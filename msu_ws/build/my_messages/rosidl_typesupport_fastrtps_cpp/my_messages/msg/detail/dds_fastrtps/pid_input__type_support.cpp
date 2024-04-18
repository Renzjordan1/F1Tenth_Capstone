// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice
#include "my_messages/msg/detail/pid_input__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_messages/msg/detail/pid_input__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace my_messages
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const my_messages::msg::KeyValue &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  my_messages::msg::KeyValue &);
size_t get_serialized_size(
  const my_messages::msg::KeyValue &,
  size_t current_alignment);
size_t
max_serialized_size_KeyValue(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace my_messages


namespace my_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_messages
cdr_serialize(
  const my_messages::msg::PIDInput & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pid_vel
  cdr << ros_message.pid_vel;
  // Member: pid_error
  {
    size_t size = ros_message.pid_error.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      my_messages::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.pid_error[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_messages::msg::PIDInput & ros_message)
{
  // Member: pid_vel
  cdr >> ros_message.pid_vel;

  // Member: pid_error
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.pid_error.resize(size);
    for (size_t i = 0; i < size; i++) {
      my_messages::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.pid_error[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_messages
get_serialized_size(
  const my_messages::msg::PIDInput & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pid_vel
  {
    size_t item_size = sizeof(ros_message.pid_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pid_error
  {
    size_t array_size = ros_message.pid_error.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        my_messages::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.pid_error[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_messages
max_serialized_size_PIDInput(
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


  // Member: pid_vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pid_error
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_messages::msg::typesupport_fastrtps_cpp::max_serialized_size_KeyValue(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_messages::msg::PIDInput;
    is_plain =
      (
      offsetof(DataType, pid_error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PIDInput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_messages::msg::PIDInput *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PIDInput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_messages::msg::PIDInput *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PIDInput__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_messages::msg::PIDInput *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PIDInput__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PIDInput(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PIDInput__callbacks = {
  "my_messages::msg",
  "PIDInput",
  _PIDInput__cdr_serialize,
  _PIDInput__cdr_deserialize,
  _PIDInput__get_serialized_size,
  _PIDInput__max_serialized_size
};

static rosidl_message_type_support_t _PIDInput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PIDInput__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<my_messages::msg::PIDInput>()
{
  return &my_messages::msg::typesupport_fastrtps_cpp::_PIDInput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_messages, msg, PIDInput)() {
  return &my_messages::msg::typesupport_fastrtps_cpp::_PIDInput__handle;
}

#ifdef __cplusplus
}
#endif
