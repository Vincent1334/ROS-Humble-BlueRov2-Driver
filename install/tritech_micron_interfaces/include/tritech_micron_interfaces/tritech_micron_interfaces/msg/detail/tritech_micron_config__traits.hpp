// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice

#ifndef TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__TRAITS_HPP_
#define TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tritech_micron_interfaces/msg/detail/tritech_micron_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tritech_micron_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TritechMicronConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: inverted
  {
    out << "inverted: ";
    rosidl_generator_traits::value_to_yaml(msg.inverted, out);
    out << ", ";
  }

  // member: continuous
  {
    out << "continuous: ";
    rosidl_generator_traits::value_to_yaml(msg.continuous, out);
    out << ", ";
  }

  // member: scanright
  {
    out << "scanright: ";
    rosidl_generator_traits::value_to_yaml(msg.scanright, out);
    out << ", ";
  }

  // member: adc8on
  {
    out << "adc8on: ";
    rosidl_generator_traits::value_to_yaml(msg.adc8on, out);
    out << ", ";
  }

  // member: gain
  {
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << ", ";
  }

  // member: ad_low
  {
    out << "ad_low: ";
    rosidl_generator_traits::value_to_yaml(msg.ad_low, out);
    out << ", ";
  }

  // member: ad_high
  {
    out << "ad_high: ";
    rosidl_generator_traits::value_to_yaml(msg.ad_high, out);
    out << ", ";
  }

  // member: left_limit
  {
    out << "left_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.left_limit, out);
    out << ", ";
  }

  // member: right_limit
  {
    out << "right_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.right_limit, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: nbins
  {
    out << "nbins: ";
    rosidl_generator_traits::value_to_yaml(msg.nbins, out);
    out << ", ";
  }

  // member: step
  {
    out << "step: ";
    rosidl_generator_traits::value_to_yaml(msg.step, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TritechMicronConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: inverted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inverted: ";
    rosidl_generator_traits::value_to_yaml(msg.inverted, out);
    out << "\n";
  }

  // member: continuous
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "continuous: ";
    rosidl_generator_traits::value_to_yaml(msg.continuous, out);
    out << "\n";
  }

  // member: scanright
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scanright: ";
    rosidl_generator_traits::value_to_yaml(msg.scanright, out);
    out << "\n";
  }

  // member: adc8on
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "adc8on: ";
    rosidl_generator_traits::value_to_yaml(msg.adc8on, out);
    out << "\n";
  }

  // member: gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << "\n";
  }

  // member: ad_low
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ad_low: ";
    rosidl_generator_traits::value_to_yaml(msg.ad_low, out);
    out << "\n";
  }

  // member: ad_high
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ad_high: ";
    rosidl_generator_traits::value_to_yaml(msg.ad_high, out);
    out << "\n";
  }

  // member: left_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.left_limit, out);
    out << "\n";
  }

  // member: right_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.right_limit, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: nbins
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nbins: ";
    rosidl_generator_traits::value_to_yaml(msg.nbins, out);
    out << "\n";
  }

  // member: step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step: ";
    rosidl_generator_traits::value_to_yaml(msg.step, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TritechMicronConfig & msg, bool use_flow_style = false)
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

}  // namespace tritech_micron_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tritech_micron_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tritech_micron_interfaces::msg::TritechMicronConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  tritech_micron_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tritech_micron_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tritech_micron_interfaces::msg::TritechMicronConfig & msg)
{
  return tritech_micron_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tritech_micron_interfaces::msg::TritechMicronConfig>()
{
  return "tritech_micron_interfaces::msg::TritechMicronConfig";
}

template<>
inline const char * name<tritech_micron_interfaces::msg::TritechMicronConfig>()
{
  return "tritech_micron_interfaces/msg/TritechMicronConfig";
}

template<>
struct has_fixed_size<tritech_micron_interfaces::msg::TritechMicronConfig>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tritech_micron_interfaces::msg::TritechMicronConfig>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tritech_micron_interfaces::msg::TritechMicronConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__TRAITS_HPP_
