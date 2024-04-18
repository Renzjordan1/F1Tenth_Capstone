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

    ##READ CSV FILE
    folder = "/home/rstole01/Documents/CSE-596/humble_ws/waypoints"
    file = folder + "/SLAM-good1.csv"

    waypoints = np.genfromtxt(file, delimiter=',')

    ##XY COORDINATES
    wp_x = waypoints[:,0]
    wp_y = waypoints[:,1]

    ##VELOCITY at point
    wp_v = waypoints[:,2]


    def __init__(self):
        super().__init__('pure_pursuit_node')
        
        ##SUBSCRIBE TO ODOM
        self.odom_sub = self.create_subscription(
            Odometry,
            '/ego_racecar/odom',
            self.pose_callback,
            10)

        #PUBLISHER FOR DRIVE
        self.drive_pub = self.create_publisher(AckermannDriveStamped, "/drive", 10)

        # Array of spline waypoints
        print(PurePursuit.waypoints)
        # tck, u = splprep([PurePursuit.wp_x, PurePursuit.wp_y], s=0)
        # self.new_points = splev(u, tck)

        ##LIST OF LISTS FOR EACH WAYPOINT VALUE
        self.new_points = [PurePursuit.wp_x, PurePursuit.wp_y, PurePursuit.wp_v]

        ##PLOT WAYPOINT PATH
        fig, ax = plt.subplots()
        ax.plot(PurePursuit.wp_x, PurePursuit.wp_y, 'ro')
        plt.show()

        ##PID AND SPEED TUNING
        ##SPEED = 2
        # self.speed = 2.0
        # self.lookahead = .9
        # self.kp = 1
        # self.kd = .4
        # self.ki = .1

        ##DYNAMIC Speed
        self.speed = 2.0
        self.lookahead = 1 
        self.min_lookahead = 0.5
        self.max_lookahead = 4.0 
        self.lookahead_ratio = 8.0
        self.kp = 1.2
        self.kd = 2.5
        self.ki = .25

        ##SPEED = 3
        # self.speed = 3.0
        # self.lookahead = 1.1
        # self.kp = 1.1
        # self.kd = 2.5
        # self.ki = .25


        ##ANGLE HISTORY
        self.prev_angle = 1000
        self.sum_angle = 0
        self.angle_change = 0


    ##CALLBACK ON ODOM
    def pose_callback(self, pose_msg):
        print("kp ",self.kp)

        #Pose and Yaw
        pose_x = pose_msg.pose.pose.position.x
        pose_y = pose_msg.pose.pose.position.y
        quaternion = pose_msg.pose.pose.orientation
        euler = tf_transformations.euler_from_quaternion([quaternion.x, quaternion.y, quaternion.z, quaternion.w])
        print("pose: " + str(pose_x) + " " + str(pose_y))

        roll = euler[0]
        pitch = euler[1]
        yaw = euler[2]


        #FIND NEXT WAYPOINT TO TRACK
        next_wp, next_angle = self.get_next_waypoint(pose_x, pose_y, yaw)


        ##GET ANGLE CHANGE AND HISTORY
        if(self.prev_angle == 1000):
            self.angle_change = 0
            self.prev_angle = next_angle
        else:
            self.angle_change = next_angle - self.prev_angle
            self.prev_angle = next_angle
            self.sum_angle += self.angle_change


        ##DETERMINE HORIZONTAL DISTANCE
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


        ##CALCULATE CURVATURE
        curvature = 2*abs(dist) / (self.lookahead**2)

        print("dist: ", dist)
        print("curve: ", curvature)


        ##DETERMINE STEERING ANGLE
        kp_val = float(self.kp * next_angle * curvature)
        kd_val = float(self.kd * self.angle_change * curvature)
        ki_val = float(self.ki * self.sum_angle * curvature)
        steering_angle = kp_val + kd_val + ki_val

        print("kp_val: ", kp_val)
        print("kd_val: ", kd_val)
        print("ki_val: ", ki_val)
        print("angle(rad): ", steering_angle)


        ##MAKE DRIVE MSG
        drive_msg = AckermannDriveStamped()

        ##LIMIT STEERING ANGLE TO 35 DEGREES
        if(steering_angle > 0.61):
            steering_angle = 0.61
        if(steering_angle < -0.61):
            steering_angle = -0.61

        drive_msg.drive.steering_angle = steering_angle


        #Find the closest point to the car, and use the velocity index for that
        closest = float('inf')
        closest_v = 0
        choice = []

        ##Loop through each point
        for i in range(len(self.new_points[0])):

            ##GET DISTANCE
            dx = self.new_points[0][i] - pose_x
            dy = self.new_points[1][i] - pose_y
            distance = math.sqrt(dx**2 + dy**2)

            #Check if closer
            if distance < closest:
                closest_v = self.new_points[2][i]
                closest = distance
                choice = [self.new_points[0][i], self.new_points[1][i], distance]

        print("choice: ", choice)


        ##DETERMINE SPEED
        self.speed = closest_v #COMMENT OUT IF USING CONSTANT SPEED
        drive_msg.drive.speed = self.speed

        print("look: ", self.lookahead)
        print("speed: ", self.speed)

        ##DYNAMIC LOOKAHEAD
        self.lookahead = min(max(self.min_lookahead, self.max_lookahead * self.speed / self.lookahead_ratio), self.max_lookahead) #COMMENT OUT IF USING CONSTANT LOOKAHEAD

        print("angle: ", steering_angle*180/3.14)
        print("yaw: ", yaw*180/3.14)

        ##PUBLISH DRIVE MSG
        self.drive_pub.publish(drive_msg)


    ##FUNCTION TO GET NEXT WAYPOINT NEAREST TO LOOKAHEAD DISTANCE
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

                #Point at lookahead
                if(dist_from_look == 0):
                    wp = [self.new_points[0][i], self.new_points[1][i], self.new_points[2][i]]
                    break

                #Point inside radius
                elif(dist_from_look > 0):
                    if(dist_from_look < closest_dist_in):
                        closest_dist_in = dist_from_look
                        wp_in = [self.new_points[0][i], self.new_points[1][i], self.new_points[2][i]]
                        relative_angle_in = relative_angle

                #Point outside radius
                else:
                    if(dist_from_look > closest_dist_out):
                        closest_dist_out = dist_from_look
                        wp_out = [self.new_points[0][i], self.new_points[1][i], self.new_points[2][i]]
                        relative_angle_out = relative_angle


        #Get Intersection of Circle and Line Interpolation
        if(wp is None):

            ##Pick point outside
            if(wp_in is None):
                wp = wp_out
                relative_angle = relative_angle_out

            ##Pick point inside
            elif(wp_out is None):
                wp = wp_in
                relative_angle = relative_angle_in

            ##Pick closest intersection
            else:

                ##Average speed
                wp_v = (wp_in[2] + wp_out[2]) / 2

                ##Get Circle intersection points at lookahead distance
                circle = Circle([curr_x, curr_y], self.lookahead)
                line = Line(wp_in[0:2], wp_out[0:2])
                point_a, point_b = circle.intersect_line(line)
                points = [point_a, point_b]
                print("\npoints: ", points)

                #Find midpoint of inside and ouside point
                midpoint = [(wp_in[0] + wp_out[0]) / 2, (wp_in[1] + wp_out[1]) / 2]

                print("midpoint: ", midpoint)

                ##Get distances from each point
                dx_a = point_a[0] - midpoint[0]
                dy_a = point_a[1] - midpoint[1]

                dist_a = math.sqrt(dx_a**2 + dy_a**2)

                dx_b = point_b[0] - midpoint[0]
                dy_b = point_b[1] - midpoint[1]

                dist_b = math.sqrt(dx_b**2 + dy_b**2)

                print("dists: ", dist_a, dist_b)

                ##Pick point a
                if(dist_a <= dist_b):
                    wp = [point_a[0], point_a[1], wp_v]
                    dx_a = point_a[0] - curr_x
                    dy_a = point_a[1] - curr_y
                    angle = math.atan2(dy_a, dx_a)
                    relative_angle = self.get_relative_angle(curr_yaw, angle)

                ##Pick point b
                else:
                    wp = [point_b[0], point_b[1], wp_v]
                    dx_b = point_b[0] - curr_x
                    dy_b = point_b[1] - curr_y
                    angle = math.atan2(dy_b, dx_b)
                    relative_angle = self.get_relative_angle(curr_yaw, angle)

        
        print("wp_in: ", wp_in)
        print("wp_out: ", wp_out)
        print("wp: ", wp)
        print("relative_angle: ", relative_angle*180/3.14)
        print("pose: ", curr_x, curr_y)
        return wp, relative_angle



    ##LIMIT ANGLE to -2pi to 2pi
    def angle_check(self,angle):
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle
    
    ##GET RELATIVE ANGLE 
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