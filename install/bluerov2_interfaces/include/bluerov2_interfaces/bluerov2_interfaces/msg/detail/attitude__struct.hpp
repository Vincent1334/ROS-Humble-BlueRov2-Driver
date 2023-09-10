// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_interfaces__msg__Attitude __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_interfaces__msg__Attitude __declspec(deprecated)
#endif

namespace bluerov2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Attitude_
{
  using Type = Attitude_<ContainerAllocator>;

  explicit Attitude_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->rollspeed = 0.0;
      this->pitchspeed = 0.0;
      this->yawspeed = 0.0;
    }
  }

  explicit Attitude_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->rollspeed = 0.0;
      this->pitchspeed = 0.0;
      this->yawspeed = 0.0;
    }
  }

  // field types and members
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _rollspeed_type =
    double;
  _rollspeed_type rollspeed;
  using _pitchspeed_type =
    double;
  _pitchspeed_type pitchspeed;
  using _yawspeed_type =
    double;
  _yawspeed_type yawspeed;

  // setters for named parameter idiom
  Type & set__time_boot_ms(
    const uint32_t & _arg)
  {
    this->time_boot_ms = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__rollspeed(
    const double & _arg)
  {
    this->rollspeed = _arg;
    return *this;
  }
  Type & set__pitchspeed(
    const double & _arg)
  {
    this->pitchspeed = _arg;
    return *this;
  }
  Type & set__yawspeed(
    const double & _arg)
  {
    this->yawspeed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_interfaces::msg::Attitude_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_interfaces::msg::Attitude_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::Attitude_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::Attitude_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_interfaces__msg__Attitude
    std::shared_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_interfaces__msg__Attitude
    std::shared_ptr<bluerov2_interfaces::msg::Attitude_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Attitude_ & other) const
  {
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->rollspeed != other.rollspeed) {
      return false;
    }
    if (this->pitchspeed != other.pitchspeed) {
      return false;
    }
    if (this->yawspeed != other.yawspeed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Attitude_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Attitude_

// alias to use template instance with default allocator
using Attitude =
  bluerov2_interfaces::msg::Attitude_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_
