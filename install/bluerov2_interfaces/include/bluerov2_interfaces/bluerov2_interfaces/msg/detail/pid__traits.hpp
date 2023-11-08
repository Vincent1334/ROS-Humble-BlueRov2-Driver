// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluerov2_interfaces:msg/PID.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__PID__TRAITS_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__PID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluerov2_interfaces/msg/detail/pid__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluerov2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PID & msg,
  std::ostream & out)
{
  out << "{";
  // member: pwm_max
  {
    out << "pwm_max: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_max, out);
    out << ", ";
  }

  // member: ki
  {
    out << "ki: ";
    rosidl_generator_traits::value_to_yaml(msg.ki, out);
    out << ", ";
  }

  // member: kp
  {
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << ", ";
  }

  // member: kd
  {
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PID & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pwm_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_max: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_max, out);
    out << "\n";
  }

  // member: ki
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ki: ";
    rosidl_generator_traits::value_to_yaml(msg.ki, out);
    out << "\n";
  }

  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << "\n";
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PID & msg, bool use_flow_style = false)
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
  const bluerov2_interfaces::msg::PID & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluerov2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluerov2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const bluerov2_interfaces::msg::PID & msg)
{
  return bluerov2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bluerov2_interfaces::msg::PID>()
{
  return "bluerov2_interfaces::msg::PID";
}

template<>
inline const char * name<bluerov2_interfaces::msg::PID>()
{
  return "bluerov2_interfaces/msg/PID";
}

template<>
struct has_fixed_size<bluerov2_interfaces::msg::PID>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluerov2_interfaces::msg::PID>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluerov2_interfaces::msg::PID>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__PID__TRAITS_HPP_
