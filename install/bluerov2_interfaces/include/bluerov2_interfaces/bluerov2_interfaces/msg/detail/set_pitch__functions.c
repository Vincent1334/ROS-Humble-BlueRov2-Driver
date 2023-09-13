// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bluerov2_interfaces:msg/SetPitch.idl
// generated code does not contain a copyright notice
#include "bluerov2_interfaces/msg/detail/set_pitch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
bluerov2_interfaces__msg__SetPitch__init(bluerov2_interfaces__msg__SetPitch * msg)
{
  if (!msg) {
    return false;
  }
  // enable_pitch_ctrl
  // pwm_max
  // kp
  // kd
  return true;
}

void
bluerov2_interfaces__msg__SetPitch__fini(bluerov2_interfaces__msg__SetPitch * msg)
{
  if (!msg) {
    return;
  }
  // enable_pitch_ctrl
  // pwm_max
  // kp
  // kd
}

bool
bluerov2_interfaces__msg__SetPitch__are_equal(const bluerov2_interfaces__msg__SetPitch * lhs, const bluerov2_interfaces__msg__SetPitch * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enable_pitch_ctrl
  if (lhs->enable_pitch_ctrl != rhs->enable_pitch_ctrl) {
    return false;
  }
  // pwm_max
  if (lhs->pwm_max != rhs->pwm_max) {
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
bluerov2_interfaces__msg__SetPitch__copy(
  const bluerov2_interfaces__msg__SetPitch * input,
  bluerov2_interfaces__msg__SetPitch * output)
{
  if (!input || !output) {
    return false;
  }
  // enable_pitch_ctrl
  output->enable_pitch_ctrl = input->enable_pitch_ctrl;
  // pwm_max
  output->pwm_max = input->pwm_max;
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  return true;
}

bluerov2_interfaces__msg__SetPitch *
bluerov2_interfaces__msg__SetPitch__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetPitch * msg = (bluerov2_interfaces__msg__SetPitch *)allocator.allocate(sizeof(bluerov2_interfaces__msg__SetPitch), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluerov2_interfaces__msg__SetPitch));
  bool success = bluerov2_interfaces__msg__SetPitch__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluerov2_interfaces__msg__SetPitch__destroy(bluerov2_interfaces__msg__SetPitch * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluerov2_interfaces__msg__SetPitch__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluerov2_interfaces__msg__SetPitch__Sequence__init(bluerov2_interfaces__msg__SetPitch__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetPitch * data = NULL;

  if (size) {
    data = (bluerov2_interfaces__msg__SetPitch *)allocator.zero_allocate(size, sizeof(bluerov2_interfaces__msg__SetPitch), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluerov2_interfaces__msg__SetPitch__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluerov2_interfaces__msg__SetPitch__fini(&data[i - 1]);
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
bluerov2_interfaces__msg__SetPitch__Sequence__fini(bluerov2_interfaces__msg__SetPitch__Sequence * array)
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
      bluerov2_interfaces__msg__SetPitch__fini(&array->data[i]);
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

bluerov2_interfaces__msg__SetPitch__Sequence *
bluerov2_interfaces__msg__SetPitch__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluerov2_interfaces__msg__SetPitch__Sequence * array = (bluerov2_interfaces__msg__SetPitch__Sequence *)allocator.allocate(sizeof(bluerov2_interfaces__msg__SetPitch__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluerov2_interfaces__msg__SetPitch__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluerov2_interfaces__msg__SetPitch__Sequence__destroy(bluerov2_interfaces__msg__SetPitch__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluerov2_interfaces__msg__SetPitch__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluerov2_interfaces__msg__SetPitch__Sequence__are_equal(const bluerov2_interfaces__msg__SetPitch__Sequence * lhs, const bluerov2_interfaces__msg__SetPitch__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluerov2_interfaces__msg__SetPitch__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluerov2_interfaces__msg__SetPitch__Sequence__copy(
  const bluerov2_interfaces__msg__SetPitch__Sequence * input,
  bluerov2_interfaces__msg__SetPitch__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluerov2_interfaces__msg__SetPitch);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bluerov2_interfaces__msg__SetPitch * data =
      (bluerov2_interfaces__msg__SetPitch *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluerov2_interfaces__msg__SetPitch__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bluerov2_interfaces__msg__SetPitch__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluerov2_interfaces__msg__SetPitch__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
