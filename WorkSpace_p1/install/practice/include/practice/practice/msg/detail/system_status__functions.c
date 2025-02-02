// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from practice:msg/SystemStatus.idl
// generated code does not contain a copyright notice
#include "practice/msg/detail/system_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `host_name`
#include "rosidl_runtime_c/string_functions.h"

bool
practice__msg__SystemStatus__init(practice__msg__SystemStatus * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    practice__msg__SystemStatus__fini(msg);
    return false;
  }
  // host_name
  if (!rosidl_runtime_c__String__init(&msg->host_name)) {
    practice__msg__SystemStatus__fini(msg);
    return false;
  }
  // cpu_percent
  // cpu_available
  // memory_percent
  // memory_total
  // memory_available
  // net_sent
  // net_recv
  return true;
}

void
practice__msg__SystemStatus__fini(practice__msg__SystemStatus * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // host_name
  rosidl_runtime_c__String__fini(&msg->host_name);
  // cpu_percent
  // cpu_available
  // memory_percent
  // memory_total
  // memory_available
  // net_sent
  // net_recv
}

bool
practice__msg__SystemStatus__are_equal(const practice__msg__SystemStatus * lhs, const practice__msg__SystemStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // host_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->host_name), &(rhs->host_name)))
  {
    return false;
  }
  // cpu_percent
  if (lhs->cpu_percent != rhs->cpu_percent) {
    return false;
  }
  // cpu_available
  if (lhs->cpu_available != rhs->cpu_available) {
    return false;
  }
  // memory_percent
  if (lhs->memory_percent != rhs->memory_percent) {
    return false;
  }
  // memory_total
  if (lhs->memory_total != rhs->memory_total) {
    return false;
  }
  // memory_available
  if (lhs->memory_available != rhs->memory_available) {
    return false;
  }
  // net_sent
  if (lhs->net_sent != rhs->net_sent) {
    return false;
  }
  // net_recv
  if (lhs->net_recv != rhs->net_recv) {
    return false;
  }
  return true;
}

bool
practice__msg__SystemStatus__copy(
  const practice__msg__SystemStatus * input,
  practice__msg__SystemStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // host_name
  if (!rosidl_runtime_c__String__copy(
      &(input->host_name), &(output->host_name)))
  {
    return false;
  }
  // cpu_percent
  output->cpu_percent = input->cpu_percent;
  // cpu_available
  output->cpu_available = input->cpu_available;
  // memory_percent
  output->memory_percent = input->memory_percent;
  // memory_total
  output->memory_total = input->memory_total;
  // memory_available
  output->memory_available = input->memory_available;
  // net_sent
  output->net_sent = input->net_sent;
  // net_recv
  output->net_recv = input->net_recv;
  return true;
}

practice__msg__SystemStatus *
practice__msg__SystemStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practice__msg__SystemStatus * msg = (practice__msg__SystemStatus *)allocator.allocate(sizeof(practice__msg__SystemStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(practice__msg__SystemStatus));
  bool success = practice__msg__SystemStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
practice__msg__SystemStatus__destroy(practice__msg__SystemStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    practice__msg__SystemStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
practice__msg__SystemStatus__Sequence__init(practice__msg__SystemStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practice__msg__SystemStatus * data = NULL;

  if (size) {
    data = (practice__msg__SystemStatus *)allocator.zero_allocate(size, sizeof(practice__msg__SystemStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = practice__msg__SystemStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        practice__msg__SystemStatus__fini(&data[i - 1]);
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
practice__msg__SystemStatus__Sequence__fini(practice__msg__SystemStatus__Sequence * array)
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
      practice__msg__SystemStatus__fini(&array->data[i]);
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

practice__msg__SystemStatus__Sequence *
practice__msg__SystemStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practice__msg__SystemStatus__Sequence * array = (practice__msg__SystemStatus__Sequence *)allocator.allocate(sizeof(practice__msg__SystemStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = practice__msg__SystemStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
practice__msg__SystemStatus__Sequence__destroy(practice__msg__SystemStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    practice__msg__SystemStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
practice__msg__SystemStatus__Sequence__are_equal(const practice__msg__SystemStatus__Sequence * lhs, const practice__msg__SystemStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!practice__msg__SystemStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
practice__msg__SystemStatus__Sequence__copy(
  const practice__msg__SystemStatus__Sequence * input,
  practice__msg__SystemStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(practice__msg__SystemStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    practice__msg__SystemStatus * data =
      (practice__msg__SystemStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!practice__msg__SystemStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          practice__msg__SystemStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!practice__msg__SystemStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
