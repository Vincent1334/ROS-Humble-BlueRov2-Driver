// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_interfaces:msg/SetTarget.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_interfaces__msg__SetTarget __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_interfaces__msg__SetTarget __declspec(deprecated)
#endif

namespace bluerov2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetTarget_
{
  using Type = SetTarget_<ContainerAllocator>;

  explicit SetTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth_desired = 0.0;
      this->roll_desired = 0.0;
      this->pitch_desired = 0.0;
      this->yaw_desired = 0.0;
    }
  }

  explicit SetTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth_desired = 0.0;
      this->roll_desired = 0.0;
      this->pitch_desired = 0.0;
      this->yaw_desired = 0.0;
    }
  }

  // field types and members
  using _depth_desired_type =
    double;
  _depth_desired_type depth_desired;
  using _roll_desired_type =
    double;
  _roll_desired_type roll_desired;
  using _pitch_desired_type =
    double;
  _pitch_desired_type pitch_desired;
  using _yaw_desired_type =
    double;
  _yaw_desired_type yaw_desired;

  // setters for named parameter idiom
  Type & set__depth_desired(
    const double & _arg)
  {
    this->depth_desired = _arg;
    return *this;
  }
  Type & set__roll_desired(
    const double & _arg)
  {
    this->roll_desired = _arg;
    return *this;
  }
  Type & set__pitch_desired(
    const double & _arg)
  {
    this->pitch_desired = _arg;
    return *this;
  }
  Type & set__yaw_desired(
    const double & _arg)
  {
    this->yaw_desired = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_interfaces__msg__SetTarget
    std::shared_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_interfaces__msg__SetTarget
    std::shared_ptr<bluerov2_interfaces::msg::SetTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetTarget_ & other) const
  {
    if (this->depth_desired != other.depth_desired) {
      return false;
    }
    if (this->roll_desired != other.roll_desired) {
      return false;
    }
    if (this->pitch_desired != other.pitch_desired) {
      return false;
    }
    if (this->yaw_desired != other.yaw_desired) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetTarget_

// alias to use template instance with default allocator
using SetTarget =
  bluerov2_interfaces::msg::SetTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__STRUCT_HPP_
