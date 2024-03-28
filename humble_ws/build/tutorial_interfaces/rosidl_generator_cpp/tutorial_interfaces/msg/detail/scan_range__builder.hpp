// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/ScanRange.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__SCAN_RANGE__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__SCAN_RANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/msg/detail/scan_range__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_ScanRange_max
{
public:
  explicit Init_ScanRange_max(::tutorial_interfaces::msg::ScanRange & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::ScanRange max(::tutorial_interfaces::msg::ScanRange::_max_type arg)
  {
    msg_.max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::ScanRange msg_;
};

class Init_ScanRange_min
{
public:
  Init_ScanRange_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScanRange_max min(::tutorial_interfaces::msg::ScanRange::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_ScanRange_max(msg_);
  }

private:
  ::tutorial_interfaces::msg::ScanRange msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::ScanRange>()
{
  return tutorial_interfaces::msg::builder::Init_ScanRange_min();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__SCAN_RANGE__BUILDER_HPP_
