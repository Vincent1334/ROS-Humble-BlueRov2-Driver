// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bluerov2_msgs:msg/Bar30.idl
// generated code does not contain a copyright notice
#include "bluerov2_msgs/msg/detail/bar30__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
bluerov2_msgs__msg__Bar30__init(bluerov2_msgs__msg__Bar30 * msg)
{
  if (!msg) {
    return false;
  }
  // time_boot_ms
  // press_abs
  // press_diff
  // temperature
  return true;
}

void
bluerov2_msgs__msg__Bar30__fini(bluerov2_msgs__msg__Bar30 * msg)
{
  if (!msg) {
    return;
  }
  // time_boot_ms
  // press_abs
  // press_diff
  // temperature
}

bool
bluerov2_msgs__msg__Bar30__are_equal(const bluerov2_msgs__msg__Bar30 * lhs, const bluerov2_msgs__msg__Bar30 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_boot_ms
  if (lhs->time_boot_ms != rhs->time_boot_ms) {
    return false;
  }
  // press_abs
  if (lhs->press_abs != rhs->press_abs) {
    return false;
  }
  // press_diff
  if (lhs->press_diff != rhs->press_diff) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  return true;
}

bool
bluerov2_msgs__msg__Bar30__copy(
  const bluerov2_msgs__msg__Bar30 * input,
  bluerov2_msgs__msg__Bar30 * output)
{
  if (!input || !output) {
    return false;
  }
  // time_boot_ms
  output->time_boot_ms = input->time_boot_ms;
  // press_abs
  output->press_abs = input->press_abs;
  // press_diff
  output->press_diff = input->press_diff;
  // temperature
  output->temperature = input->temperature;
  return true;
}

bluerov2_msgs__msg__Bar30 *
bluerov2_msgs__msg__Bar30__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__Bar30 * msg = (bluerov2_msgs__msg__Bar30 *)allocator.allocate(sizeof(bluerov2_msgs__msg__Bar30), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluerov2_msgs__msg__Bar30));
  bool success = bluerov2_msgs__msg__Bar30__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluerov2_msgs__msg__Bar30__destroy(bluerov2_msgs__msg__Bar30 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluerov2_msgs__msg__Bar30__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluerov2_msgs__msg__Bar30__Sequence__init(bluerov2_msgs__msg__Bar30__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__Bar30 * data = NULL;

  if (size) {
    data = (bluerov2_msgs__msg__Bar30 *)allocator.zero_allocate(size, sizeof(bluerov2_msgs__msg__Bar30), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluerov2_msgs__msg__Bar30__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluerov2_msgs__msg__Bar30__fini(&data[i - 1]);
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
bluerov2_msgs__msg__Bar30__Sequence__fini(bluerov2_msgs__msg__Bar30__Sequence * array)
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
      bluerov2_msgs__msg__Bar30__fini(&array->data[i]);
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

bluerov2_msgs__msg__Bar30__Sequence *
bluerov2_msgs__msg__Bar30__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__Bar30__Sequence * array = (bluerov2_msgs__msg__Bar30__Sequence *)allocator.allocate(sizeof(bluerov2_msgs__msg__Bar30__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluerov2_msgs__msg__Bar30__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluerov2_msgs__msg__Bar30__Sequence__destroy(bluerov2_msgs__msg__Bar30__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluerov2_msgs__msg__Bar30__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluerov2_msgs__msg__Bar30__Sequence__are_equal(const bluerov2_msgs__msg__Bar30__Sequence * lhs, const bluerov2_msgs__msg__Bar30__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluerov2_msgs__msg__Bar30__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluerov2_msgs__msg__Bar30__Sequence__copy(
  const bluerov2_msgs__msg__Bar30__Sequence * input,
  bluerov2_msgs__msg__Bar30__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluerov2_msgs__msg__Bar30);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bluerov2_msgs__msg__Bar30 * data =
      (bluerov2_msgs__msg__Bar30 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluerov2_msgs__msg__Bar30__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bluerov2_msgs__msg__Bar30__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluerov2_msgs__msg__Bar30__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
