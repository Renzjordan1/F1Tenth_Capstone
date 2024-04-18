// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_H_
#define MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pid_error'
#include "my_messages/msg/detail/key_value__struct.h"

/// Struct defined in msg/PIDInput in the package my_messages.
typedef struct my_messages__msg__PIDInput
{
  float pid_vel;
  my_messages__msg__KeyValue__Sequence pid_error;
} my_messages__msg__PIDInput;

// Struct for a sequence of my_messages__msg__PIDInput.
typedef struct my_messages__msg__PIDInput__Sequence
{
  my_messages__msg__PIDInput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_messages__msg__PIDInput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_H_
