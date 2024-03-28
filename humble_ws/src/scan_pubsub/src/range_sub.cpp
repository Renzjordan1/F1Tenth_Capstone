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
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber(): Node("minimal_subscriber")
    {
      subscription_close = this->create_subscription<std_msgs::msg::Float64>(
        "/closest_point", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

      subscription_far = this->create_subscription<std_msgs::msg::Float64>(
        "/farthest_point", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

      // subscription_close = message_filters::Subscriber<StampedStringMsg> string_sub(node, "stamped_string_topic", qos_profile);
      // subscription_far = message_filters::Subscriber<StampedBooleanMsg> bool_sub(node, "stamped_boolean_topic", qos_profile);
    }

  private:
    void topic_callback(const std_msgs::msg::Float64 & msg) const
    {
      RCLCPP_INFO(this->get_logger(), 
      "Closest Point: %f,\nAFarthest_Point: %f,\nAngle_increment: %f,\nTime_increment: %f,\nScan_time: %f,\nRange_min: %f,\nRange_max: %f\nRange (front): %f\n", 
      values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);

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
