// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_messages:msg/KeyValue.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_
#define MY_MESSAGES__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_messages/msg/detail/key_value__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyValue & msg,
  std::ostream & out)
{
  out << "{";
  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KeyValue & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyValue & msg, bool use_flow_style = false)
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
  const my_messages::msg::KeyValue & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_messages::msg::KeyValue & msg)
{
  return my_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_messages::msg::KeyValue>()
{
  return "my_messages::msg::KeyValue";
}

template<>
inline const char * name<my_messages::msg::KeyValue>()
{
  return "my_messages/msg/KeyValue";
}

template<>
struct has_fixed_size<my_messages::msg::KeyValue>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_messages::msg::KeyValue>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_messages::msg::KeyValue>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MESSAGES__MSG__DETAIL__KEY_VALUE__TRAITS_HPP_
