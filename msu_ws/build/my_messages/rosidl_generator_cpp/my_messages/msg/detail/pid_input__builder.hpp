// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__PID_INPUT__BUILDER_HPP_
#define MY_MESSAGES__MSG__DETAIL__PID_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_messages/msg/detail/pid_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_messages
{

namespace msg
{

namespace builder
{

class Init_PIDInput_pid_error
{
public:
  explicit Init_PIDInput_pid_error(::my_messages::msg::PIDInput & msg)
  : msg_(msg)
  {}
  ::my_messages::msg::PIDInput pid_error(::my_messages::msg::PIDInput::_pid_error_type arg)
  {
    msg_.pid_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_messages::msg::PIDInput msg_;
};

class Init_PIDInput_pid_vel
{
public:
  Init_PIDInput_pid_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PIDInput_pid_error pid_vel(::my_messages::msg::PIDInput::_pid_vel_type arg)
  {
    msg_.pid_vel = std::move(arg);
    return Init_PIDInput_pid_error(msg_);
  }

private:
  ::my_messages::msg::PIDInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_messages::msg::PIDInput>()
{
  return my_messages::msg::builder::Init_PIDInput_pid_vel();
}

}  // namespace my_messages

#endif  // MY_MESSAGES__MSG__DETAIL__PID_INPUT__BUILDER_HPP_
