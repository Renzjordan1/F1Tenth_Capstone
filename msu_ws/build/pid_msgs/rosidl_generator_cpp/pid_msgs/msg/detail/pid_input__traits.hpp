// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef PID_MSGS__MSG__DETAIL__PID_INPUT__TRAITS_HPP_
#define PID_MSGS__MSG__DETAIL__PID_INPUT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pid_msgs/msg/detail/pid_input__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pid_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PIDInput & msg,
  std::ostream & out)
{
  out << "{";
  // member: pid_vel
  {
    out << "pid_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_vel, out);
    out << ", ";
  }

  // member: pid_error
  {
    out << "pid_error: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PIDInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pid_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pid_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_vel, out);
    out << "\n";
  }

  // member: pid_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pid_error: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PIDInput & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pid_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pid_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pid_msgs::msg::PIDInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  pid_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pid_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pid_msgs::msg::PIDInput & msg)
{
  return pid_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pid_msgs::msg::PIDInput>()
{
  return "pid_msgs::msg::PIDInput";
}

template<>
inline const char * name<pid_msgs::msg::PIDInput>()
{
  return "pid_msgs/msg/PIDInput";
}

template<>
struct has_fixed_size<pid_msgs::msg::PIDInput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pid_msgs::msg::PIDInput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pid_msgs::msg::PIDInput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PID_MSGS__MSG__DETAIL__PID_INPUT__TRAITS_HPP_
