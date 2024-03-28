// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ackermann_msgs:msg/AckermannDriveStamped.idl
// generated code does not contain a copyright notice

#ifndef ACKERMANN_MSGS__MSG__DETAIL__ACKERMANN_DRIVE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ACKERMANN_MSGS__MSG__DETAIL__ACKERMANN_DRIVE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ackermann_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ackermann_msgs/msg/detail/ackermann_drive_stamped__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ackermann_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ackermann_msgs
cdr_serialize(
  const ackermann_msgs::msg::AckermannDriveStamped & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ackermann_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ackermann_msgs::msg::AckermannDriveStamped & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ackermann_msgs
get_serialized_size(
  const ackermann_msgs::msg::AckermannDriveStamped & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ackermann_msgs
max_serialized_size_AckermannDriveStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ackermann_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ackermann_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ackermann_msgs, msg, AckermannDriveStamped)();

#ifdef __cplusplus
}
#endif

#endif  // ACKERMANN_MSGS__MSG__DETAIL__ACKERMANN_DRIVE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
