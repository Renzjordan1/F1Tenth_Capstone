// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qlearn_interfaces:msg/IntStamped.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__BUILDER_HPP_
#define QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qlearn_interfaces/msg/detail/int_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qlearn_interfaces
{

namespace msg
{

namespace builder
{

class Init_IntStamped_data
{
public:
  explicit Init_IntStamped_data(::qlearn_interfaces::msg::IntStamped & msg)
  : msg_(msg)
  {}
  ::qlearn_interfaces::msg::IntStamped data(::qlearn_interfaces::msg::IntStamped::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::msg::IntStamped msg_;
};

class Init_IntStamped_header
{
public:
  Init_IntStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IntStamped_data header(::qlearn_interfaces::msg::IntStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IntStamped_data(msg_);
  }

private:
  ::qlearn_interfaces::msg::IntStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::msg::IntStamped>()
{
  return qlearn_interfaces::msg::builder::Init_IntStamped_header();
}

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__BUILDER_HPP_
