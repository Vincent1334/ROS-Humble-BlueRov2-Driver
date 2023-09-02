// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluerov2_msgs:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__BAR30__TRAITS_HPP_
#define BLUEROV2_MSGS__MSG__DETAIL__BAR30__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluerov2_msgs/msg/detail/bar30__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluerov2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Bar30 & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_boot_ms
  {
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
    out << ", ";
  }

  // member: press_abs
  {
    out << "press_abs: ";
    rosidl_generator_traits::value_to_yaml(msg.press_abs, out);
    out << ", ";
  }

  // member: press_diff
  {
    out << "press_diff: ";
    rosidl_generator_traits::value_to_yaml(msg.press_diff, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Bar30 & msg,
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

  // member: press_abs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "press_abs: ";
    rosidl_generator_traits::value_to_yaml(msg.press_abs, out);
    out << "\n";
  }

  // member: press_diff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "press_diff: ";
    rosidl_generator_traits::value_to_yaml(msg.press_diff, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Bar30 & msg, bool use_flow_style = false)
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

}  // namespace bluerov2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use bluerov2_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bluerov2_msgs::msg::Bar30 & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluerov2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluerov2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const bluerov2_msgs::msg::Bar30 & msg)
{
  return bluerov2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bluerov2_msgs::msg::Bar30>()
{
  return "bluerov2_msgs::msg::Bar30";
}

template<>
inline const char * name<bluerov2_msgs::msg::Bar30>()
{
  return "bluerov2_msgs/msg/Bar30";
}

template<>
struct has_fixed_size<bluerov2_msgs::msg::Bar30>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluerov2_msgs::msg::Bar30>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluerov2_msgs::msg::Bar30>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BLUEROV2_MSGS__MSG__DETAIL__BAR30__TRAITS_HPP_
