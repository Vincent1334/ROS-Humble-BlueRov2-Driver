// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Status in the package bluerov2_interfaces.
typedef struct bluerov2_interfaces__msg__Status
{
  uint16_t pitch;
  uint16_t roll;
  uint16_t throttle;
  uint16_t yaw;
  uint16_t forward;
  uint16_t lateral;
  uint16_t camera_pan;
  uint16_t camera_tilt;
  uint16_t lights;
} bluerov2_interfaces__msg__Status;

// Struct for a sequence of bluerov2_interfaces__msg__Status.
typedef struct bluerov2_interfaces__msg__Status__Sequence
{
  bluerov2_interfaces__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_interfaces__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
