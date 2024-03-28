#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

import numpy as np
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive
from nav_msgs.msg import Odometry

import tf_transformations
import geometry_msgs


from scipy.interpolate import splprep, splev
import matplotlib.pyplot as plt
import math
from skspatial.objects import Circle
from skspatial.objects import Line

# TODO CHECK: include needed ROS msg type headers and libraries

class PurePursuit(Node):
    """ 
    Implement Pure Pursuit on the car
    This is just a template, you are free to implement your own node!
    """

    folder = "/home/rstole01/Documents/CSE-596/humble_ws/waypoints"
    file = folder + "/see.csv"

    waypoints = np.genfromtxt(file, delimiter=',')
    wp_x = waypoints[:,0]
    wp_y = waypoints[:,1]

    def __init__(self):
        super().__init__('pure_pursuit_node')
        # TODO: create ROS subscribers and publishers
        self.odom_sub = self.create_subscription(
            Odometry,
            '/ego_racecar/odom',
            self.pose_callback,
            10)
        self.drive_pub = self.create_publisher(AckermannDriveStamped, "/drive", 10)

        # Array of spline waypoints
        # print(PurePursuit.waypoints)
        # tck, u = splprep([PurePursuit.wp_x, PurePursuit.wp_y], s=0)
        # self.new_points = splev(u, tck)

        self.new_points = [PurePursuit.wp_x, PurePursuit.wp_y]

        fig, ax = plt.subplots()

        ax.plot(PurePursuit.wp_x, PurePursuit.wp_y, 'ro')

        plt.show()
        self.speed = 4.0
        self.lookahead = 1.5
        self.kp = .5

        # print(self.new_points[0])
        # print(self.new_points[1])


    def pose_callback(self, pose_msg):

        # std_msgs/msg/Header header
        #     string child_frame_id

        # geometry_msgs/msg/PoseWithCovariance pose
        #     geometry_msgs/msg/Pose pose
        #         geometry_msgs/msg/Point position
        #             double x
        #             double y
        #             double z
        #         geometry_msgs/msg/Quaternion orientation
        #             double x=0.0
        #             double y=0.0
        #             double z=0.0
        #             double w=1.0
        #     double[36] covariance
        # geometry_msgs/msg/TwistWithCovariance twist
        #     geometry_msgs/msg/Twist twist
        #         geometry_msgs/msg/Vector3 linear
        #             double x
        #             double y
        #             double z
        #         geometry_msgs/msg/Vector3 angular
        #             double x
        #             double y
        #             double z
        #     double[36] covariance

        #Pose and Yaw
        pose_x = pose_msg.pose.pose.position.x
        pose_y = pose_msg.pose.pose.position.y
        quaternion = pose_msg.pose.pose.orientation
        euler = tf_transformations.euler_from_quaternion([quaternion.x, quaternion.y, quaternion.z, quaternion.w])

        roll = euler[0]
        pitch = euler[1]
        yaw = euler[2]

        # TODO: find the current waypoint to track using methods mentioned in lecture
        next_wp, next_angle = self.get_next_waypoint(pose_x, pose_y, yaw)

        # TODO: transform goal point to vehicle frame of reference


        # TODO: calculate curvature/steering angle
        # y_dist = (next_wp[1] - pose_y)
        # x_dist = (next_wp[0] - pose_x)

        # if(x_dist >= 0 and abs(x_dist) >= abs(y_dist)):
        #     print("up")
        #     curvature = 2*(y_dist) / (self.lookahead**2)
        # elif(x_dist < 0 and abs(x_dist) >= abs(y_dist)):
        #     print("down")
        #     curvature = -2*(y_dist) / (self.lookahead**2)
        # elif(y_dist >= 0 and abs(y_dist) >= abs(x_dist)):
        #     print("left")
        #     curvature = -2*(x_dist) / (self.lookahead**2)
        # elif(y_dist < 0 and abs(y_dist) >= abs(x_dist)):
        #     print("right")
        #     curvature = 2*(x_dist) / (self.lookahead**2)

        dist = 0
        yaw_deg = yaw*180/3.14
        if(yaw_deg >= 0 and yaw_deg < 60):
            dist = (next_wp[1] - pose_y)
        elif(yaw_deg >= 60 and yaw_deg < 120):
            dist = (next_wp[0] - pose_x)
        elif(yaw_deg >= 120 or yaw_deg < -120):
            dist = (next_wp[1] - pose_y)
        elif(yaw_deg >= -120 and yaw_deg < -60):
            dist = (next_wp[0] - pose_x)
        elif(yaw_deg >= -60 and yaw_deg < 0):
            dist = (next_wp[1] - pose_y)

        curvature = 2*abs(dist) / (self.lookahead**2)

        print("dist: ", dist)
        print("curve: ", curvature)
        # if(next_angle >= 0):
        #     steering_angle = float(self.kp * curvature)
        # else: 
        #     steering_angle = -1 * float(self.kp * curvature)

        steering_angle = float(self.kp * next_angle * curvature)
        print("angle(rad): ", steering_angle)

        # TODO: publish drive message, don't forget to limit the steering angle.
        drive_msg = AckermannDriveStamped()
        # std_msgs/Header header
        # ackermann_msgs/AckermannDrive drive
        #     float32 steering_angle
        #     float32 steering_angle_velocity
        #     float32 speed
        #     float32 acceleration
        #     float32 jerk

        drive_msg.drive.steering_angle = steering_angle
        drive_msg.drive.speed = self.speed

        print("angle: ", steering_angle*180/3.14)
        print("yaw: ", yaw*180/3.14)
        self.drive_pub.publish(drive_msg)
    
    def get_next_waypoint(self, curr_x, curr_y, curr_yaw):
        wp = None
        wp_in = None
        wp_out = None
        closest_dist_in = float('inf')
        closest_dist_out = -1 * float('inf')

        # pick closest waypoint in direction of car
    
        search_angle = 1.5 # 90 degrees
        relative_angle = 0
        relative_angle_in = 0
        relative_angle_out = 0


        ##Loop through each point
        for i in range(len(self.new_points[0])):


            ##Find relative angle
            dx = self.new_points[0][i] - curr_x
            dy = self.new_points[1][i] - curr_y
            angle = math.atan2(dy, dx)
            relative_angle = self.get_relative_angle(curr_yaw, angle)
            distance = math.sqrt(dx**2 + dy**2)
            dist_from_look = self.lookahead - distance

            #Check if angle is towards direction
            if abs(relative_angle) < search_angle:

                # print(self.new_points[0][i], self.new_points[1][i])

                #Point at lookahead
                if(dist_from_look == 0):
                    wp = [self.new_points[0][i], self.new_points[1][i]]
                    break

                #Point inside radius
                elif(dist_from_look > 0):
                    if(dist_from_look < closest_dist_in):
                        closest_dist_in = dist_from_look
                        wp_in = [self.new_points[0][i], self.new_points[1][i]]
                        relative_angle_in = relative_angle

                #Point outside radius
                else:
                    if(dist_from_look > closest_dist_out):
                        closest_dist_out = dist_from_look
                        wp_out = [self.new_points[0][i], self.new_points[1][i]]
                        relative_angle_out = relative_angle


        #Get Intersection of Circle and Line Interpolation
        if(wp is None):
            if(wp_in is None):
                wp = wp_out
                relative_angle = relative_angle_out
            elif(wp_out is None):
                wp = wp_in
                relative_angle = relative_angle_in
            else:
                circle = Circle([curr_x, curr_y], self.lookahead)
                line = Line(wp_in, wp_out)
                point_a, point_b = circle.intersect_line(line)

                points = [point_a, point_b]
                print("\npoints: ", points)

                midpoint = [(wp_in[0] + wp_out[0]) / 2, (wp_in[1] + wp_out[1]) / 2]

                print("midpoint: ", midpoint)

                dx_a = point_a[0] - midpoint[0]
                dy_a = point_a[1] - midpoint[1]

                dist_a = math.sqrt(dx_a**2 + dy_a**2)

                dx_b = point_b[0] - midpoint[0]
                dy_b = point_b[1] - midpoint[1]

                dist_b = math.sqrt(dx_b**2 + dy_b**2)

                print("dists: ", dist_a, dist_b)

                if(dist_a <= dist_b):
                    wp = [point_a[0], point_a[1]]
                    dx_a = point_a[0] - curr_x
                    dy_a = point_a[1] - curr_y
                    angle = math.atan2(dy_a, dx_a)
                    relative_angle = self.get_relative_angle(curr_yaw, angle)

                else:
                    wp = [point_b[0], point_b[1]]
                    dx_b = point_b[0] - curr_x
                    dy_b = point_b[1] - curr_y
                    angle = math.atan2(dy_b, dx_b)
                    relative_angle = self.get_relative_angle(curr_yaw, angle)

                



                # for point in points:
                #     ##Find relative angle
                #     dx = point[0] - curr_x
                #     dy = point[1] - curr_y
                #     angle = math.atan2(dy, dx)
                #     relative_angle = self.get_relative_angle(curr_yaw, angle)
                #     print("relative: ", relative_angle)

                #     if abs(relative_angle) < search_angle:
                #         wp = [point[0], point[1]]
                #         search_angle = abs(relative_angle)

                # print("interp: ", wp)
        
        # print(wp, wp_in, wp_out)
        print("wp_in: ", wp_in)
        print("wp_out: ", wp_out)
        print("wp: ", wp)
        print("relative_angle: ", relative_angle*180/3.14)
        print("pose: ", curr_x, curr_y)
        return wp, relative_angle




    def angle_check(self,angle):
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle
    
    def get_relative_angle(self, car_yaw, angle):
        relative_angle = angle - car_yaw
        relative_angle = self.angle_check(relative_angle)
        return relative_angle



def main(args=None):
    rclpy.init(args=args)
    print("PurePursuit Initialized")
    pure_pursuit_node = PurePursuit()
    # print(pure_pursuit_node)
    rclpy.spin(pure_pursuit_node)

    pure_pursuit_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()