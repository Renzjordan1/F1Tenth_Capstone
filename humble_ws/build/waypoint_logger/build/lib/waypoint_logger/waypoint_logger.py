#!/usr/bin/env python
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

import numpy as np
import atexit
import tf_transformations
from os.path import expanduser
from time import gmtime, strftime
from numpy import linalg as LA
from tf_transformations import euler_from_quaternion
from nav_msgs.msg import Odometry

home = expanduser('~')
file = open(strftime(home+'/Documents/CSE-596/humble_ws/waypoints/wp-%Y-%m-%d-%H-%M-%S',gmtime())+'.csv', 'w')



class WaypointSubscriber(Node):

    def __init__(self):
        super().__init__('waypoint_subscriber')
        self.subscription = self.create_subscription(
            Odometry,
            'ego_racecar/odom',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, data):
        # self.get_logger().info('I heard: "%s"', data)
        
        quaternion = np.array([data.pose.pose.orientation.x, 
                           data.pose.pose.orientation.y, 
                           data.pose.pose.orientation.z, 
                           data.pose.pose.orientation.w])

        euler = tf_transformations.euler_from_quaternion(quaternion)
        speed = LA.norm(np.array([data.twist.twist.linear.x, 
                                data.twist.twist.linear.y, 
                                data.twist.twist.linear.z]),2)

        if (data.twist.twist.linear.x > 0.):
            print(data.twist.twist.linear.x)

        file.write('%f, %f, %f, %f\n' % (data.pose.pose.position.x,
                                        data.pose.pose.position.y,
                                        euler[2],
                                        speed))

def shutdown():
    file.close()
    print('Goodbye')
    
def main(args=None):
    rclpy.init(args=args)

    waypoint_logger = WaypointSubscriber()

    rclpy.spin(waypoint_logger)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    file.close()
    waypoint_logger.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    # atexit.register(shutdown)
    # print('Saving waypoints...')
    main()