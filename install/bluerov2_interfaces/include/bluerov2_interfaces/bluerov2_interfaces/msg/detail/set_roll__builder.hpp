// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/SetRoll.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/set_roll__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetRoll_kd
{
public:
  explicit Init_SetRoll_kd(::bluerov2_interfaces::msg::SetRoll & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::SetRoll kd(::bluerov2_interfaces::msg::SetRoll::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetRoll msg_;
};

class Init_SetRoll_kp
{
public:
  explicit Init_SetRoll_kp(::bluerov2_interfaces::msg::SetRoll & msg)
  : msg_(msg)
  {}
  Init_SetRoll_kd kp(::bluerov2_interfaces::msg::SetRoll::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetRoll_kd(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetRoll msg_;
};

class Init_SetRoll_pwm_max
{
public:
  explicit Init_SetRoll_pwm_max(::bluerov2_interfaces::msg::SetRoll & msg)
  : msg_(msg)
  {}
  Init_SetRoll_kp pwm_max(::bluerov2_interfaces::msg::SetRoll::_pwm_max_type arg)
  {
    msg_.pwm_max = std::move(arg);
    return Init_SetRoll_kp(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetRoll msg_;
};

class Init_SetRoll_enable_roll_ctrl
{
public:
  Init_SetRoll_enable_roll_ctrl()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRoll_pwm_max enable_roll_ctrl(::bluerov2_interfaces::msg::SetRoll::_enable_roll_ctrl_type arg)
  {
    msg_.enable_roll_ctrl = std::move(arg);
    return Init_SetRoll_pwm_max(msg_);
  }

private:
  ::bluerov2_interfaces::msg::SetRoll msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::SetRoll>()
{
  return bluerov2_interfaces::msg::builder::Init_SetRoll_enable_roll_ctrl();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__BUILDER_HPP_
