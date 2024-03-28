import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, Twist, TransformStamped, Transform
from ackermann_msgs.msg import AckermannDriveStamped
from std_msgs.msg import Float32, Int32, Bool
from tf2_ros import TransformBroadcaster

import gym
import numpy as np
from transforms3d import euler


class GymBridge(Node):
    def __init__(self):
        super().__init__("gym_bridge")

        self.declare_parameter("ego_namespace", rclpy.Parameter.Type.STRING)
        self.declare_parameter("ego_odom_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("ego_scan_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("ego_drive_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("opp_namespace", rclpy.Parameter.Type.STRING)
        self.declare_parameter("opp_odom_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("opp_scan_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("opp_drive_topic", rclpy.Parameter.Type.STRING)
        self.declare_parameter("sim_hz", rclpy.Parameter.Type.INTEGER)
        self.declare_parameter("tf_hz", rclpy.Parameter.Type.INTEGER)
        self.declare_parameter("scan_distance_to_base_link", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("scan_fov", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("scan_beams", rclpy.Parameter.Type.INTEGER)
        self.declare_parameter("scan_hz", rclpy.Parameter.Type.INTEGER)
        self.declare_parameter("map_path", rclpy.Parameter.Type.STRING)
        self.declare_parameter("map_img_ext", rclpy.Parameter.Type.STRING)
        self.declare_parameter("num_agent", rclpy.Parameter.Type.INTEGER)
        self.declare_parameter("sx", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("sy", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("stheta", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("sx1", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("sy1", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("stheta1", rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter("kb_teleop", rclpy.Parameter.Type.BOOL)

        # echo all parameters
        # parameters = self.get_parameters_by_prefix("")
        # for param in parameters:
        #     parameter = self.get_parameter(param)
        #     self.get_logger().info("{}: {}".format(parameter.name, parameter.value))

        # check num_agents
        num_agents = self.get_parameter("num_agent").value
        if num_agents < 1 or num_agents > 2:
            raise ValueError("num_agents should be either 1 or 2.")
        elif type(num_agents) != int:
            raise ValueError("num_agents should be an int.")

        collision = False

        # env backend
        self.env = gym.make(
            "f110_gym:f110-v0",
            map=self.get_parameter("map_path").value,
            map_ext=self.get_parameter("map_img_ext").value,
            num_agents=num_agents,
            timestep= 0.01,  # simulation accuracy, default: 0.01
        )

        # timer logging
        self.get_logger().info("sim_hz: %d" % self.get_parameter("sim_hz").value)
        self.get_logger().info("tf_hz: %d" % self.get_parameter("tf_hz").value)
        self.get_logger().info("scan_hz: %d" % self.get_parameter("scan_hz").value)

        sx = self.get_parameter("sx").value
        sy = self.get_parameter("sy").value
        stheta = self.get_parameter("stheta").value
        self.ego_pose = [sx, sy, stheta]
        self.ego_speed = [0.0, 0.0, 0.0]
        self.ego_requested_speed = 0.0
        self.ego_steer = 0.0
        self.ego_collision = collision
        ego_scan_topic = self.get_parameter("ego_scan_topic").value
        ego_drive_topic = self.get_parameter("ego_drive_topic").value
        scan_fov = self.get_parameter("scan_fov").value
        scan_beams = self.get_parameter("scan_beams").value
        self.angle_min = -scan_fov / 2.0
        self.angle_max = scan_fov / 2.0
        self.angle_inc = scan_fov / scan_beams
        self.get_logger().info("angle_min: %f" % self.angle_min)
        self.get_logger().info("angle_max: %f" % self.angle_max)
        self.get_logger().info("angle_inc: %f" % self.angle_inc)
        self.get_logger().info("number of beams: %f" % scan_beams)
        self.get_logger().info("number of angle increments: %f" % (scan_fov / self.angle_inc))

        self.ego_namespace = self.get_parameter("ego_namespace").value
        ego_odom_topic = self.get_parameter("ego_odom_topic").value
        self.scan_distance_to_base_link = self.get_parameter(
            "scan_distance_to_base_link"
        ).value

        if num_agents == 2:
            self.has_opp = True
            self.opp_namespace = self.get_parameter("opp_namespace").value
            sx1 = self.get_parameter("sx1").value
            sy1 = self.get_parameter("sy1").value
            stheta1 = self.get_parameter("stheta1").value
            self.opp_pose = [sx1, sy1, stheta1]
            self.opp_speed = [0.0, 0.0, 0.0]
            self.opp_requested_speed = 0.0
            self.opp_steer = 0.0
            self.opp_collision = collision
            self.obs, _, self.done, _ = self.env.reset(
                np.array([[sx, sy, stheta], [sx1, sy1, stheta1]])
            )
            self.ego_scan = list(self.obs["scans"][0])
            self.opp_scan = list(self.obs["scans"][1])

            opp_scan_topic = self.opp_namespace + "/" + self.get_parameter("opp_scan_topic").value
            opp_odom_topic = self.opp_namespace + "/" + self.get_parameter("opp_odom_topic").value
            opp_drive_topic = self.opp_namespace + "/" + self.get_parameter("opp_drive_topic").value

        else:
            self.has_opp = False
            self.obs, _, self.done, _ = self.env.reset(np.array([[sx, sy, stheta]]))
            self.ego_scan = list(self.obs["scans"][0])


        if self.get_parameter("kb_teleop").value:
            self.teleop_sub = self.create_subscription(
                Twist, "/cmd_vel", self.teleop_callback, 10
            )

        # sim physical step timer
        self.sim_timer = self.create_timer(1.0 / self.get_parameter("sim_hz").value, self.sim_timer_callback) # originally 0.01
        self.get_logger().info('sim update interval: %f' % (1.0 / self.get_parameter("sim_hz").value) );

        # transform publishing timer
        self.tf_timer = self.create_timer(1.0 / self.get_parameter("tf_hz").value, self.tf_timer_callback) # originally 0.004
        self.get_logger().info('tf update interval: %f' % (1.0 / self.get_parameter("tf_hz").value) );

        # lidar scan timer
        self.scan_timer = self.create_timer(1.0 / self.get_parameter("scan_hz").value, self.scan_timer_callback)
        self.get_logger().info('scan update interval: %f' % (1.0 / self.get_parameter("scan_hz").value) );

        # transform broadcaster
        self.br = TransformBroadcaster(self)

        # publishers
        self.ego_scan_pub = self.create_publisher(LaserScan, ego_scan_topic, 10)
        self.ego_odom_pub = self.create_publisher(Odometry, ego_odom_topic, 10)
        self.ego_drive_published = False
        self.ego_collision_pub = self.create_publisher(Bool, "/ego_collision", 10)

        if num_agents == 2:
            self.opp_scan_pub = self.create_publisher(LaserScan, opp_scan_topic, 10)
            self.opp_odom_pub = self.create_publisher(Odometry, opp_odom_topic, 10)
            self.opp_drive_published = False
            self.opp_collision_pub = self.create_publisher(Bool, "/opp_collision", 10)

        # lap time info
        self.ego_lap_time_pub = self.create_publisher(Float32, "/ego_lap_time", 10)
        self.ego_lap_count_pub = self.create_publisher(Int32, "/ego_lap_count", 10)
        if num_agents == 2:
            self.opp_lap_time_pub = self.create_publisher(Float32, "/opp_lap_time", 10)
            self.opp_lap_count_pub = self.create_publisher(Int32, "/opp_lap_count", 10)

        # subscribers
        self.ego_drive_sub = self.create_subscription(
            AckermannDriveStamped, ego_drive_topic, self.drive_callback, 10
        )
        self.ego_reset_sub = self.create_subscription(
            PoseWithCovarianceStamped, "/initialpose", self.ego_reset_callback, 10
        )

        if num_agents == 2:
            self.opp_drive_sub = self.create_subscription(
                AckermannDriveStamped, opp_drive_topic, self.opp_drive_callback, 10
            )
            self.opp_reset_sub = self.create_subscription(
                PoseStamped, "/goal_pose", self.opp_reset_callback, 10
            )

    def reset_lap(self, x, y, car_idx=0):
        self.env.start_xs[car_idx] = x
        self.env.start_ys[car_idx] = y
        self.env.lap_times[car_idx] = 0.0
        self.env.lap_counts[car_idx] = 0.0

    def teleop_callback(self, twist_msg):
        self.ego_requested_speed = twist_msg.linear.x
        self.ego_steer = twist_msg.angular.z

    def drive_callback(self, drive_msg):
        self.ego_requested_speed = drive_msg.drive.speed
        self.ego_steer = drive_msg.drive.steering_angle
        self.ego_drive_published = True

    def opp_drive_callback(self, drive_msg):
        self.opp_requested_speed = drive_msg.drive.speed
        self.opp_steer = drive_msg.drive.steering_angle
        self.opp_drive_published = True

    def ego_reset_callback(self, pose_msg):
        rx = pose_msg.pose.pose.position.x
        ry = pose_msg.pose.pose.position.y
        rqx = pose_msg.pose.pose.orientation.x
        rqy = pose_msg.pose.pose.orientation.y
        rqz = pose_msg.pose.pose.orientation.z
        rqw = pose_msg.pose.pose.orientation.w
        _, _, rtheta = euler.quat2euler([rqw, rqx, rqy, rqz], axes="sxyz")

        self.reset_lap(rx, ry)

        if self.has_opp:
            opp_pose = [
                self.obs["poses_x"][1],
                self.obs["poses_y"][1],
                self.obs["poses_theta"][1],
            ]
            self.reset_lap(opp_pose[0], opp_pose[1], car_idx=1)
            self.obs, _, self.done, _ = self.env.reset(
                np.array([[rx, ry, rtheta], opp_pose])
            )
        else:
            self.obs, _, self.done, _ = self.env.reset(np.array([[rx, ry, rtheta]]))

    def opp_reset_callback(self, pose_msg):
        if self.has_opp:
            rx = pose_msg.pose.position.x
            ry = pose_msg.pose.position.y
            rqx = pose_msg.pose.orientation.x
            rqy = pose_msg.pose.orientation.y
            rqz = pose_msg.pose.orientation.z
            rqw = pose_msg.pose.orientation.w
            _, _, rtheta = euler.quat2euler([rqw, rqx, rqy, rqz], axes="sxyz")
            self.obs, _, self.done, _ = self.env.reset(
                np.array([list(self.ego_pose), [rx, ry, rtheta]])
            )

    def sim_timer_callback(self):
        # experimental; will not work because publishers will need to publish faster than the sim timer
        # if not self.ego_drive_published:
        #     self.ego_requested_speed = 0.0
        #     self.ego_steer = 0.0

        if not self.has_opp:
            self.obs, _, self.done, _ = self.env.step(
                np.array([[self.ego_steer, self.ego_requested_speed]])
            )
            self.ego_drive_published = False

        elif self.has_opp:
            # if not self.opp_drive_published:
            #     self.opp_requested_speed = 0.0
            #     self.opp_steer = 0.0

            self.obs, _, self.done, _ = self.env.step(
                np.array(
                    [
                        [self.ego_steer, self.ego_requested_speed],
                        [self.opp_steer, self.opp_requested_speed],
                    ]
                )
            )
            self.ego_drive_published = False
            self.opp_drive_published = False

        self.update_lap()

        self._update_sim_state()

    def update_lap(self):
        # publish lap time and count
        lap_time_msg = Float32()
        lap_time_msg.data = self.env.lap_times[0]
        self.ego_lap_time_pub.publish(lap_time_msg)

        lap_count_msg = Int32()
        lap_count_msg.data = int(self.env.lap_counts[0])
        self.ego_lap_count_pub.publish(lap_count_msg)

        if self.has_opp:
            opp_lap_time_msg = Float32()
            opp_lap_time_msg.data = self.env.lap_times[1]
            self.opp_lap_time_pub.publish(opp_lap_time_msg)

            opp_lap_count_msg = Int32()
            opp_lap_count_msg.data = int(self.env.lap_counts[1])
            self.opp_lap_count_pub.publish(opp_lap_count_msg)


    def tf_timer_callback(self):
        ts = self.get_clock().now().to_msg()

        # pub tf
        self._publish_odom(ts)
        self._publish_collision(ts)
        self._publish_transforms(ts)
        self._publish_wheel_transforms(ts)

    def scan_timer_callback(self):
        ts = self.get_clock().now().to_msg()

        # pub scans
        scan = LaserScan()
        scan.header.stamp = ts
        scan.header.frame_id = self.ego_namespace + "/laser"
        scan.angle_min = self.angle_min
        scan.angle_max = self.angle_max - self.angle_inc
        scan.angle_increment = self.angle_inc
        scan.range_min = 0.0
        scan.range_max = 50.0
        scan.ranges = self.ego_scan
        self.ego_scan_pub.publish(scan)

        if self.has_opp:
            opp_scan = LaserScan()
            opp_scan.header.stamp = ts
            opp_scan.header.frame_id = self.opp_namespace + "/laser"
            opp_scan.angle_min = self.angle_min
            opp_scan.angle_max = self.angle_max - self.angle_inc
            opp_scan.angle_increment = self.angle_inc
            opp_scan.range_min = 0.0
            opp_scan.range_max = 50.0
            opp_scan.ranges = self.opp_scan
            self.opp_scan_pub.publish(opp_scan)

        self._publish_laser_transforms(ts)

    def _update_sim_state(self):
        self.ego_scan = list(self.obs["scans"][0])
        if self.has_opp:
            self.opp_scan = list(self.obs["scans"][1])
            self.opp_pose[0] = self.obs["poses_x"][1]
            self.opp_pose[1] = self.obs["poses_y"][1]
            self.opp_pose[2] = self.obs["poses_theta"][1]
            self.opp_speed[0] = self.obs["linear_vels_x"][1]
            self.opp_speed[1] = self.obs["linear_vels_y"][1]
            self.opp_speed[2] = self.obs["ang_vels_z"][1]
            self.opp_collision = self.obs["collisions"][1]

        self.ego_pose[0] = self.obs["poses_x"][0]
        self.ego_pose[1] = self.obs["poses_y"][0]
        self.ego_pose[2] = self.obs["poses_theta"][0]
        self.ego_speed[0] = self.obs["linear_vels_x"][0]
        self.ego_speed[1] = self.obs["linear_vels_y"][0]
        self.ego_speed[2] = self.obs["ang_vels_z"][0]
        self.ego_collision = self.obs["collisions"][0]

    def _publish_odom(self, ts):
        ego_odom = Odometry()
        ego_odom.header.stamp = ts
        ego_odom.header.frame_id = "map"
        # ego_odom.child_frame_id = self.ego_namespace + "/base_link"
        ego_odom.child_frame_id = self.ego_namespace + "/odom"
        ego_odom.pose.pose.position.x = self.ego_pose[0]
        ego_odom.pose.pose.position.y = self.ego_pose[1]
        ego_quat = euler.euler2quat(0.0, 0.0, self.ego_pose[2], axes="sxyz")
        ego_odom.pose.pose.orientation.x = ego_quat[1]
        ego_odom.pose.pose.orientation.y = ego_quat[2]
        ego_odom.pose.pose.orientation.z = ego_quat[3]
        ego_odom.pose.pose.orientation.w = ego_quat[0]
        ego_odom.twist.twist.linear.x = self.ego_speed[0]
        ego_odom.twist.twist.linear.y = self.ego_speed[1]
        ego_odom.twist.twist.angular.z = self.ego_speed[2]
        self.ego_odom_pub.publish(ego_odom)

        if self.has_opp:
            opp_odom = Odometry()
            opp_odom.header.stamp = ts
            opp_odom.header.frame_id = "map"
            # opp_odom.child_frame_id = self.opp_namespace + "/base_link"
            opp_odom.child_frame_id = self.opp_namespace + "/odom"
            opp_odom.pose.pose.position.x = self.opp_pose[0]
            opp_odom.pose.pose.position.y = self.opp_pose[1]
            opp_quat = euler.euler2quat(0.0, 0.0, self.opp_pose[2], axes="sxyz")
            opp_odom.pose.pose.orientation.x = opp_quat[1]
            opp_odom.pose.pose.orientation.y = opp_quat[2]
            opp_odom.pose.pose.orientation.z = opp_quat[3]
            opp_odom.pose.pose.orientation.w = opp_quat[0]
            opp_odom.twist.twist.linear.x = self.opp_speed[0]
            opp_odom.twist.twist.linear.y = self.opp_speed[1]
            opp_odom.twist.twist.angular.z = self.opp_speed[2]
            self.opp_odom_pub.publish(opp_odom)

    def _publish_transforms(self, ts):

        # map to odom transform (same frame)
        map_t = TransformStamped()
        map_t.header.stamp = ts
        map_t.header.frame_id = "map"
        map_t.child_frame_id = self.ego_namespace + "/odom"
        map_t.transform.translation.x = 0.0
        map_t.transform.translation.y = 0.0
        map_t.transform.translation.z = 0.0
        map_t.transform.rotation.x = 0.0
        map_t.transform.rotation.y = 0.0
        map_t.transform.rotation.z = 0.0
        map_t.transform.rotation.w = 1.0
        self.br.sendTransform(map_t)

        if self.has_opp:
            opp_map_t = TransformStamped()
            opp_map_t.header.stamp = ts
            opp_map_t.header.frame_id = "map"
            opp_map_t.child_frame_id = self.opp_namespace + "/odom"
            opp_map_t.transform.translation.x = 0.0
            opp_map_t.transform.translation.y = 0.0
            opp_map_t.transform.translation.z = 0.0
            opp_map_t.transform.rotation.x = 0.0
            opp_map_t.transform.rotation.y = 0.0
            opp_map_t.transform.rotation.z = 0.0
            opp_map_t.transform.rotation.w = 1.0
            self.br.sendTransform(opp_map_t)

        ego_t = Transform()
        ego_t.translation.x = self.ego_pose[0]
        ego_t.translation.y = self.ego_pose[1]
        ego_t.translation.z = 0.0
        ego_quat = euler.euler2quat(0.0, 0.0, self.ego_pose[2], axes="sxyz")
        ego_t.rotation.x = ego_quat[1]
        ego_t.rotation.y = ego_quat[2]
        ego_t.rotation.z = ego_quat[3]
        ego_t.rotation.w = ego_quat[0]

        ego_ts = TransformStamped()
        ego_ts.transform = ego_t
        ego_ts.header.stamp = ts
        # ego_ts.header.frame_id = "map"
        ego_ts.header.frame_id = self.ego_namespace + "/odom"
        ego_ts.child_frame_id = self.ego_namespace + "/base_link"
        self.br.sendTransform(ego_ts)

        if self.has_opp:
            opp_t = Transform()
            opp_t.translation.x = self.opp_pose[0]
            opp_t.translation.y = self.opp_pose[1]
            opp_t.translation.z = 0.0
            opp_quat = euler.euler2quat(0.0, 0.0, self.opp_pose[2], axes="sxyz")
            opp_t.rotation.x = opp_quat[1]
            opp_t.rotation.y = opp_quat[2]
            opp_t.rotation.z = opp_quat[3]
            opp_t.rotation.w = opp_quat[0]

            opp_ts = TransformStamped()
            opp_ts.transform = opp_t
            opp_ts.header.stamp = ts
            # opp_ts.header.frame_id = "map"
            opp_ts.header.frame_id = self.opp_namespace + "/odom"
            opp_ts.child_frame_id = self.opp_namespace + "/base_link"
            self.br.sendTransform(opp_ts)

    def _publish_wheel_transforms(self, ts):
        ego_wheel_ts = TransformStamped()
        ego_wheel_quat = euler.euler2quat(0.0, 0.0, self.ego_steer, axes="sxyz")
        ego_wheel_ts.transform.rotation.x = ego_wheel_quat[1]
        ego_wheel_ts.transform.rotation.y = ego_wheel_quat[2]
        ego_wheel_ts.transform.rotation.z = ego_wheel_quat[3]
        ego_wheel_ts.transform.rotation.w = ego_wheel_quat[0]
        ego_wheel_ts.header.stamp = ts
        ego_wheel_ts.header.frame_id = self.ego_namespace + "/front_left_hinge"
        ego_wheel_ts.child_frame_id = self.ego_namespace + "/front_left_wheel"
        self.br.sendTransform(ego_wheel_ts)
        ego_wheel_ts.header.frame_id = self.ego_namespace + "/front_right_hinge"
        ego_wheel_ts.child_frame_id = self.ego_namespace + "/front_right_wheel"
        self.br.sendTransform(ego_wheel_ts)

        if self.has_opp:
            opp_wheel_ts = TransformStamped()
            opp_wheel_quat = euler.euler2quat(0.0, 0.0, self.opp_steer, axes="sxyz")
            opp_wheel_ts.transform.rotation.x = opp_wheel_quat[1]
            opp_wheel_ts.transform.rotation.y = opp_wheel_quat[2]
            opp_wheel_ts.transform.rotation.z = opp_wheel_quat[3]
            opp_wheel_ts.transform.rotation.w = opp_wheel_quat[0]
            opp_wheel_ts.header.stamp = ts
            opp_wheel_ts.header.frame_id = self.opp_namespace + "/front_left_hinge"
            opp_wheel_ts.child_frame_id = self.opp_namespace + "/front_left_wheel"
            self.br.sendTransform(opp_wheel_ts)
            opp_wheel_ts.header.frame_id = self.opp_namespace + "/front_right_hinge"
            opp_wheel_ts.child_frame_id = self.opp_namespace + "/front_right_wheel"
            self.br.sendTransform(opp_wheel_ts)

    def _publish_laser_transforms(self, ts):
        ego_scan_ts = TransformStamped()
        ego_scan_ts.transform.translation.x = self.scan_distance_to_base_link
        # ego_scan_ts.transform.translation.z = 0.04 + 0.1 + 0.025
        ego_scan_ts.transform.rotation.w = 1.0
        ego_scan_ts.header.stamp = ts
        ego_scan_ts.header.frame_id = self.ego_namespace + "/base_link"
        ego_scan_ts.child_frame_id = self.ego_namespace + "/laser"
        self.br.sendTransform(ego_scan_ts)

        if self.has_opp:
            opp_scan_ts = TransformStamped()
            opp_scan_ts.transform.translation.x = self.scan_distance_to_base_link
            opp_scan_ts.transform.rotation.w = 1.0
            opp_scan_ts.header.stamp = ts
            opp_scan_ts.header.frame_id = self.opp_namespace + "/base_link"
            opp_scan_ts.child_frame_id = self.opp_namespace + "/laser"
            self.br.sendTransform(opp_scan_ts)

    def _publish_collision(self, ts):
        ego_collision_msg = Bool()
        ego_collision_msg.data = bool(self.ego_collision)
        self.ego_collision_pub.publish(ego_collision_msg)

        if self.has_opp:
            opp_collision_msg = Bool()
            opp_collision_msg.data = bool(self.opp_collision)
            self.opp_collision_pub.publish(opp_collision_msg)


def main(args=None):
    rclpy.init(args=args)
    gym_bridge = GymBridge()
    rclpy.spin(gym_bridge)


if __name__ == "__main__":
    main()
