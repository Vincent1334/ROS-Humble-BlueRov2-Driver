// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/SetPitch.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_PITCH__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_PITCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/set_pitch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPitch_kd
{
public:
  explicit Init_SetPitch_kd(::bluerov2_interfaces::msg::SetPitch & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::SetPitch kd(::bluerov2_interfaces::msg::SetPitch::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetPitch msg_;
};

class Init_SetPitch_kp
{
public:
  explicit Init_SetPitch_kp(::bluerov2_interfaces::msg::SetPitch & msg)
  : msg_(msg)
  {}
  Init_SetPitch_kd kp(::bluerov2_interfaces::msg::SetPitch::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetPitch_kd(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetPitch msg_;
};

class Init_SetPitch_pwm_max
{
public:
  explicit Init_SetPitch_pwm_max(::bluerov2_interfaces::msg::SetPitch & msg)
  : msg_(msg)
  {}
  Init_SetPitch_kp pwm_max(::bluerov2_interfaces::msg::SetPitch::_pwm_max_type arg)
  {
    msg_.pwm_max = std::move(arg);
    return Init_SetPitch_kp(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetPitch msg_;
};

class Init_SetPitch_enable_pitch_ctrl
{
public:
  Init_SetPitch_enable_pitch_ctrl()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPitch_pwm_max enable_pitch_ctrl(::bluerov2_interfaces::msg::SetPitch::_enable_pitch_ctrl_type arg)
  {
    msg_.enable_pitch_ctrl = std::move(arg);
    return Init_SetPitch_pwm_max(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetPitch msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::SetPitch>()
{
  return bluerov2_interfaces::msg::builder::Init_SetPitch_enable_pitch_ctrl();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_PITCH__BUILDER_HPP_
