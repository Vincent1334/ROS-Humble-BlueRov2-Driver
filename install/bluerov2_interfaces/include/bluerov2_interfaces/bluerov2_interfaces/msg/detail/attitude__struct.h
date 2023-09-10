// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Attitude in the package bluerov2_interfaces.
typedef struct bluerov2_interfaces__msg__Attitude
{
  uint32_t time_boot_ms;
  double roll;
  double pitch;
  double yaw;
  double rollspeed;
  double pitchspeed;
  double yawspeed;
} bluerov2_interfaces__msg__Attitude;

// Struct for a sequence of bluerov2_interfaces__msg__Attitude.
typedef struct bluerov2_interfaces__msg__Attitude__Sequence
{
  bluerov2_interfaces__msg__Attitude * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_interfaces__msg__Attitude__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_
