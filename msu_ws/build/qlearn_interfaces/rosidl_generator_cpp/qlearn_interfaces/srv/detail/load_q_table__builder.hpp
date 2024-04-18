// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qlearn_interfaces:srv/LoadQTable.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__BUILDER_HPP_
#define QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qlearn_interfaces/srv/detail/load_q_table__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qlearn_interfaces
{

namespace srv
{

namespace builder
{

class Init_LoadQTable_Request_filename
{
public:
  Init_LoadQTable_Request_filename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qlearn_interfaces::srv::LoadQTable_Request filename(::qlearn_interfaces::srv::LoadQTable_Request::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::srv::LoadQTable_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::srv::LoadQTable_Request>()
{
  return qlearn_interfaces::srv::builder::Init_LoadQTable_Request_filename();
}

}  // namespace qlearn_interfaces


namespace qlearn_interfaces
{

namespace srv
{

namespace builder
{

class Init_LoadQTable_Response_success
{
public:
  Init_LoadQTable_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qlearn_interfaces::srv::LoadQTable_Response success(::qlearn_interfaces::srv::LoadQTable_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qlearn_interfaces::srv::LoadQTable_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qlearn_interfaces::srv::LoadQTable_Response>()
{
  return qlearn_interfaces::srv::builder::Init_LoadQTable_Response_success();
}

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__BUILDER_HPP_
