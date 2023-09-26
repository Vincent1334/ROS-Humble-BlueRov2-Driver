// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/SetYaw.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_YAW__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_YAW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/set_yaw__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetYaw_kd
{
public:
  explicit Init_SetYaw_kd(::bluerov2_interfaces::msg::SetYaw & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::SetYaw kd(::bluerov2_interfaces::msg::SetYaw::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetYaw msg_;
};

class Init_SetYaw_kp
{
public:
  explicit Init_SetYaw_kp(::bluerov2_interfaces::msg::SetYaw & msg)
  : msg_(msg)
  {}
  Init_SetYaw_kd kp(::bluerov2_interfaces::msg::SetYaw::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetYaw_kd(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetYaw msg_;
};

class Init_SetYaw_pwm_max
{
public:
  explicit Init_SetYaw_pwm_max(::bluerov2_interfaces::msg::SetYaw & msg)
  : msg_(msg)
  {}
  Init_SetYaw_kp pwm_max(::bluerov2_interfaces::msg::SetYaw::_pwm_max_type arg)
  {
    msg_.pwm_max = std::move(arg);
    return Init_SetYaw_kp(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetYaw msg_;
};

class Init_SetYaw_enable_yaw_ctrl
{
public:
  Init_SetYaw_enable_yaw_ctrl()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetYaw_pwm_max enable_yaw_ctrl(::bluerov2_interfaces::msg::SetYaw::_enable_yaw_ctrl_type arg)
  {
    msg_.enable_yaw_ctrl = std::move(arg);
    return Init_SetYaw_pwm_max(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetYaw msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::SetYaw>()
{
  return bluerov2_interfaces::msg::builder::Init_SetYaw_enable_yaw_ctrl();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_YAW__BUILDER_HPP_
