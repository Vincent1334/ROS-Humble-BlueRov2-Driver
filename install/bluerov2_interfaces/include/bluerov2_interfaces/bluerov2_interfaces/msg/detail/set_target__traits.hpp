// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluerov2_interfaces:msg/SetTarget.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__TRAITS_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluerov2_interfaces/msg/detail/set_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluerov2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: depth_desired
  {
    out << "depth_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_desired, out);
    out << ", ";
  }

  // member: roll_desired
  {
    out << "roll_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_desired, out);
    out << ", ";
  }

  // member: pitch_desired
  {
    out << "pitch_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_desired, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: depth_desired
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_desired, out);
    out << "\n";
  }

  // member: roll_desired
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_desired, out);
    out << "\n";
  }

  // member: pitch_desired
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_desired: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_desired, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetTarget & msg, bool use_flow_style = false)
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
  const bluerov2_interfaces::msg::SetTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluerov2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluerov2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const bluerov2_interfaces::msg::SetTarget & msg)
{
  return bluerov2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bluerov2_interfaces::msg::SetTarget>()
{
  return "bluerov2_interfaces::msg::SetTarget";
}

template<>
inline const char * name<bluerov2_interfaces::msg::SetTarget>()
{
  return "bluerov2_interfaces/msg/SetTarget";
}

template<>
struct has_fixed_size<bluerov2_interfaces::msg::SetTarget>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluerov2_interfaces::msg::SetTarget>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluerov2_interfaces::msg::SetTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__TRAITS_HPP_
