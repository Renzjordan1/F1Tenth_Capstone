// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qlearn_interfaces:srv/SetFloat.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__BUILDER_HPP_
#define QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qlearn_interfaces/srv/detail/set_float__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qlearn_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetFloat_Request_data
{
public:
  Init_SetFloat_Request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qlearn_interfaces::srv::SetFloat_Request data(::qlearn_interfaces::srv::SetFloat_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::srv::SetFloat_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::srv::SetFloat_Request>()
{
  return qlearn_interfaces::srv::builder::Init_SetFloat_Request_data();
}

}  // namespace qlearn_interfaces


namespace qlearn_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetFloat_Response_success
{
public:
  Init_SetFloat_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qlearn_interfaces::srv::SetFloat_Response success(::qlearn_interfaces::srv::SetFloat_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::srv::SetFloat_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::srv::SetFloat_Response>()
{
  return qlearn_interfaces::srv::builder::Init_SetFloat_Response_success();
}

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__BUILDER_HPP_
