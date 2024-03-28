#include "rclcpp/rclcpp.hpp"
#include <string>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"

// using namespace std::chrono_literals;
using std::placeholders::_1;


class WallFollow : public rclcpp::Node {

public:
    WallFollow() : Node("wall_follow_node")
    {
        // TODO: create ROS subscribers and publishers

        // Scan Subscriber
        scan_sub = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, std::bind(&WallFollow::scan_callback, this, _1));

        //Drive publisher
        drive_pub = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("/drive", 10);
    }

private:
    // PID CONTROL PARAMS
    double kp = 10.0;
    double kd = 5.0;
    double ki = 0.0;

    double servo_offset = 0.0;
    double prev_error = 0.0;
    double error = 0.0;
    double integral = 0.0;

    double dist = 1;

    double lookahead = 1.0;

    // int right_angle_ind = 0;
    // int min_angle_ind = 0;
    // int max_angle_ind = 0;

    // Topics
    std::string lidarscan_topic = "/scan";
    std::string drive_topic = "/drive";

    /// TODO: create ROS subscribers and publishers
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub;
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr drive_pub;


    //Find index of desired angle
    int find_angle_index(float angle_min, float angle_increment, float angle){

        //Angle to Radians
        double pi = 2*acos(0.0);
        angle = angle * pi / 180;

        int increments = (angle - angle_min) / angle_increment;

        return increments;

    }


    void scan_callback(const sensor_msgs::msg::LaserScan::ConstSharedPtr &scan_msg) 
    {
        /*
        Callback function for LaserScan messages. Calculate the error and publish the drive message in this function.

        Args:
            msg: Incoming LaserScan message

        Returns:
            None
        */

        //SUBSCRIBE
        float angle_min = scan_msg->angle_min;
        // float angle_max = scan_msg->angle_max;
        float angle_increment = scan_msg->angle_increment;

        // int range_len = scan_msg->ranges.size();
        float ranges[1080];
        std::copy(std::begin(scan_msg->ranges), std::end(scan_msg->ranges), std::begin(ranges));


        //Possible Angles to Use
        int right_angle_ind = find_angle_index(angle_min, angle_increment, 90.0);
        int max_angle_ind = find_angle_index(angle_min, angle_increment, 70.0);
        int min_angle_ind = find_angle_index(angle_min, angle_increment, 0.0);

        //Angle and Ranges used
        double second_angle;
        float second_range;
        float right_range = ranges[right_angle_ind];

        //Find first angle to use
        for(int i = max_angle_ind; i > min_angle_ind; i--){
            if ( !(std::isinf(ranges[i]) || std::isnan(ranges[i])) ){
                second_angle = angle_min + (i * angle_increment);
                second_range = ranges[i];
                break;
            }
        }

        //Get Alpha
        double alpha = get_alpha(second_angle, second_range, right_range);

        //Get Error
        this->error = get_error(right_range, alpha, this->dist); // TODO: replace with error calculated by get_error()
        this->integral += this->error;

        // double velocity = 0.0; // TODO: calculate desired car velocity based on error
        // TODO: actuate the car with PID
        
        pid_control();;

        this->prev_error = error;

        RCLCPP_INFO(this->get_logger(), 
      "index: %d", right_angle_ind);

    }

    double get_alpha(double second_angle, float a, float b){
        double pi = 2*acos(0.0);
        double theta = ((90.0 * pi/180) - second_angle);
        double alpha = atan( (a * cos(theta) - b) / (a * sin(theta)) );

        return alpha;
    }


    double get_error(float b, double alpha, double dist)
    {
        /*
        Calculates the error to the wall. Follow the wall to the left (going counter clockwise in the Levine loop). You potentially will need to use get_range()

        Args:
            range_data: single range array from the LiDAR
            dist: desired distance to the wall

        Returns:
            error: calculated error
        */

        // TODO:implement

    
        double distance = b * cos(alpha);
        double new_distance =  distance + this->lookahead * sin(alpha);

        double error = -1 * (dist - new_distance);

        RCLCPP_INFO(this->get_logger(), 
      "Distance: %lf,\nNew Distance: %lf,\nError: %lf,\nDelta: %lf,\n", 
      distance, new_distance, error, error - this->prev_error);

        return error;
    }



    void pid_control()
    {
        /*
        Based on the calculated error, publish vehicle control

        Args:
            error: calculated error
            velocity: desired velocity

        Returns:
            None
        */

        double angle = (this->kp * this->error + this->kd * (this->error - this->prev_error) + this->ki * this->integral);
        // TODO: Use kp, ki & kd to implement a PID controller

        double velocity;
        //Determine velocity
        double pi = 2*acos(0.0);
        if(angle >= 0 && angle < 10*pi/180){
            velocity = 1.5;
        }
        else if(angle >= 10*pi/180 && angle < 20*pi/180){
            velocity = 1.0;
        }
        else{
            velocity = 0.5;
        }

        
        auto drive_msg = ackermann_msgs::msg::AckermannDriveStamped();
        // TODO: fill in drive message and publish

        // std_msgs/Header header
        // ackermann_msgs/AckermannDrive drive
        //     float32 steering_angle
        //     float32 steering_angle_velocity
        //     float32 speed
        //     float32 acceleration
        //     float32 jerk

    //     RCLCPP_INFO(this->get_logger(), 
    //   "Steering Angle: %lf,\nVelocity: %lf\nError: %lf\nDelta: %lf\n", 
    //   angle*180/pi, velocity, this->error, this->error - this->prev_error);

        drive_msg.drive.steering_angle = angle;
        drive_msg.drive.speed = velocity;
        drive_pub->publish(drive_msg);
    }

};
int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WallFollow>());
    rclcpp::shutdown();
    return 0;
}