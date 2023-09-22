// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Status_lights
{
public:
  explicit Init_Status_lights(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::Status lights(::bluerov2_interfaces::msg::Status::_lights_type arg)
  {
    msg_.lights = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_camera_tilt
{
public:
  explicit Init_Status_camera_tilt(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_lights camera_tilt(::bluerov2_interfaces::msg::Status::_camera_tilt_type arg)
  {
    msg_.camera_tilt = std::move(arg);
    return Init_Status_lights(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_camera_pan
{
public:
  explicit Init_Status_camera_pan(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_camera_tilt camera_pan(::bluerov2_interfaces::msg::Status::_camera_pan_type arg)
  {
    msg_.camera_pan = std::move(arg);
    return Init_Status_camera_tilt(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_lateral
{
public:
  explicit Init_Status_lateral(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_camera_pan lateral(::bluerov2_interfaces::msg::Status::_lateral_type arg)
  {
    msg_.lateral = std::move(arg);
    return Init_Status_camera_pan(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_forward
{
public:
  explicit Init_Status_forward(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_lateral forward(::bluerov2_interfaces::msg::Status::_forward_type arg)
  {
    msg_.forward = std::move(arg);
    return Init_Status_lateral(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_yaw
{
public:
  explicit Init_Status_yaw(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_forward yaw(::bluerov2_interfaces::msg::Status::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Status_forward(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_throttle
{
public:
  explicit Init_Status_throttle(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_yaw throttle(::bluerov2_interfaces::msg::Status::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return Init_Status_yaw(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_roll
{
public:
  explicit Init_Status_roll(::bluerov2_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_throttle roll(::bluerov2_interfaces::msg::Status::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Status_throttle(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

class Init_Status_pitch
{
public:
  Init_Status_pitch()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_roll pitch(::bluerov2_interfaces::msg::Status::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Status_roll(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::Status>()
{
  return bluerov2_interfaces::msg::builder::Init_Status_pitch();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_
