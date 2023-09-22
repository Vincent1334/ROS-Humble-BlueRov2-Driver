// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluerov2_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluerov2_interfaces/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluerov2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Status & msg,
  std::ostream & out)
{
  out << "{";
  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: throttle
  {
    out << "throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.throttle, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: forward
  {
    out << "forward: ";
    rosidl_generator_traits::value_to_yaml(msg.forward, out);
    out << ", ";
  }

  // member: lateral
  {
    out << "lateral: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral, out);
    out << ", ";
  }

  // member: camera_pan
  {
    out << "camera_pan: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_pan, out);
    out << ", ";
  }

  // member: camera_tilt
  {
    out << "camera_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_tilt, out);
    out << ", ";
  }

  // member: lights
  {
    out << "lights: ";
    rosidl_generator_traits::value_to_yaml(msg.lights, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: throttle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.throttle, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: forward
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "forward: ";
    rosidl_generator_traits::value_to_yaml(msg.forward, out);
    out << "\n";
  }

  // member: lateral
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lateral: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral, out);
    out << "\n";
  }

  // member: camera_pan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_pan: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_pan, out);
    out << "\n";
  }

  // member: camera_tilt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_tilt, out);
    out << "\n";
  }

  // member: lights
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lights: ";
    rosidl_generator_traits::value_to_yaml(msg.lights, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace bluerov2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use bluerov2_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bluerov2_interfaces::msg::Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluerov2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluerov2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const bluerov2_interfaces::msg::Status & msg)
{
  return bluerov2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bluerov2_interfaces::msg::Status>()
{
  return "bluerov2_interfaces::msg::Status";
}

template<>
inline const char * name<bluerov2_interfaces::msg::Status>()
{
  return "bluerov2_interfaces/msg/Status";
}

template<>
struct has_fixed_size<bluerov2_interfaces::msg::Status>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluerov2_interfaces::msg::Status>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluerov2_interfaces::msg::Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_
