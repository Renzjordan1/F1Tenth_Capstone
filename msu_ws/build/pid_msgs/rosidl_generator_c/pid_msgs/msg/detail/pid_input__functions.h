// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pid_msgs:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef PID_MSGS__MSG__DETAIL__PID_INPUT__FUNCTIONS_H_
#define PID_MSGS__MSG__DETAIL__PID_INPUT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pid_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pid_msgs/msg/detail/pid_input__struct.h"

/// Initialize msg/PIDInput message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pid_msgs__msg__PIDInput
 * )) before or use
 * pid_msgs__msg__PIDInput__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__init(pid_msgs__msg__PIDInput * msg);

/// Finalize msg/PIDInput message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
void
pid_msgs__msg__PIDInput__fini(pid_msgs__msg__PIDInput * msg);

/// Create msg/PIDInput message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pid_msgs__msg__PIDInput__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
pid_msgs__msg__PIDInput *
pid_msgs__msg__PIDInput__create();

/// Destroy msg/PIDInput message.
/**
 * It calls
 * pid_msgs__msg__PIDInput__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
void
pid_msgs__msg__PIDInput__destroy(pid_msgs__msg__PIDInput * msg);

/// Check for msg/PIDInput message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__are_equal(const pid_msgs__msg__PIDInput * lhs, const pid_msgs__msg__PIDInput * rhs);

/// Copy a msg/PIDInput message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__copy(
  const pid_msgs__msg__PIDInput * input,
  pid_msgs__msg__PIDInput * output);

/// Initialize array of msg/PIDInput messages.
/**
 * It allocates the memory for the number of elements and calls
 * pid_msgs__msg__PIDInput__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__Sequence__init(pid_msgs__msg__PIDInput__Sequence * array, size_t size);

/// Finalize array of msg/PIDInput messages.
/**
 * It calls
 * pid_msgs__msg__PIDInput__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
void
pid_msgs__msg__PIDInput__Sequence__fini(pid_msgs__msg__PIDInput__Sequence * array);

/// Create array of msg/PIDInput messages.
/**
 * It allocates the memory for the array and calls
 * pid_msgs__msg__PIDInput__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
pid_msgs__msg__PIDInput__Sequence *
pid_msgs__msg__PIDInput__Sequence__create(size_t size);

/// Destroy array of msg/PIDInput messages.
/**
 * It calls
 * pid_msgs__msg__PIDInput__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
void
pid_msgs__msg__PIDInput__Sequence__destroy(pid_msgs__msg__PIDInput__Sequence * array);

/// Check for msg/PIDInput message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__Sequence__are_equal(const pid_msgs__msg__PIDInput__Sequence * lhs, const pid_msgs__msg__PIDInput__Sequence * rhs);

/// Copy an array of msg/PIDInput messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pid_msgs
bool
pid_msgs__msg__PIDInput__Sequence__copy(
  const pid_msgs__msg__PIDInput__Sequence * input,
  pid_msgs__msg__PIDInput__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PID_MSGS__MSG__DETAIL__PID_INPUT__FUNCTIONS_H_
