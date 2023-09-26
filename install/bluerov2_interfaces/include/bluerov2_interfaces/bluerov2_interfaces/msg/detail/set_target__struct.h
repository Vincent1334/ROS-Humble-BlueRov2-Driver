// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_interfaces:msg/SetTarget.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SetTarget in the package bluerov2_interfaces.
typedef struct bluerov2_interfaces__msg__SetTarget
{
  double depth_desired;
  double roll_desired;
  double pitch_desired;
  double yaw_desired;
} bluerov2_interfaces__msg__SetTarget;

// Struct for a sequence of bluerov2_interfaces__msg__SetTarget.
typedef struct bluerov2_interfaces__msg__SetTarget__Sequence
{
  bluerov2_interfaces__msg__SetTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_interfaces__msg__SetTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_H_
