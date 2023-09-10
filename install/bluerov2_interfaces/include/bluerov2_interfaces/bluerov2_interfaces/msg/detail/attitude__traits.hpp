// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluerov2_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluerov2_interfaces/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluerov2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Attitude & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_boot_ms
  {
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: rollspeed
  {
    out << "rollspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed, out);
    out << ", ";
  }

  // member: pitchspeed
  {
    out << "pitchspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed, out);
    out << ", ";
  }

  // member: yawspeed
  {
    out << "yawspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Attitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time_boot_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
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

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
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

  // member: rollspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rollspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed, out);
    out << "\n";
  }

  // member: pitchspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitchspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed, out);
    out << "\n";
  }

  // member: yawspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yawspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Attitude & msg, bool use_flow_style = false)
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
  const bluerov2_interfaces::msg::Attitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluerov2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluerov2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const bluerov2_interfaces::msg::Attitude & msg)
{
  return bluerov2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bluerov2_interfaces::msg::Attitude>()
{
  return "bluerov2_interfaces::msg::Attitude";
}

template<>
inline const char * name<bluerov2_interfaces::msg::Attitude>()
{
  return "bluerov2_interfaces/msg/Attitude";
}

template<>
struct has_fixed_size<bluerov2_interfaces::msg::Attitude>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluerov2_interfaces::msg::Attitude>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluerov2_interfaces::msg::Attitude>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
