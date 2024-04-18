// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__PID_INPUT__TRAITS_HPP_
#define MY_MESSAGES__MSG__DETAIL__PID_INPUT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_messages/msg/detail/pid_input__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pid_error'
#include "my_messages/msg/detail/key_value__traits.hpp"

namespace my_messages
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
    if (msg.pid_error.size() == 0) {
      out << "pid_error: []";
    } else {
      out << "pid_error: [";
      size_t pending_items = msg.pid_error.size();
      for (auto item : msg.pid_error) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
    if (msg.pid_error.size() == 0) {
      out << "pid_error: []\n";
    } else {
      out << "pid_error:\n";
      for (auto item : msg.pid_error) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
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

}  // namespace my_messages

namespace rosidl_generator_traits
{

[[deprecated("use my_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_messages::msg::PIDInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_messages::msg::PIDInput & msg)
{
  return my_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_messages::msg::PIDInput>()
{
  return "my_messages::msg::PIDInput";
}

template<>
inline const char * name<my_messages::msg::PIDInput>()
{
  return "my_messages/msg/PIDInput";
}

template<>
struct has_fixed_size<my_messages::msg::PIDInput>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_messages::msg::PIDInput>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_messages::msg::PIDInput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MESSAGES__MSG__DETAIL__PID_INPUT__TRAITS_HPP_
