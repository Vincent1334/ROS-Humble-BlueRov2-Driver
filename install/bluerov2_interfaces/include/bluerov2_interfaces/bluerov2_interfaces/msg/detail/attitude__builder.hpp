// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluerov2_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluerov2_interfaces/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluerov2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Attitude_yawspeed
{
public:
  explicit Init_Attitude_yawspeed(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  ::bluerov2_interfaces::msg::Attitude yawspeed(::bluerov2_interfaces::msg::Attitude::_yawspeed_type arg)
  {
    msg_.yawspeed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_pitchspeed
{
public:
  explicit Init_Attitude_pitchspeed(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yawspeed pitchspeed(::bluerov2_interfaces::msg::Attitude::_pitchspeed_type arg)
  {
    msg_.pitchspeed = std::move(arg);
    return Init_Attitude_yawspeed(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_rollspeed
{
public:
  explicit Init_Attitude_rollspeed(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_pitchspeed rollspeed(::bluerov2_interfaces::msg::Attitude::_rollspeed_type arg)
  {
    msg_.rollspeed = std::move(arg);
    return Init_Attitude_pitchspeed(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_yaw
{
public:
  explicit Init_Attitude_yaw(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_rollspeed yaw(::bluerov2_interfaces::msg::Attitude::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Attitude_rollspeed(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_pitch
{
public:
  explicit Init_Attitude_pitch(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yaw pitch(::bluerov2_interfaces::msg::Attitude::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Attitude_yaw(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_roll
{
public:
  explicit Init_Attitude_roll(::bluerov2_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_pitch roll(::bluerov2_interfaces::msg::Attitude::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Attitude_pitch(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

class Init_Attitude_time_boot_ms
{
public:
  Init_Attitude_time_boot_ms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Attitude_roll time_boot_ms(::bluerov2_interfaces::msg::Attitude::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_Attitude_roll(msg_);
  }

private:
  ::bluerov2_interfaces::msg::Attitude msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluerov2_interfaces::msg::Attitude>()
{
  return bluerov2_interfaces::msg::builder::Init_Attitude_time_boot_ms();
}

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
