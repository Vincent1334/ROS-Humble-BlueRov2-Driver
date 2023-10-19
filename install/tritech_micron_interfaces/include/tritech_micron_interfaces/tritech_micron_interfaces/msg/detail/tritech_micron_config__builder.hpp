// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice

#ifndef TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__BUILDER_HPP_
#define TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tritech_micron_interfaces/msg/detail/tritech_micron_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tritech_micron_interfaces
{

namespace msg
{

namespace builder
{

class Init_TritechMicronConfig_step
{
public:
  explicit Init_TritechMicronConfig_step(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  ::tritech_micron_interfaces::msg::TritechMicronConfig step(::tritech_micron_interfaces::msg::TritechMicronConfig::_step_type arg)
  {
    msg_.step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_nbins
{
public:
  explicit Init_TritechMicronConfig_nbins(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_step nbins(::tritech_micron_interfaces::msg::TritechMicronConfig::_nbins_type arg)
  {
    msg_.nbins = std::move(arg);
    return Init_TritechMicronConfig_step(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_range
{
public:
  explicit Init_TritechMicronConfig_range(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_nbins range(::tritech_micron_interfaces::msg::TritechMicronConfig::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_TritechMicronConfig_nbins(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_right_limit
{
public:
  explicit Init_TritechMicronConfig_right_limit(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_range right_limit(::tritech_micron_interfaces::msg::TritechMicronConfig::_right_limit_type arg)
  {
    msg_.right_limit = std::move(arg);
    return Init_TritechMicronConfig_range(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_left_limit
{
public:
  explicit Init_TritechMicronConfig_left_limit(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_right_limit left_limit(::tritech_micron_interfaces::msg::TritechMicronConfig::_left_limit_type arg)
  {
    msg_.left_limit = std::move(arg);
    return Init_TritechMicronConfig_right_limit(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_ad_high
{
public:
  explicit Init_TritechMicronConfig_ad_high(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_left_limit ad_high(::tritech_micron_interfaces::msg::TritechMicronConfig::_ad_high_type arg)
  {
    msg_.ad_high = std::move(arg);
    return Init_TritechMicronConfig_left_limit(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_ad_low
{
public:
  explicit Init_TritechMicronConfig_ad_low(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_ad_high ad_low(::tritech_micron_interfaces::msg::TritechMicronConfig::_ad_low_type arg)
  {
    msg_.ad_low = std::move(arg);
    return Init_TritechMicronConfig_ad_high(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_gain
{
public:
  explicit Init_TritechMicronConfig_gain(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_ad_low gain(::tritech_micron_interfaces::msg::TritechMicronConfig::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return Init_TritechMicronConfig_ad_low(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_adc8on
{
public:
  explicit Init_TritechMicronConfig_adc8on(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_gain adc8on(::tritech_micron_interfaces::msg::TritechMicronConfig::_adc8on_type arg)
  {
    msg_.adc8on = std::move(arg);
    return Init_TritechMicronConfig_gain(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_scanright
{
public:
  explicit Init_TritechMicronConfig_scanright(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_adc8on scanright(::tritech_micron_interfaces::msg::TritechMicronConfig::_scanright_type arg)
  {
    msg_.scanright = std::move(arg);
    return Init_TritechMicronConfig_adc8on(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_continuous
{
public:
  explicit Init_TritechMicronConfig_continuous(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_scanright continuous(::tritech_micron_interfaces::msg::TritechMicronConfig::_continuous_type arg)
  {
    msg_.continuous = std::move(arg);
    return Init_TritechMicronConfig_scanright(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_inverted
{
public:
  explicit Init_TritechMicronConfig_inverted(::tritech_micron_interfaces::msg::TritechMicronConfig & msg)
  : msg_(msg)
  {}
  Init_TritechMicronConfig_continuous inverted(::tritech_micron_interfaces::msg::TritechMicronConfig::_inverted_type arg)
  {
    msg_.inverted = std::move(arg);
    return Init_TritechMicronConfig_continuous(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

class Init_TritechMicronConfig_header
{
public:
  Init_TritechMicronConfig_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TritechMicronConfig_inverted header(::tritech_micron_interfaces::msg::TritechMicronConfig::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TritechMicronConfig_inverted(msg_);
  }

private:
  ::tritech_micron_interfaces::msg::TritechMicronConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tritech_micron_interfaces::msg::TritechMicronConfig>()
{
  return tritech_micron_interfaces::msg::builder::Init_TritechMicronConfig_header();
}

}  // namespace tritech_micron_interfaces

#endif  // TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__BUILDER_HPP_
