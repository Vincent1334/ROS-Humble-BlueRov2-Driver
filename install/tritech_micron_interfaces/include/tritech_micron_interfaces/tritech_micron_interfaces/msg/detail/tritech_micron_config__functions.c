// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice
#include "tritech_micron_interfaces/msg/detail/tritech_micron_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
tritech_micron_interfaces__msg__TritechMicronConfig__init(tritech_micron_interfaces__msg__TritechMicronConfig * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tritech_micron_interfaces__msg__TritechMicronConfig__fini(msg);
    return false;
  }
  // inverted
  // continuous
  // scanright
  // adc8on
  // gain
  // ad_low
  // ad_high
  // left_limit
  // right_limit
  // range
  // nbins
  // step
  return true;
}

void
tritech_micron_interfaces__msg__TritechMicronConfig__fini(tritech_micron_interfaces__msg__TritechMicronConfig * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // inverted
  // continuous
  // scanright
  // adc8on
  // gain
  // ad_low
  // ad_high
  // left_limit
  // right_limit
  // range
  // nbins
  // step
}

bool
tritech_micron_interfaces__msg__TritechMicronConfig__are_equal(const tritech_micron_interfaces__msg__TritechMicronConfig * lhs, const tritech_micron_interfaces__msg__TritechMicronConfig * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // inverted
  if (lhs->inverted != rhs->inverted) {
    return false;
  }
  // continuous
  if (lhs->continuous != rhs->continuous) {
    return false;
  }
  // scanright
  if (lhs->scanright != rhs->scanright) {
    return false;
  }
  // adc8on
  if (lhs->adc8on != rhs->adc8on) {
    return false;
  }
  // gain
  if (lhs->gain != rhs->gain) {
    return false;
  }
  // ad_low
  if (lhs->ad_low != rhs->ad_low) {
    return false;
  }
  // ad_high
  if (lhs->ad_high != rhs->ad_high) {
    return false;
  }
  // left_limit
  if (lhs->left_limit != rhs->left_limit) {
    return false;
  }
  // right_limit
  if (lhs->right_limit != rhs->right_limit) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // nbins
  if (lhs->nbins != rhs->nbins) {
    return false;
  }
  // step
  if (lhs->step != rhs->step) {
    return false;
  }
  return true;
}

bool
tritech_micron_interfaces__msg__TritechMicronConfig__copy(
  const tritech_micron_interfaces__msg__TritechMicronConfig * input,
  tritech_micron_interfaces__msg__TritechMicronConfig * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // inverted
  output->inverted = input->inverted;
  // continuous
  output->continuous = input->continuous;
  // scanright
  output->scanright = input->scanright;
  // adc8on
  output->adc8on = input->adc8on;
  // gain
  output->gain = input->gain;
  // ad_low
  output->ad_low = input->ad_low;
  // ad_high
  output->ad_high = input->ad_high;
  // left_limit
  output->left_limit = input->left_limit;
  // right_limit
  output->right_limit = input->right_limit;
  // range
  output->range = input->range;
  // nbins
  output->nbins = input->nbins;
  // step
  output->step = input->step;
  return true;
}

tritech_micron_interfaces__msg__TritechMicronConfig *
tritech_micron_interfaces__msg__TritechMicronConfig__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tritech_micron_interfaces__msg__TritechMicronConfig * msg = (tritech_micron_interfaces__msg__TritechMicronConfig *)allocator.allocate(sizeof(tritech_micron_interfaces__msg__TritechMicronConfig), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tritech_micron_interfaces__msg__TritechMicronConfig));
  bool success = tritech_micron_interfaces__msg__TritechMicronConfig__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tritech_micron_interfaces__msg__TritechMicronConfig__destroy(tritech_micron_interfaces__msg__TritechMicronConfig * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tritech_micron_interfaces__msg__TritechMicronConfig__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__init(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tritech_micron_interfaces__msg__TritechMicronConfig * data = NULL;

  if (size) {
    data = (tritech_micron_interfaces__msg__TritechMicronConfig *)allocator.zero_allocate(size, sizeof(tritech_micron_interfaces__msg__TritechMicronConfig), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tritech_micron_interfaces__msg__TritechMicronConfig__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tritech_micron_interfaces__msg__TritechMicronConfig__fini(&data[i - 1]);
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
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__fini(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array)
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
      tritech_micron_interfaces__msg__TritechMicronConfig__fini(&array->data[i]);
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

tritech_micron_interfaces__msg__TritechMicronConfig__Sequence *
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array = (tritech_micron_interfaces__msg__TritechMicronConfig__Sequence *)allocator.allocate(sizeof(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__destroy(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__are_equal(const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * lhs, const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tritech_micron_interfaces__msg__TritechMicronConfig__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__copy(
  const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * input,
  tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tritech_micron_interfaces__msg__TritechMicronConfig);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tritech_micron_interfaces__msg__TritechMicronConfig * data =
      (tritech_micron_interfaces__msg__TritechMicronConfig *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tritech_micron_interfaces__msg__TritechMicronConfig__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tritech_micron_interfaces__msg__TritechMicronConfig__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tritech_micron_interfaces__msg__TritechMicronConfig__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
