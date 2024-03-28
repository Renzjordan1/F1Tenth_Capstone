// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qlearn_interfaces:srv/LoadQTable.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__STRUCT_H_
#define QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filename'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LoadQTable in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__LoadQTable_Request
{
  rosidl_runtime_c__String filename;
} qlearn_interfaces__srv__LoadQTable_Request;

// Struct for a sequence of qlearn_interfaces__srv__LoadQTable_Request.
typedef struct qlearn_interfaces__srv__LoadQTable_Request__Sequence
{
  qlearn_interfaces__srv__LoadQTable_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__LoadQTable_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/LoadQTable in the package qlearn_interfaces.
typedef struct qlearn_interfaces__srv__LoadQTable_Response
{
  bool success;
} qlearn_interfaces__srv__LoadQTable_Response;

// Struct for a sequence of qlearn_interfaces__srv__LoadQTable_Response.
typedef struct qlearn_interfaces__srv__LoadQTable_Response__Sequence
{
  qlearn_interfaces__srv__LoadQTable_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qlearn_interfaces__srv__LoadQTable_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QLEARN_INTERFACES__SRV__DETAIL__LOAD_Q_TABLE__STRUCT_H_
