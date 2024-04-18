// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice
#include "pid_msgs/msg/detail/pid_input__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pid_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pid_msgs/msg/detail/pid_input__struct.h"
#include "pid_msgs/msg/detail/pid_input__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PIDInput__ros_msg_type = pid_msgs__msg__PIDInput;

static bool _PIDInput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PIDInput__ros_msg_type * ros_message = static_cast<const _PIDInput__ros_msg_type *>(untyped_ros_message);
  // Field name: pid_vel
  {
    cdr << ros_message->pid_vel;
  }

  // Field name: pid_error
  {
    cdr << ros_message->pid_error;
  }

  return true;
}

static bool _PIDInput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PIDInput__ros_msg_type * ros_message = static_cast<_PIDInput__ros_msg_type *>(untyped_ros_message);
  // Field name: pid_vel
  {
    cdr >> ros_message->pid_vel;
  }

  // Field name: pid_error
  {
    cdr >> ros_message->pid_error;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pid_msgs
size_t get_serialized_size_pid_msgs__msg__PIDInput(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PIDInput__ros_msg_type * ros_message = static_cast<const _PIDInput__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pid_vel
  {
    size_t item_size = sizeof(ros_message->pid_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pid_error
  {
    size_t item_size = sizeof(ros_message->pid_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PIDInput__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pid_msgs__msg__PIDInput(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pid_msgs
size_t max_serialized_size_pid_msgs__msg__PIDInput(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: pid_vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pid_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pid_msgs__msg__PIDInput;
    is_plain =
      (
      offsetof(DataType, pid_error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PIDInput__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pid_msgs__msg__PIDInput(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PIDInput = {
  "pid_msgs::msg",
  "PIDInput",
  _PIDInput__cdr_serialize,
  _PIDInput__cdr_deserialize,
  _PIDInput__get_serialized_size,
  _PIDInput__max_serialized_size
};

static rosidl_message_type_support_t _PIDInput__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PIDInput,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pid_msgs, msg, PIDInput)() {
  return &_PIDInput__type_support;
}

#if defined(__cplusplus)
}
#endif
