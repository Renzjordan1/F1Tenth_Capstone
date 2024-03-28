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

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber(): Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const sensor_msgs::msg::LaserScan & msg) const
    {
      float values[8];

      values[0] = msg.angle_min;
      values[1] = msg.angle_max;
      values[2] = msg.angle_increment;
      values[3] = msg.time_increment;
      values[4] = msg.scan_time;
      values[5] = msg.range_min;
      values[6] = msg.range_max;
      values[7] = msg.ranges[360];

      bool filter = false;

      for(int i = 0; i < (int)(sizeof(values)/sizeof(float)); i++){
        if (std::isinf(values[i]) || std::isnan(values[i])){
          filter = true;
        }
      }

      
      if(filter){
        RCLCPP_INFO(this->get_logger(), 
        "Scan Filtered\n");
      }

      else{
        RCLCPP_INFO(this->get_logger(), 
        "Angle_mix: %f,\nAngle_max: %f,\nAngle_increment: %f,\nTime_increment: %f,\nScan_time: %f,\nRange_min: %f,\nRange_max: %f\nRange (front): %f\n", 
        values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);
      }

    }
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
