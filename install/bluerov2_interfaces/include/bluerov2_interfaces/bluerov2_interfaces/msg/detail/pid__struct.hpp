// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_interfaces:msg/PID.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__PID__STRUCT_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__PID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_interfaces__msg__PID __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_interfaces__msg__PID __declspec(deprecated)
#endif

namespace bluerov2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PID_
{
  using Type = PID_<ContainerAllocator>;

  explicit PID_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->pwm_max = 65535;
      this->ki = 65535;
      this->kp = 65535;
      this->kd = 65535;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->pwm_max = 0;
      this->ki = 0;
      this->kp = 0;
      this->kd = 0;
    }
  }

  explicit PID_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->pwm_max = 65535;
      this->ki = 65535;
      this->kp = 65535;
      this->kd = 65535;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->pwm_max = 0;
      this->ki = 0;
      this->kp = 0;
      this->kd = 0;
    }
  }

  // field types and members
  using _pwm_max_type =
    uint16_t;
  _pwm_max_type pwm_max;
  using _ki_type =
    uint16_t;
  _ki_type ki;
  using _kp_type =
    uint16_t;
  _kp_type kp;
  using _kd_type =
    uint16_t;
  _kd_type kd;

  // setters for named parameter idiom
  Type & set__pwm_max(
    const uint16_t & _arg)
  {
    this->pwm_max = _arg;
    return *this;
  }
  Type & set__ki(
    const uint16_t & _arg)
  {
    this->ki = _arg;
    return *this;
  }
  Type & set__kp(
    const uint16_t & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const uint16_t & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_interfaces::msg::PID_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_interfaces::msg::PID_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::PID_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::PID_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_interfaces__msg__PID
    std::shared_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_interfaces__msg__PID
    std::shared_ptr<bluerov2_interfaces::msg::PID_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PID_ & other) const
  {
    if (this->pwm_max != other.pwm_max) {
      return false;
    }
    if (this->ki != other.ki) {
      return false;
    }
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    return true;
  }
  bool operator!=(const PID_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PID_

// alias to use template instance with default allocator
using PID =
  bluerov2_interfaces::msg::PID_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__PID__STRUCT_HPP_
