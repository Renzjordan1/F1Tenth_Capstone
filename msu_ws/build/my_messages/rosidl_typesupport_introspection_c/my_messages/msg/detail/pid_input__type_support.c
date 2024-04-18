// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_messages/msg/detail/pid_input__rosidl_typesupport_introspection_c.h"
#include "my_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_messages/msg/detail/pid_input__functions.h"
#include "my_messages/msg/detail/pid_input__struct.h"


// Include directives for member types
// Member `pid_error`
#include "my_messages/msg/key_value.h"
// Member `pid_error`
#include "my_messages/msg/detail/key_value__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_messages__msg__PIDInput__init(message_memory);
}

void my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_fini_function(void * message_memory)
{
  my_messages__msg__PIDInput__fini(message_memory);
}

size_t my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__size_function__PIDInput__pid_error(
  const void * untyped_member)
{
  const my_messages__msg__KeyValue__Sequence * member =
    (const my_messages__msg__KeyValue__Sequence *)(untyped_member);
  return member->size;
}

const void * my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_const_function__PIDInput__pid_error(
  const void * untyped_member, size_t index)
{
  const my_messages__msg__KeyValue__Sequence * member =
    (const my_messages__msg__KeyValue__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_function__PIDInput__pid_error(
  void * untyped_member, size_t index)
{
  my_messages__msg__KeyValue__Sequence * member =
    (my_messages__msg__KeyValue__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__fetch_function__PIDInput__pid_error(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const my_messages__msg__KeyValue * item =
    ((const my_messages__msg__KeyValue *)
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_const_function__PIDInput__pid_error(untyped_member, index));
  my_messages__msg__KeyValue * value =
    (my_messages__msg__KeyValue *)(untyped_value);
  *value = *item;
}

void my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__assign_function__PIDInput__pid_error(
  void * untyped_member, size_t index, const void * untyped_value)
{
  my_messages__msg__KeyValue * item =
    ((my_messages__msg__KeyValue *)
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_function__PIDInput__pid_error(untyped_member, index));
  const my_messages__msg__KeyValue * value =
    (const my_messages__msg__KeyValue *)(untyped_value);
  *item = *value;
}

bool my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__resize_function__PIDInput__pid_error(
  void * untyped_member, size_t size)
{
  my_messages__msg__KeyValue__Sequence * member =
    (my_messages__msg__KeyValue__Sequence *)(untyped_member);
  my_messages__msg__KeyValue__Sequence__fini(member);
  return my_messages__msg__KeyValue__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_member_array[2] = {
  {
    "pid_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_messages__msg__PIDInput, pid_vel),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_messages__msg__PIDInput, pid_error),  // bytes offset in struct
    NULL,  // default value
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__size_function__PIDInput__pid_error,  // size() function pointer
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_const_function__PIDInput__pid_error,  // get_const(index) function pointer
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__get_function__PIDInput__pid_error,  // get(index) function pointer
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__fetch_function__PIDInput__pid_error,  // fetch(index, &value) function pointer
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__assign_function__PIDInput__pid_error,  // assign(index, value) function pointer
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__resize_function__PIDInput__pid_error  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_members = {
  "my_messages__msg",  // message namespace
  "PIDInput",  // message name
  2,  // number of fields
  sizeof(my_messages__msg__PIDInput),
  my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_member_array,  // message members
  my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_init_function,  // function to initialize message memory (memory has to be allocated)
  my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle = {
  0,
  &my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_messages, msg, PIDInput)() {
  my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_messages, msg, KeyValue)();
  if (!my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle.typesupport_identifier) {
    my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_messages__msg__PIDInput__rosidl_typesupport_introspection_c__PIDInput_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
