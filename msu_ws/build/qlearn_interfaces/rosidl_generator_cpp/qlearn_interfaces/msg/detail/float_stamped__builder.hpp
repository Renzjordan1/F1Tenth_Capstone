// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qlearn_interfaces:msg/FloatStamped.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__MSG__DETAIL__FLOAT_STAMPED__BUILDER_HPP_
#define QLEARN_INTERFACES__MSG__DETAIL__FLOAT_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qlearn_interfaces/msg/detail/float_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qlearn_interfaces
{

namespace msg
{

namespace builder
{

class Init_FloatStamped_data
{
public:
  explicit Init_FloatStamped_data(::qlearn_interfaces::msg::FloatStamped & msg)
  : msg_(msg)
  {}
  ::qlearn_interfaces::msg::FloatStamped data(::qlearn_interfaces::msg::FloatStamped::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::msg::FloatStamped msg_;
};

class Init_FloatStamped_header
{
public:
  Init_FloatStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FloatStamped_data header(::qlearn_interfaces::msg::FloatStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FloatStamped_data(msg_);
  }

private:
  ::qlearn_interfaces::msg::FloatStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::msg::FloatStamped>()
{
  return qlearn_interfaces::msg::builder::Init_FloatStamped_header();
}

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__MSG__DETAIL__FLOAT_STAMPED__BUILDER_HPP_
