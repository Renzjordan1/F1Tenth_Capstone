// #include <functional>
// #include <memory>
// #include <chrono>
// #include <string>
#include <algorithm>


#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
#include "std_msgs/msg/bool.hpp"

#include "geometry_msgs/msg/pose_with_covariance.hpp"
#include "geometry_msgs/msg/twist_with_covariance.hpp"

// using namespace std::chrono_literals;
using std::placeholders::_1;


// TODO: include ROS msg type headers and libraries

class Safety : public rclcpp::Node
{
    // The class that handles emergency braking
    private:
        double speed;

        double vx;


        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub;
        rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr brake_pub;
        // rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr bool_pub;

        // int findAngleIndex(float angle_min, float angle_max, float angle_increment, float angle){

        //     //Angle to Radians
        //     double pi = 2*acos(0.0);
        //     angle = angle * pi / 180;

        //     int increments = (angle - angle_min) / angle_increment;

        //     return increments;

        // }

        void brake(){
            //Publish AckermannDriveStamped
            auto ack_msg = ackermann_msgs::msg::AckermannDriveStamped();
            // std_msgs/Header header
            // ackermann_msgs/AckermannDrive drive
            //     float32 steering_angle
            //     float32 steering_angle_velocity
            //     float32 speed
            //     float32 acceleration
            //     float32 jerk

            ack_msg.drive.speed = 0.0;
            brake_pub->publish(ack_msg);
        }
        

    // TODO: create ROS subscribers and publishers
    public:
        Safety() : Node("safety_node") {
            // speed = 0.0;

            // Scan Subscriber
            scan_sub = this->create_subscription<sensor_msgs::msg::LaserScan>(
                "/scan", 10, std::bind(&Safety::scan_callback, this, _1));

            //Odom Subscriber
            odom_sub = this->create_subscription<nav_msgs::msg::Odometry>(
                "/ego_racecar/odom", 10, std::bind(&Safety::odom_callback, this, _1));

            //Brake publisher
            brake_pub = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("/drive", 10);

            //Brake Bool publisher
            // bool_pub = this->create_publisher<std_msgs::msg::Bool>("/brake_bool", 10);

            /*
            One publisher should publish to the /brake topic with an
            ackermann_msgs/AckermannDriveStamped brake message.

            One publisher should publish to the /brake_bool topic with a
            std_msgs/Bool message.

            You should also subscribe to the /scan topic to get the
            sensor_msgs/LaserScan messages and the /odom topic to get
            the nav_msgs/Odometry messages

            The subscribers should use the provided odom_callback and 
            scan_callback as callback methods

            NOTE that the x component of the linear velocity in odom is the speed
            */

            // TODO: create ROS subscribers and publishers
            
        }
        void odom_callback(const nav_msgs::msg::Odometry::ConstSharedPtr &odom_msg) {
            // TODO: update current speed
            // speed = 0.0;


            // std_msgs/msg/Header header
            // string child_frame_id

            // geometry_msgs/msg/PoseWithCovariance pose
                // geometry_msgs/msg/Pose pose
                    // geometry_msgs/msg/Point position
                        // double x
                        // double y
                        // double z
                    // geometry_msgs/msg/Quaternion orientation
                        // double x=0.0
                        // double y=0.0
                        // double z=0.0
                        // double w=1.0
                // double[36] covariance

            // geometry_msgs/msg/TwistWithCovariance twist
                // geometry_msgs/msg/Twist twist
                    // geometry_msgs/msg/Vector3 linear
                        // double x
                        // double y
                        // double z
                    // geometry_msgs/msg/Vector3 angular
                        // double x
                        // double y
                        // double z
                // double[36] covariance


            this->vx = odom_msg->twist.twist.linear.x;


            // RCLCPP_INFO(this->get_logger(), 
            // "Forward speed: %lf,\n", 
            // this->vx);



        }

        void scan_callback(const sensor_msgs::msg::LaserScan::ConstSharedPtr &scan_msg) {
            // TODO: calculate TTC

            // TODO: publish drive/brake message

            //SUBSCRIBE
            float angle_min = scan_msg->angle_min;
            float angle_max = scan_msg->angle_max;
            float angle_increment = scan_msg->angle_increment;

            //FORWARD IS 0 degrees so adjust
            // double pi = 2*acos(0.0);
            // float angle_shift = 90 * pi / 180;

            // angle_min -= angle_shift;
            // angle_max -= angle_shift;

            //LENGTH OF RANGES VECTOR
            int range_len = scan_msg->ranges.size();

            //VARIABLES FOR LOOP
            float angle;
            float range_rate;
            float range;

            float TTC[range_len];

            double vx = this->vx;
    

            //TTC for each scan angle
            for(int i = 0; i < range_len; i++){
                angle = angle_min + (angle_increment * i);
                range = scan_msg->ranges[i];
                
                //get range rate
                range_rate = vx * cos(angle);

                //get TTC
                //DIVIDE BY ZERO ERROR
                TTC[i] = range / (std::max((range_rate), (float)0));


                //TEST OUTPUT (FRONT)
                // if(i == 540){
                // RCLCPP_INFO(this->get_logger(), 
                // "Range (front): %f\n, TTC: %f\nSpeed: %lf\nRange Rate: %f\nAngle: %f\n", 
                // scan_msg->ranges[i], TTC[i], vx, range_rate, angle);
                // }

                if(TTC[i] <= 1 && TTC[i] >= 0){
                    RCLCPP_INFO(this->get_logger(), 
                "Range: %f\n, TTC: %f\nSpeed: %lf\nRange Rate: %f\n", 
                scan_msg->ranges[i], TTC[i], vx, range_rate);
                    brake();
                    break;

                }

            }



            // float front = scan_msg->ranges[540];

            // RCLCPP_INFO(this->get_logger(), 
            // "Angle_mix: %f,\nAngle_max: %f,\nAngle_increment: %f,\nRange (front): %f\n, TTC: %f\nSpeed: %lf", 
            // angle_min, angle_max, angle_increment, front, TTC[540], vx);

            // RCLCPP_INFO(this->get_logger(), 
            // "Range (front): %f\n, TTC: %f\nSpeed: %lf", 
            // front, TTC[540], vx);

        }

};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Safety>());
    rclcpp::shutdown();
    return 0;
}