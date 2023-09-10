// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_interfaces:msg/SetRoll.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SetRoll in the package bluerov2_interfaces.
typedef struct bluerov2_interfaces__msg__SetRoll
{
  bool enable_roll_ctrl;
  uint16_t pwm_max;
  uint32_t kp;
  uint32_t kd;
} bluerov2_interfaces__msg__SetRoll;

// Struct for a sequence of bluerov2_interfaces__msg__SetRoll.
typedef struct bluerov2_interfaces__msg__SetRoll__Sequence
{
  bluerov2_interfaces__msg__SetRoll * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_interfaces__msg__SetRoll__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_H_
