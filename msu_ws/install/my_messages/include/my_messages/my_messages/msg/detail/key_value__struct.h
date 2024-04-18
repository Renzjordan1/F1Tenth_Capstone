// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_messages:msg/KeyValue.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__KEY_VALUE__STRUCT_H_
#define MY_MESSAGES__MSG__DETAIL__KEY_VALUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/KeyValue in the package my_messages.
typedef struct my_messages__msg__KeyValue
{
  int32_t key;
  float value;
} my_messages__msg__KeyValue;

// Struct for a sequence of my_messages__msg__KeyValue.
typedef struct my_messages__msg__KeyValue__Sequence
{
  my_messages__msg__KeyValue * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_messages__msg__KeyValue__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MESSAGES__MSG__DETAIL__KEY_VALUE__STRUCT_H_
