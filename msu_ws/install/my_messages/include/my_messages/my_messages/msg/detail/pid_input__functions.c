// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice
#include "my_messages/msg/detail/pid_input__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pid_error`
#include "my_messages/msg/detail/key_value__functions.h"

bool
my_messages__msg__PIDInput__init(my_messages__msg__PIDInput * msg)
{
  if (!msg) {
    return false;
  }
  // pid_vel
  // pid_error
  if (!my_messages__msg__KeyValue__Sequence__init(&msg->pid_error, 0)) {
    my_messages__msg__PIDInput__fini(msg);
    return false;
  }
  return true;
}

void
my_messages__msg__PIDInput__fini(my_messages__msg__PIDInput * msg)
{
  if (!msg) {
    return;
  }
  // pid_vel
  // pid_error
  my_messages__msg__KeyValue__Sequence__fini(&msg->pid_error);
}

bool
my_messages__msg__PIDInput__are_equal(const my_messages__msg__PIDInput * lhs, const my_messages__msg__PIDInput * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pid_vel
  if (lhs->pid_vel != rhs->pid_vel) {
    return false;
  }
  // pid_error
  if (!my_messages__msg__KeyValue__Sequence__are_equal(
      &(lhs->pid_error), &(rhs->pid_error)))
  {
    return false;
  }
  return true;
}

bool
my_messages__msg__PIDInput__copy(
  const my_messages__msg__PIDInput * input,
  my_messages__msg__PIDInput * output)
{
  if (!input || !output) {
    return false;
  }
  // pid_vel
  output->pid_vel = input->pid_vel;
  // pid_error
  if (!my_messages__msg__KeyValue__Sequence__copy(
      &(input->pid_error), &(output->pid_error)))
  {
    return false;
  }
  return true;
}

my_messages__msg__PIDInput *
my_messages__msg__PIDInput__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_messages__msg__PIDInput * msg = (my_messages__msg__PIDInput *)allocator.allocate(sizeof(my_messages__msg__PIDInput), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_messages__msg__PIDInput));
  bool success = my_messages__msg__PIDInput__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_messages__msg__PIDInput__destroy(my_messages__msg__PIDInput * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_messages__msg__PIDInput__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_messages__msg__PIDInput__Sequence__init(my_messages__msg__PIDInput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_messages__msg__PIDInput * data = NULL;

  if (size) {
    data = (my_messages__msg__PIDInput *)allocator.zero_allocate(size, sizeof(my_messages__msg__PIDInput), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_messages__msg__PIDInput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_messages__msg__PIDInput__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_messages__msg__PIDInput__Sequence__fini(my_messages__msg__PIDInput__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_messages__msg__PIDInput__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_messages__msg__PIDInput__Sequence *
my_messages__msg__PIDInput__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_messages__msg__PIDInput__Sequence * array = (my_messages__msg__PIDInput__Sequence *)allocator.allocate(sizeof(my_messages__msg__PIDInput__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_messages__msg__PIDInput__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_messages__msg__PIDInput__Sequence__destroy(my_messages__msg__PIDInput__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_messages__msg__PIDInput__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_messages__msg__PIDInput__Sequence__are_equal(const my_messages__msg__PIDInput__Sequence * lhs, const my_messages__msg__PIDInput__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_messages__msg__PIDInput__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_messages__msg__PIDInput__Sequence__copy(
  const my_messages__msg__PIDInput__Sequence * input,
  my_messages__msg__PIDInput__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_messages__msg__PIDInput);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_messages__msg__PIDInput * data =
      (my_messages__msg__PIDInput *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_messages__msg__PIDInput__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_messages__msg__PIDInput__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_messages__msg__PIDInput__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
