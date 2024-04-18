// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qlearn_interfaces:msg/IntStamped.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_H_
#define QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/IntStamped in the package qlearn_interfaces.
typedef struct qlearn_interfaces__msg__IntStamped
{
  std_msgs__msg__Header header;
  int32_t data;
} qlearn_interfaces__msg__IntStamped;

// Struct for a sequence of qlearn_interfaces__msg__IntStamped.
typedef struct qlearn_interfaces__msg__IntStamped__Sequence
{
  qlearn_interfaces__msg__IntStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__msg__IntStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_H_
