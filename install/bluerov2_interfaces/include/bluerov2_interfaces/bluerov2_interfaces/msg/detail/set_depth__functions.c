// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bluerov2_interfaces:msg/SetDepth.idl
// generated code does not contain a copyright notice
#include "bluerov2_interfaces/msg/detail/set_depth__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
bluerov2_interfaces__msg__SetDepth__init(bluerov2_interfaces__msg__SetDepth * msg)
{
  if (!msg) {
    return false;
  }
  // enable_depth_ctrl
  msg->enable_depth_ctrl = false;
  // pwm_max
  msg->pwm_max = 1900;
  // ki
  msg->ki = 100ul;
  // kp
  msg->kp = 600ul;
  // kd
  msg->kd = 50ul;
  return true;
}

void
bluerov2_interfaces__msg__SetDepth__fini(bluerov2_interfaces__msg__SetDepth * msg)
{
  if (!msg) {
    return;
  }
  // enable_depth_ctrl
  // pwm_max
  // ki
  // kp
  // kd
}

bool
bluerov2_interfaces__msg__SetDepth__are_equal(const bluerov2_interfaces__msg__SetDepth * lhs, const bluerov2_interfaces__msg__SetDepth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enable_depth_ctrl
  if (lhs->enable_depth_ctrl != rhs->enable_depth_ctrl) {
    return false;
  }
  // pwm_max
  if (lhs->pwm_max != rhs->pwm_max) {
    return false;
  }
  // ki
  if (lhs->ki != rhs->ki) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  return true;
}

bool
bluerov2_interfaces__msg__SetDepth__copy(
  const bluerov2_interfaces__msg__SetDepth * input,
  bluerov2_interfaces__msg__SetDepth * output)
{
  if (!input || !output) {
    return false;
  }
  // enable_depth_ctrl
  output->enable_depth_ctrl = input->enable_depth_ctrl;
  // pwm_max
  output->pwm_max = input->pwm_max;
  // ki
  output->ki = input->ki;
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  return true;
}

bluerov2_interfaces__msg__SetDepth *
bluerov2_interfaces__msg__SetDepth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetDepth * msg = (bluerov2_interfaces__msg__SetDepth *)allocator.allocate(sizeof(bluerov2_interfaces__msg__SetDepth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluerov2_interfaces__msg__SetDepth));
  bool success = bluerov2_interfaces__msg__SetDepth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluerov2_interfaces__msg__SetDepth__destroy(bluerov2_interfaces__msg__SetDepth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluerov2_interfaces__msg__SetDepth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluerov2_interfaces__msg__SetDepth__Sequence__init(bluerov2_interfaces__msg__SetDepth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetDepth * data = NULL;

  if (size) {
    data = (bluerov2_interfaces__msg__SetDepth *)allocator.zero_allocate(size, sizeof(bluerov2_interfaces__msg__SetDepth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluerov2_interfaces__msg__SetDepth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluerov2_interfaces__msg__SetDepth__fini(&data[i - 1]);
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
bluerov2_interfaces__msg__SetDepth__Sequence__fini(bluerov2_interfaces__msg__SetDepth__Sequence * array)
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
      bluerov2_interfaces__msg__SetDepth__fini(&array->data[i]);
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

bluerov2_interfaces__msg__SetDepth__Sequence *
bluerov2_interfaces__msg__SetDepth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetDepth__Sequence * array = (bluerov2_interfaces__msg__SetDepth__Sequence *)allocator.allocate(sizeof(bluerov2_interfaces__msg__SetDepth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluerov2_interfaces__msg__SetDepth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluerov2_interfaces__msg__SetDepth__Sequence__destroy(bluerov2_interfaces__msg__SetDepth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluerov2_interfaces__msg__SetDepth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluerov2_interfaces__msg__SetDepth__Sequence__are_equal(const bluerov2_interfaces__msg__SetDepth__Sequence * lhs, const bluerov2_interfaces__msg__SetDepth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluerov2_interfaces__msg__SetDepth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluerov2_interfaces__msg__SetDepth__Sequence__copy(
  const bluerov2_interfaces__msg__SetDepth__Sequence * input,
  bluerov2_interfaces__msg__SetDepth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluerov2_interfaces__msg__SetDepth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bluerov2_interfaces__msg__SetDepth * data =
      (bluerov2_interfaces__msg__SetDepth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluerov2_interfaces__msg__SetDepth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bluerov2_interfaces__msg__SetDepth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluerov2_interfaces__msg__SetDepth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
