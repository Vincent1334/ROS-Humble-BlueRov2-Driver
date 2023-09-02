// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bluerov2_msgs:msg/SetTarget.idl
// generated code does not contain a copyright notice
#include "bluerov2_msgs/msg/detail/set_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
bluerov2_msgs__msg__SetTarget__init(bluerov2_msgs__msg__SetTarget * msg)
{
  if (!msg) {
    return false;
  }
  // depth_desired
  // roll_desired
  // pitch_desired
  return true;
}

void
bluerov2_msgs__msg__SetTarget__fini(bluerov2_msgs__msg__SetTarget * msg)
{
  if (!msg) {
    return;
  }
  // depth_desired
  // roll_desired
  // pitch_desired
}

bool
bluerov2_msgs__msg__SetTarget__are_equal(const bluerov2_msgs__msg__SetTarget * lhs, const bluerov2_msgs__msg__SetTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // depth_desired
  if (lhs->depth_desired != rhs->depth_desired) {
    return false;
  }
  // roll_desired
  if (lhs->roll_desired != rhs->roll_desired) {
    return false;
  }
  // pitch_desired
  if (lhs->pitch_desired != rhs->pitch_desired) {
    return false;
  }
  return true;
}

bool
bluerov2_msgs__msg__SetTarget__copy(
  const bluerov2_msgs__msg__SetTarget * input,
  bluerov2_msgs__msg__SetTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // depth_desired
  output->depth_desired = input->depth_desired;
  // roll_desired
  output->roll_desired = input->roll_desired;
  // pitch_desired
  output->pitch_desired = input->pitch_desired;
  return true;
}

bluerov2_msgs__msg__SetTarget *
bluerov2_msgs__msg__SetTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__SetTarget * msg = (bluerov2_msgs__msg__SetTarget *)allocator.allocate(sizeof(bluerov2_msgs__msg__SetTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluerov2_msgs__msg__SetTarget));
  bool success = bluerov2_msgs__msg__SetTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluerov2_msgs__msg__SetTarget__destroy(bluerov2_msgs__msg__SetTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluerov2_msgs__msg__SetTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluerov2_msgs__msg__SetTarget__Sequence__init(bluerov2_msgs__msg__SetTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__SetTarget * data = NULL;

  if (size) {
    data = (bluerov2_msgs__msg__SetTarget *)allocator.zero_allocate(size, sizeof(bluerov2_msgs__msg__SetTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluerov2_msgs__msg__SetTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluerov2_msgs__msg__SetTarget__fini(&data[i - 1]);
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
bluerov2_msgs__msg__SetTarget__Sequence__fini(bluerov2_msgs__msg__SetTarget__Sequence * array)
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
      bluerov2_msgs__msg__SetTarget__fini(&array->data[i]);
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

bluerov2_msgs__msg__SetTarget__Sequence *
bluerov2_msgs__msg__SetTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_msgs__msg__SetTarget__Sequence * array = (bluerov2_msgs__msg__SetTarget__Sequence *)allocator.allocate(sizeof(bluerov2_msgs__msg__SetTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluerov2_msgs__msg__SetTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluerov2_msgs__msg__SetTarget__Sequence__destroy(bluerov2_msgs__msg__SetTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluerov2_msgs__msg__SetTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluerov2_msgs__msg__SetTarget__Sequence__are_equal(const bluerov2_msgs__msg__SetTarget__Sequence * lhs, const bluerov2_msgs__msg__SetTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluerov2_msgs__msg__SetTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluerov2_msgs__msg__SetTarget__Sequence__copy(
  const bluerov2_msgs__msg__SetTarget__Sequence * input,
  bluerov2_msgs__msg__SetTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluerov2_msgs__msg__SetTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bluerov2_msgs__msg__SetTarget * data =
      (bluerov2_msgs__msg__SetTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluerov2_msgs__msg__SetTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bluerov2_msgs__msg__SetTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluerov2_msgs__msg__SetTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
