// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_messages/msg/detail/pid_input__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PIDInput_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_messages::msg::PIDInput(_init);
}

void PIDInput_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_messages::msg::PIDInput *>(message_memory);
  typed_message->~PIDInput();
}

size_t size_function__PIDInput__pid_error(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<my_messages::msg::KeyValue> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PIDInput__pid_error(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<my_messages::msg::KeyValue> *>(untyped_member);
  return &member[index];
}

void * get_function__PIDInput__pid_error(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<my_messages::msg::KeyValue> *>(untyped_member);
  return &member[index];
}

void fetch_function__PIDInput__pid_error(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const my_messages::msg::KeyValue *>(
    get_const_function__PIDInput__pid_error(untyped_member, index));
  auto & value = *reinterpret_cast<my_messages::msg::KeyValue *>(untyped_value);
  value = item;
}

void assign_function__PIDInput__pid_error(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<my_messages::msg::KeyValue *>(
    get_function__PIDInput__pid_error(untyped_member, index));
  const auto & value = *reinterpret_cast<const my_messages::msg::KeyValue *>(untyped_value);
  item = value;
}

void resize_function__PIDInput__pid_error(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<my_messages::msg::KeyValue> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PIDInput_message_member_array[2] = {
  {
    "pid_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_messages::msg::PIDInput, pid_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pid_error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<my_messages::msg::KeyValue>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_messages::msg::PIDInput, pid_error),  // bytes offset in struct
    nullptr,  // default value
    size_function__PIDInput__pid_error,  // size() function pointer
    get_const_function__PIDInput__pid_error,  // get_const(index) function pointer
    get_function__PIDInput__pid_error,  // get(index) function pointer
    fetch_function__PIDInput__pid_error,  // fetch(index, &value) function pointer
    assign_function__PIDInput__pid_error,  // assign(index, value) function pointer
    resize_function__PIDInput__pid_error  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PIDInput_message_members = {
  "my_messages::msg",  // message namespace
  "PIDInput",  // message name
  2,  // number of fields
  sizeof(my_messages::msg::PIDInput),
  PIDInput_message_member_array,  // message members
  PIDInput_init_function,  // function to initialize message memory (memory has to be allocated)
  PIDInput_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PIDInput_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PIDInput_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_messages::msg::PIDInput>()
{
  return &::my_messages::msg::rosidl_typesupport_introspection_cpp::PIDInput_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_messages, msg, PIDInput)() {
  return &::my_messages::msg::rosidl_typesupport_introspection_cpp::PIDInput_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
