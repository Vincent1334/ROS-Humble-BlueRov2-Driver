// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_interfaces:msg/SetRoll.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_interfaces__msg__SetRoll __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_interfaces__msg__SetRoll __declspec(deprecated)
#endif

namespace bluerov2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetRoll_
{
  using Type = SetRoll_<ContainerAllocator>;

  explicit SetRoll_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_roll_ctrl = false;
      this->pwm_max = 0;
      this->kp = 0ul;
      this->kd = 0ul;
    }
  }

  explicit SetRoll_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_roll_ctrl = false;
      this->pwm_max = 0;
      this->kp = 0ul;
      this->kd = 0ul;
    }
  }

  // field types and members
  using _enable_roll_ctrl_type =
    bool;
  _enable_roll_ctrl_type enable_roll_ctrl;
  using _pwm_max_type =
    uint16_t;
  _pwm_max_type pwm_max;
  using _kp_type =
    uint32_t;
  _kp_type kp;
  using _kd_type =
    uint32_t;
  _kd_type kd;

  // setters for named parameter idiom
  Type & set__enable_roll_ctrl(
    const bool & _arg)
  {
    this->enable_roll_ctrl = _arg;
    return *this;
  }
  Type & set__pwm_max(
    const uint16_t & _arg)
  {
    this->pwm_max = _arg;
    return *this;
  }
  Type & set__kp(
    const uint32_t & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const uint32_t & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_interfaces__msg__SetRoll
    std::shared_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_interfaces__msg__SetRoll
    std::shared_ptr<bluerov2_interfaces::msg::SetRoll_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetRoll_ & other) const
  {
    if (this->enable_roll_ctrl != other.enable_roll_ctrl) {
      return false;
    }
    if (this->pwm_max != other.pwm_max) {
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
  bool operator!=(const SetRoll_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetRoll_

// alias to use template instance with default allocator
using SetRoll =
  bluerov2_interfaces::msg::SetRoll_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_ROLL__STRUCT_HPP_
