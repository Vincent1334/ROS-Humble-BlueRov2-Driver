// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/SetDepth.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_DEPTH__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_DEPTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/set_depth__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetDepth_kd
{
public:
  explicit Init_SetDepth_kd(::bluerov2_interfaces::msg::SetDepth & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::SetDepth kd(::bluerov2_interfaces::msg::SetDepth::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetDepth msg_;
};

class Init_SetDepth_kp
{
public:
  explicit Init_SetDepth_kp(::bluerov2_interfaces::msg::SetDepth & msg)
  : msg_(msg)
  {}
  Init_SetDepth_kd kp(::bluerov2_interfaces::msg::SetDepth::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetDepth_kd(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetDepth msg_;
};

class Init_SetDepth_ki
{
public:
  explicit Init_SetDepth_ki(::bluerov2_interfaces::msg::SetDepth & msg)
  : msg_(msg)
  {}
  Init_SetDepth_kp ki(::bluerov2_interfaces::msg::SetDepth::_ki_type arg)
  {
    msg_.ki = std::move(arg);
    return Init_SetDepth_kp(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetDepth msg_;
};

class Init_SetDepth_pwm_max
{
public:
  explicit Init_SetDepth_pwm_max(::bluerov2_interfaces::msg::SetDepth & msg)
  : msg_(msg)
  {}
  Init_SetDepth_ki pwm_max(::bluerov2_interfaces::msg::SetDepth::_pwm_max_type arg)
  {
    msg_.pwm_max = std::move(arg);
    return Init_SetDepth_ki(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetDepth msg_;
};

class Init_SetDepth_enable_depth_ctrl
{
public:
  Init_SetDepth_enable_depth_ctrl()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDepth_pwm_max enable_depth_ctrl(::bluerov2_interfaces::msg::SetDepth::_enable_depth_ctrl_type arg)
  {
    msg_.enable_depth_ctrl = std::move(arg);
    return Init_SetDepth_pwm_max(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetDepth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::SetDepth>()
{
  return bluerov2_interfaces::msg::builder::Init_SetDepth_enable_depth_ctrl();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_DEPTH__BUILDER_HPP_
