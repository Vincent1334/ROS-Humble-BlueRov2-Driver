// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_msgs:msg/SetTarget.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__SET_TARGET__BUILDER_HPP_
#define BLUEROV2_MSGS__MSG__DETAIL__SET_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_msgs/msg/detail/set_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_msgs
{

namespace msg
{

namespace builder
{

class Init_SetTarget_pitch_desired
{
public:
  explicit Init_SetTarget_pitch_desired(::bluerov2_msgs::msg::SetTarget & msg)
  : msg_(msg)
  {}
  ::bluerov2_msgs::msg::SetTarget pitch_desired(::bluerov2_msgs::msg::SetTarget::_pitch_desired_type arg)
  {
    msg_.pitch_desired = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_msgs::msg::SetTarget msg_;
};

class Init_SetTarget_roll_desired
{
public:
  explicit Init_SetTarget_roll_desired(::bluerov2_msgs::msg::SetTarget & msg)
  : msg_(msg)
  {}
  Init_SetTarget_pitch_desired roll_desired(::bluerov2_msgs::msg::SetTarget::_roll_desired_type arg)
  {
    msg_.roll_desired = std::move(arg);
    return Init_SetTarget_pitch_desired(msg_);
  }

private:
  ::bluerov2_msgs::msg::SetTarget msg_;
};

class Init_SetTarget_depth_desired
{
public:
  Init_SetTarget_depth_desired()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTarget_roll_desired depth_desired(::bluerov2_msgs::msg::SetTarget::_depth_desired_type arg)
  {
    msg_.depth_desired = std::move(arg);
    return Init_SetTarget_roll_desired(msg_);
  }

private:
  ::bluerov2_msgs::msg::SetTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_msgs::msg::SetTarget>()
{
  return bluerov2_msgs::msg::builder::Init_SetTarget_depth_desired();
}

}  // namespace bluerov2_msgs

#endif  // BLUEROV2_MSGS__MSG__DETAIL__SET_TARGET__BUILDER_HPP_
