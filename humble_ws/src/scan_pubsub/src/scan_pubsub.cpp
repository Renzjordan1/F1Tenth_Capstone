// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <functional>
#include <memory>

#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#include "std_msgs/msg/float64.hpp"

#include "tutorial_interfaces/msg/scan_range.hpp"


using namespace std::chrono_literals;
using std::placeholders::_1;

class Scan_PubSub : public rclcpp::Node
{
  public:
    Scan_PubSub(): Node("scan_pubsub")
    {

      //Subscriber
      subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&Scan_PubSub::topic_callback, this, _1));


      //Publisher
      // publisher_close = this->create_publisher<std_msgs::msg::Float64>("/closest_point", 10);
      // publisher_far = this->create_publisher<std_msgs::msg::Float64>("/farthest_point", 10);
      publisher_ = this->create_publisher<tutorial_interfaces::msg::ScanRange>("/scan_range", 10);

      // timer_ = this->create_wall_timer(
      // 500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void topic_callback(const sensor_msgs::msg::LaserScan & msg) const
    {

      //SUBSCRIBE
      float values[8];

      values[0] = msg.angle_min;
      values[1] = msg.angle_max;
      values[2] = msg.angle_increment;
      values[3] = msg.time_increment;
      values[4] = msg.scan_time;
      values[5] = msg.range_min;
      values[6] = msg.range_max;
      values[7] = msg.ranges[360];
      
      RCLCPP_INFO(this->get_logger(), 
      "Angle_mix: %f,\nAngle_max: %f,\nAngle_increment: %f,\nTime_increment: %f,\nScan_time: %f,\nRange_min: %f,\nRange_max: %f\nRange (front): %f\n", 
      values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);


      //PUBLISH
      // float ranges[720];
      // std::copy(std::begin(msg.ranges), std::end(msg.ranges), std::begin(ranges));

      float min = -1;
      float max = -1;

      //find closest and farthest ranges
      for(int i = 0; i < 720; i++){
        if (!(std::isinf(msg.ranges[i]) || std::isnan(msg.ranges[i]))){

          if (min == -1 && max == -1){
            min = msg.ranges[i];
            max = msg.ranges[i];
          }

          else{
            if(msg.ranges[i] > max){
              max = msg.ranges[i];
            }

            if(msg.ranges[i] < min){
              min = msg.ranges[i];
            }
          }
        }
      }

      // auto close_msg = std_msgs::msg::Float64();
      // close_msg.data = min;

      // auto far_msg = std_msgs::msg::Float64();
      // far_msg.data = max;

      auto R_msg = tutorial_interfaces::msg::ScanRange();
      R_msg.min = min;
      R_msg.max = max;

      RCLCPP_INFO(this->get_logger(), "Publishing- Close: %f, Far: %f", R_msg.min, R_msg.max);

      // publisher_close->publish(close_msg);
      // publisher_far->publish(far_msg);

      publisher_->publish(R_msg);




    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    // rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_close;
    // rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_far;
    rclcpp::Publisher<tutorial_interfaces::msg::ScanRange>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Scan_PubSub>());
  rclcpp::shutdown();
  return 0;
}
