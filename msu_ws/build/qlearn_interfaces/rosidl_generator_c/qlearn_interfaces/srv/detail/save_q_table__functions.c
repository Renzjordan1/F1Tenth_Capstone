// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qlearn_interfaces:srv/SaveQTable.idl
// generated code does not contain a copyright notice
#include "qlearn_interfaces/srv/detail/save_q_table__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"

bool
qlearn_interfaces__srv__SaveQTable_Request__init(qlearn_interfaces__srv__SaveQTable_Request * msg)
{
  if (!msg) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__init(&msg->filename)) {
    qlearn_interfaces__srv__SaveQTable_Request__fini(msg);
    return false;
  }
  return true;
}

void
qlearn_interfaces__srv__SaveQTable_Request__fini(qlearn_interfaces__srv__SaveQTable_Request * msg)
{
  if (!msg) {
    return;
  }
  // filename
  rosidl_runtime_c__String__fini(&msg->filename);
}

bool
qlearn_interfaces__srv__SaveQTable_Request__are_equal(const qlearn_interfaces__srv__SaveQTable_Request * lhs, const qlearn_interfaces__srv__SaveQTable_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filename), &(rhs->filename)))
  {
    return false;
  }
  return true;
}

bool
qlearn_interfaces__srv__SaveQTable_Request__copy(
  const qlearn_interfaces__srv__SaveQTable_Request * input,
  qlearn_interfaces__srv__SaveQTable_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__copy(
      &(input->filename), &(output->filename)))
  {
    return false;
  }
  return true;
}

qlearn_interfaces__srv__SaveQTable_Request *
qlearn_interfaces__srv__SaveQTable_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Request * msg = (qlearn_interfaces__srv__SaveQTable_Request *)allocator.allocate(sizeof(qlearn_interfaces__srv__SaveQTable_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qlearn_interfaces__srv__SaveQTable_Request));
  bool success = qlearn_interfaces__srv__SaveQTable_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qlearn_interfaces__srv__SaveQTable_Request__destroy(qlearn_interfaces__srv__SaveQTable_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qlearn_interfaces__srv__SaveQTable_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qlearn_interfaces__srv__SaveQTable_Request__Sequence__init(qlearn_interfaces__srv__SaveQTable_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Request * data = NULL;

  if (size) {
    data = (qlearn_interfaces__srv__SaveQTable_Request *)allocator.zero_allocate(size, sizeof(qlearn_interfaces__srv__SaveQTable_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qlearn_interfaces__srv__SaveQTable_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qlearn_interfaces__srv__SaveQTable_Request__fini(&data[i - 1]);
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
qlearn_interfaces__srv__SaveQTable_Request__Sequence__fini(qlearn_interfaces__srv__SaveQTable_Request__Sequence * array)
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
      qlearn_interfaces__srv__SaveQTable_Request__fini(&array->data[i]);
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

qlearn_interfaces__srv__SaveQTable_Request__Sequence *
qlearn_interfaces__srv__SaveQTable_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Request__Sequence * array = (qlearn_interfaces__srv__SaveQTable_Request__Sequence *)allocator.allocate(sizeof(qlearn_interfaces__srv__SaveQTable_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qlearn_interfaces__srv__SaveQTable_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qlearn_interfaces__srv__SaveQTable_Request__Sequence__destroy(qlearn_interfaces__srv__SaveQTable_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qlearn_interfaces__srv__SaveQTable_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qlearn_interfaces__srv__SaveQTable_Request__Sequence__are_equal(const qlearn_interfaces__srv__SaveQTable_Request__Sequence * lhs, const qlearn_interfaces__srv__SaveQTable_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qlearn_interfaces__srv__SaveQTable_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qlearn_interfaces__srv__SaveQTable_Request__Sequence__copy(
  const qlearn_interfaces__srv__SaveQTable_Request__Sequence * input,
  qlearn_interfaces__srv__SaveQTable_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qlearn_interfaces__srv__SaveQTable_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qlearn_interfaces__srv__SaveQTable_Request * data =
      (qlearn_interfaces__srv__SaveQTable_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qlearn_interfaces__srv__SaveQTable_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qlearn_interfaces__srv__SaveQTable_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qlearn_interfaces__srv__SaveQTable_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
qlearn_interfaces__srv__SaveQTable_Response__init(qlearn_interfaces__srv__SaveQTable_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
qlearn_interfaces__srv__SaveQTable_Response__fini(qlearn_interfaces__srv__SaveQTable_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
qlearn_interfaces__srv__SaveQTable_Response__are_equal(const qlearn_interfaces__srv__SaveQTable_Response * lhs, const qlearn_interfaces__srv__SaveQTable_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
qlearn_interfaces__srv__SaveQTable_Response__copy(
  const qlearn_interfaces__srv__SaveQTable_Response * input,
  qlearn_interfaces__srv__SaveQTable_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

qlearn_interfaces__srv__SaveQTable_Response *
qlearn_interfaces__srv__SaveQTable_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Response * msg = (qlearn_interfaces__srv__SaveQTable_Response *)allocator.allocate(sizeof(qlearn_interfaces__srv__SaveQTable_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qlearn_interfaces__srv__SaveQTable_Response));
  bool success = qlearn_interfaces__srv__SaveQTable_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qlearn_interfaces__srv__SaveQTable_Response__destroy(qlearn_interfaces__srv__SaveQTable_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qlearn_interfaces__srv__SaveQTable_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qlearn_interfaces__srv__SaveQTable_Response__Sequence__init(qlearn_interfaces__srv__SaveQTable_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Response * data = NULL;

  if (size) {
    data = (qlearn_interfaces__srv__SaveQTable_Response *)allocator.zero_allocate(size, sizeof(qlearn_interfaces__srv__SaveQTable_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qlearn_interfaces__srv__SaveQTable_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qlearn_interfaces__srv__SaveQTable_Response__fini(&data[i - 1]);
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
qlearn_interfaces__srv__SaveQTable_Response__Sequence__fini(qlearn_interfaces__srv__SaveQTable_Response__Sequence * array)
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
      qlearn_interfaces__srv__SaveQTable_Response__fini(&array->data[i]);
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

qlearn_interfaces__srv__SaveQTable_Response__Sequence *
qlearn_interfaces__srv__SaveQTable_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qlearn_interfaces__srv__SaveQTable_Response__Sequence * array = (qlearn_interfaces__srv__SaveQTable_Response__Sequence *)allocator.allocate(sizeof(qlearn_interfaces__srv__SaveQTable_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qlearn_interfaces__srv__SaveQTable_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qlearn_interfaces__srv__SaveQTable_Response__Sequence__destroy(qlearn_interfaces__srv__SaveQTable_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qlearn_interfaces__srv__SaveQTable_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qlearn_interfaces__srv__SaveQTable_Response__Sequence__are_equal(const qlearn_interfaces__srv__SaveQTable_Response__Sequence * lhs, const qlearn_interfaces__srv__SaveQTable_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qlearn_interfaces__srv__SaveQTable_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qlearn_interfaces__srv__SaveQTable_Response__Sequence__copy(
  const qlearn_interfaces__srv__SaveQTable_Response__Sequence * input,
  qlearn_interfaces__srv__SaveQTable_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qlearn_interfaces__srv__SaveQTable_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qlearn_interfaces__srv__SaveQTable_Response * data =
      (qlearn_interfaces__srv__SaveQTable_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qlearn_interfaces__srv__SaveQTable_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qlearn_interfaces__srv__SaveQTable_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qlearn_interfaces__srv__SaveQTable_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
