// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qlearn_interfaces:srv/SetFloat.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__STRUCT_H_
#define QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetFloat in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__SetFloat_Request
{
  double data;
} qlearn_interfaces__srv__SetFloat_Request;

// Struct for a sequence of qlearn_interfaces__srv__SetFloat_Request.
typedef struct qlearn_interfaces__srv__SetFloat_Request__Sequence
{
  qlearn_interfaces__srv__SetFloat_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__SetFloat_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetFloat in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__SetFloat_Response
{
  bool success;
} qlearn_interfaces__srv__SetFloat_Response;

// Struct for a sequence of qlearn_interfaces__srv__SetFloat_Response.
typedef struct qlearn_interfaces__srv__SetFloat_Response__Sequence
{
  qlearn_interfaces__srv__SetFloat_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__SetFloat_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QLEARN_INTERFACES__SRV__DETAIL__SET_FLOAT__STRUCT_H_
