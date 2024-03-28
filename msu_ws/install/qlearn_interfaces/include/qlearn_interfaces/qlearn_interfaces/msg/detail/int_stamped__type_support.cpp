// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from qlearn_interfaces:msg/IntStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "qlearn_interfaces/msg/detail/int_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace qlearn_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IntStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) qlearn_interfaces::msg::IntStamped(_init);
}

void IntStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<qlearn_interfaces::msg::IntStamped *>(message_memory);
  typed_message->~IntStamped();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IntStamped_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qlearn_interfaces::msg::IntStamped, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qlearn_interfaces::msg::IntStamped, data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IntStamped_message_members = {
  "qlearn_interfaces::msg",  // message namespace
  "IntStamped",  // message name
  2,  // number of fields
  sizeof(qlearn_interfaces::msg::IntStamped),
  IntStamped_message_member_array,  // message members
  IntStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  IntStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IntStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IntStamped_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace qlearn_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qlearn_interfaces::msg::IntStamped>()
{
  return &::qlearn_interfaces::msg::rosidl_typesupport_introspection_cpp::IntStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qlearn_interfaces, msg, IntStamped)() {
  return &::qlearn_interfaces::msg::rosidl_typesupport_introspection_cpp::IntStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
