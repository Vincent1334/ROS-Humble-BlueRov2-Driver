// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_interfaces:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__STRUCT_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Bar30 in the package bluerov2_interfaces.
typedef struct bluerov2_interfaces__msg__Bar30
{
  uint32_t time_boot_ms;
  double press_abs;
  double press_diff;
  int16_t temperature;
} bluerov2_interfaces__msg__Bar30;

// Struct for a sequence of bluerov2_interfaces__msg__Bar30.
typedef struct bluerov2_interfaces__msg__Bar30__Sequence
{
  bluerov2_interfaces__msg__Bar30 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_interfaces__msg__Bar30__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__STRUCT_H_
