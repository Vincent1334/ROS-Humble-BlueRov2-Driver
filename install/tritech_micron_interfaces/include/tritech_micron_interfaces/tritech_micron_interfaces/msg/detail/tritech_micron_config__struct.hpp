// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice

#ifndef TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_HPP_
#define TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tritech_micron_interfaces__msg__TritechMicronConfig __attribute__((deprecated))
#else
# define DEPRECATED__tritech_micron_interfaces__msg__TritechMicronConfig __declspec(deprecated)
#endif

namespace tritech_micron_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TritechMicronConfig_
{
  using Type = TritechMicronConfig_<ContainerAllocator>;

  explicit TritechMicronConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->inverted = false;
      this->continuous = false;
      this->scanright = false;
      this->adc8on = false;
      this->gain = 0.0;
      this->ad_low = 0.0;
      this->ad_high = 0.0;
      this->left_limit = 0.0;
      this->right_limit = 0.0;
      this->range = 0.0;
      this->nbins = 0;
      this->step = 0.0;
    }
  }

  explicit TritechMicronConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->inverted = false;
      this->continuous = false;
      this->scanright = false;
      this->adc8on = false;
      this->gain = 0.0;
      this->ad_low = 0.0;
      this->ad_high = 0.0;
      this->left_limit = 0.0;
      this->right_limit = 0.0;
      this->range = 0.0;
      this->nbins = 0;
      this->step = 0.0;
    }
  }

  // field types and members
  using _inverted_type =
    bool;
  _inverted_type inverted;
  using _continuous_type =
    bool;
  _continuous_type continuous;
  using _scanright_type =
    bool;
  _scanright_type scanright;
  using _adc8on_type =
    bool;
  _adc8on_type adc8on;
  using _gain_type =
    double;
  _gain_type gain;
  using _ad_low_type =
    double;
  _ad_low_type ad_low;
  using _ad_high_type =
    double;
  _ad_high_type ad_high;
  using _left_limit_type =
    double;
  _left_limit_type left_limit;
  using _right_limit_type =
    double;
  _right_limit_type right_limit;
  using _range_type =
    double;
  _range_type range;
  using _nbins_type =
    int16_t;
  _nbins_type nbins;
  using _step_type =
    double;
  _step_type step;

  // setters for named parameter idiom
  Type & set__inverted(
    const bool & _arg)
  {
    this->inverted = _arg;
    return *this;
  }
  Type & set__continuous(
    const bool & _arg)
  {
    this->continuous = _arg;
    return *this;
  }
  Type & set__scanright(
    const bool & _arg)
  {
    this->scanright = _arg;
    return *this;
  }
  Type & set__adc8on(
    const bool & _arg)
  {
    this->adc8on = _arg;
    return *this;
  }
  Type & set__gain(
    const double & _arg)
  {
    this->gain = _arg;
    return *this;
  }
  Type & set__ad_low(
    const double & _arg)
  {
    this->ad_low = _arg;
    return *this;
  }
  Type & set__ad_high(
    const double & _arg)
  {
    this->ad_high = _arg;
    return *this;
  }
  Type & set__left_limit(
    const double & _arg)
  {
    this->left_limit = _arg;
    return *this;
  }
  Type & set__right_limit(
    const double & _arg)
  {
    this->right_limit = _arg;
    return *this;
  }
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__nbins(
    const int16_t & _arg)
  {
    this->nbins = _arg;
    return *this;
  }
  Type & set__step(
    const double & _arg)
  {
    this->step = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tritech_micron_interfaces__msg__TritechMicronConfig
    std::shared_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tritech_micron_interfaces__msg__TritechMicronConfig
    std::shared_ptr<tritech_micron_interfaces::msg::TritechMicronConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TritechMicronConfig_ & other) const
  {
    if (this->inverted != other.inverted) {
      return false;
    }
    if (this->continuous != other.continuous) {
      return false;
    }
    if (this->scanright != other.scanright) {
      return false;
    }
    if (this->adc8on != other.adc8on) {
      return false;
    }
    if (this->gain != other.gain) {
      return false;
    }
    if (this->ad_low != other.ad_low) {
      return false;
    }
    if (this->ad_high != other.ad_high) {
      return false;
    }
    if (this->left_limit != other.left_limit) {
      return false;
    }
    if (this->right_limit != other.right_limit) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->nbins != other.nbins) {
      return false;
    }
    if (this->step != other.step) {
      return false;
    }
    return true;
  }
  bool operator!=(const TritechMicronConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TritechMicronConfig_

// alias to use template instance with default allocator
using TritechMicronConfig =
  tritech_micron_interfaces::msg::TritechMicronConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tritech_micron_interfaces

#endif  // TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__STRUCT_HPP_
