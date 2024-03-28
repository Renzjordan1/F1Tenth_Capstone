// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_messages:msg/KeyValue.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__KEY_VALUE__BUILDER_HPP_
#define MY_MESSAGES__MSG__DETAIL__KEY_VALUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_messages/msg/detail/key_value__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_messages
{

namespace msg
{

namespace builder
{

class Init_KeyValue_value
{
public:
  explicit Init_KeyValue_value(::my_messages::msg::KeyValue & msg)
  : msg_(msg)
  {}
  ::my_messages::msg::KeyValue value(::my_messages::msg::KeyValue::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_messages::msg::KeyValue msg_;
};

class Init_KeyValue_key
{
public:
  Init_KeyValue_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyValue_value key(::my_messages::msg::KeyValue::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_KeyValue_value(msg_);
  }

private:
  ::my_messages::msg::KeyValue msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_messages::msg::KeyValue>()
{
  return my_messages::msg::builder::Init_KeyValue_key();
}

}  // namespace my_messages

#endif  // MY_MESSAGES__MSG__DETAIL__KEY_VALUE__BUILDER_HPP_
