// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pid_msgs/msg/detail/pid_input__rosidl_typesupport_introspection_c.h"
#include "pid_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pid_msgs/msg/detail/pid_input__functions.h"
#include "pid_msgs/msg/detail/pid_input__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pid_msgs__msg__PIDInput__init(message_memory);
}

void pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_fini_function(void * message_memory)
{
  pid_msgs__msg__PIDInput__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_member_array[2] = {
  {
    "pid_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pid_msgs__msg__PIDInput, pid_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pid_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pid_msgs__msg__PIDInput, pid_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_members = {
  "pid_msgs__msg",  // message namespace
  "PIDInput",  // message name
  2,  // number of fields
  sizeof(pid_msgs__msg__PIDInput),
  pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_member_array,  // message members
  pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_init_function,  // function to initialize message memory (memory has to be allocated)
  pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle = {
  0,
  &pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pid_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pid_msgs, msg, PIDInput)() {
  if (!pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle.typesupport_identifier) {
    pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pid_msgs__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
