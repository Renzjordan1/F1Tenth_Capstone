// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef PID_MSGS__MSG__DETAIL__PID_INPUT__STRUCT_H_
#define PID_MSGS__MSG__DETAIL__PID_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PIDInput in the package pid_msgs.
typedef struct pid_msgs__msg__PIDInput
{
  float pid_vel;
  float pid_error;
} pid_msgs__msg__PIDInput;

// Struct for a sequence of pid_msgs__msg__PIDInput.
typedef struct pid_msgs__msg__PIDInput__Sequence
{
  pid_msgs__msg__PIDInput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pid_msgs__msg__PIDInput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PID_MSGS__MSG__DETAIL__PID_INPUT__STRUCT_H_
