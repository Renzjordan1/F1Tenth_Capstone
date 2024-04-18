// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qlearn_interfaces:srv/SetInt.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__SET_INT__STRUCT_H_
#define QLEARN_INTERFACES__SRV__DETAIL__SET_INT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetInt in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__SetInt_Request
{
  int64_t data;
} qlearn_interfaces__srv__SetInt_Request;

// Struct for a sequence of qlearn_interfaces__srv__SetInt_Request.
typedef struct qlearn_interfaces__srv__SetInt_Request__Sequence
{
  qlearn_interfaces__srv__SetInt_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__SetInt_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetInt in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__SetInt_Response
{
  bool success;
} qlearn_interfaces__srv__SetInt_Response;

// Struct for a sequence of qlearn_interfaces__srv__SetInt_Response.
typedef struct qlearn_interfaces__srv__SetInt_Response__Sequence
{
  qlearn_interfaces__srv__SetInt_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__SetInt_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QLEARN_INTERFACES__SRV__DETAIL__SET_INT__STRUCT_H_
