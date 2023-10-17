// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice

#ifndef TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_H_
#define TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TritechMicronConfig in the package tritech_micron_interfaces.
/**
  * Tritech Micron configuration parameters.
 */
typedef struct tritech_micron_interfaces__msg__TritechMicronConfig
{
  /// Whether the sonar head is facing upwards.
  bool inverted;
  /// Whether the scan is continuous or in sector scan mode.
  bool continuous;
  /// Whether the scan is clockwise.
  bool scanright;
  /// Whether the scan intensity is an 8-bit or 4-bit number.
  bool adc8on;
  /// Initial gain of the sonar pulse. Ranges between 0 and 1.
  double gain;
  /// Mapping of intensity to dB. Ranges from 0 to 80 dB.
  double ad_low;
  double ad_high;
  /// Right and left limit of scan if in sector scan mode. Values are in radians
  /// and range from 0 to 2 pi.
  double left_limit;
  double right_limit;
  /// Range of scan in meters.
  double range;
  /// Number of bins per scan slice.
  int16_t nbins;
  /// Motor step size in radians.
  double step;
} tritech_micron_interfaces__msg__TritechMicronConfig;

// Struct for a sequence of tritech_micron_interfaces__msg__TritechMicronConfig.
typedef struct tritech_micron_interfaces__msg__TritechMicronConfig__Sequence
{
  tritech_micron_interfaces__msg__TritechMicronConfig * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tritech_micron_interfaces__msg__TritechMicronConfig__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_H_
