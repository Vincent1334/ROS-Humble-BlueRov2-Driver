// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/bar30__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Bar30_temperature
{
public:
  explicit Init_Bar30_temperature(::bluerov2_interfaces::msg::Bar30 & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::Bar30 temperature(::bluerov2_interfaces::msg::Bar30::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Bar30 msg_;
};

class Init_Bar30_press_diff
{
public:
  explicit Init_Bar30_press_diff(::bluerov2_interfaces::msg::Bar30 & msg)
  : msg_(msg)
  {}
  Init_Bar30_temperature press_diff(::bluerov2_interfaces::msg::Bar30::_press_diff_type arg)
  {
    msg_.press_diff = std::move(arg);
    return Init_Bar30_temperature(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Bar30 msg_;
};

class Init_Bar30_press_abs
{
public:
  explicit Init_Bar30_press_abs(::bluerov2_interfaces::msg::Bar30 & msg)
  : msg_(msg)
  {}
  Init_Bar30_press_diff press_abs(::bluerov2_interfaces::msg::Bar30::_press_abs_type arg)
  {
    msg_.press_abs = std::move(arg);
    return Init_Bar30_press_diff(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Bar30 msg_;
};

class Init_Bar30_time_boot_ms
{
public:
  Init_Bar30_time_boot_ms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bar30_press_abs time_boot_ms(::bluerov2_interfaces::msg::Bar30::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_Bar30_press_abs(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Bar30 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::Bar30>()
{
  return bluerov2_interfaces::msg::builder::Init_Bar30_time_boot_ms();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__BAR30__BUILDER_HPP_
