// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/PID.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__PID__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__PID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/pid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_PID_kd
{
public:
  explicit Init_PID_kd(::bluerov2_interfaces::msg::PID & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::PID kd(::bluerov2_interfaces::msg::PID::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::PID msg_;
};

class Init_PID_kp
{
public:
  explicit Init_PID_kp(::bluerov2_interfaces::msg::PID & msg)
  : msg_(msg)
  {}
  Init_PID_kd kp(::bluerov2_interfaces::msg::PID::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_PID_kd(msg_);
  }

private:
  ::bluerov2_interfaces::msg::PID msg_;
};

class Init_PID_ki
{
public:
  explicit Init_PID_ki(::bluerov2_interfaces::msg::PID & msg)
  : msg_(msg)
  {}
  Init_PID_kp ki(::bluerov2_interfaces::msg::PID::_ki_type arg)
  {
    msg_.ki = std::move(arg);
    return Init_PID_kp(msg_);
  }

private:
  ::bluerov2_interfaces::msg::PID msg_;
};

class Init_PID_pwm_max
{
public:
  Init_PID_pwm_max()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PID_ki pwm_max(::bluerov2_interfaces::msg::PID::_pwm_max_type arg)
  {
    msg_.pwm_max = std::move(arg);
    return Init_PID_ki(msg_);
  }

private:
  ::bluerov2_interfaces::msg::PID msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::PID>()
{
  return bluerov2_interfaces::msg::builder::Init_PID_pwm_max();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__PID__BUILDER_HPP_
