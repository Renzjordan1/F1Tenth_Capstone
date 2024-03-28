// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef PID_MSGS__MSG__DETAIL__PID_INPUT__BUILDER_HPP_
#define PID_MSGS__MSG__DETAIL__PID_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pid_msgs/msg/detail/pid_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pid_msgs
{

namespace msg
{

namespace builder
{

class Init_PIDInput_pid_error
{
public:
  explicit Init_PIDInput_pid_error(::pid_msgs::msg::PIDInput & msg)
  : msg_(msg)
  {}
  ::pid_msgs::msg::PIDInput pid_error(::pid_msgs::msg::PIDInput::_pid_error_type arg)
  {
    msg_.pid_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pid_msgs::msg::PIDInput msg_;
};

class Init_PIDInput_pid_vel
{
public:
  Init_PIDInput_pid_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PIDInput_pid_error pid_vel(::pid_msgs::msg::PIDInput::_pid_vel_type arg)
  {
    msg_.pid_vel = std::move(arg);
    return Init_PIDInput_pid_error(msg_);
  }

private:
  ::pid_msgs::msg::PIDInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pid_msgs::msg::PIDInput>()
{
  return pid_msgs::msg::builder::Init_PIDInput_pid_vel();
}

}  // namespace pid_msgs

#endif  // PID_MSGS__MSG__DETAIL__PID_INPUT__BUILDER_HPP_
