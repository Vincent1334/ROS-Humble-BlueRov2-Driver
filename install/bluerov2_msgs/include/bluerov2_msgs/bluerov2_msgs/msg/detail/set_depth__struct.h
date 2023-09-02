// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluerov2_msgs:msg/SetDepth.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__SET_DEPTH__STRUCT_H_
#define BLUEROV2_MSGS__MSG__DETAIL__SET_DEPTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SetDepth in the package bluerov2_msgs.
typedef struct bluerov2_msgs__msg__SetDepth
{
  bool enable_depth_ctrl;
  uint16_t pwm_max;
  uint32_t ki;
  uint32_t kp;
  uint32_t kd;
} bluerov2_msgs__msg__SetDepth;

// Struct for a sequence of bluerov2_msgs__msg__SetDepth.
typedef struct bluerov2_msgs__msg__SetDepth__Sequence
{
  bluerov2_msgs__msg__SetDepth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluerov2_msgs__msg__SetDepth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_MSGS__MSG__DETAIL__SET_DEPTH__STRUCT_H_
