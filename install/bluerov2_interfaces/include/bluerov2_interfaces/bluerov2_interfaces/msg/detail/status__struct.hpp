// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_
#define BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_interfaces__msg__Status __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_interfaces__msg__Status __declspec(deprecated)
#endif

namespace bluerov2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Status_
{
  using Type = Status_<ContainerAllocator>;

  explicit Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch = 0;
      this->roll = 0;
      this->throttle = 0;
      this->yaw = 0;
      this->forward = 0;
      this->lateral = 0;
      this->camera_pan = 0;
      this->camera_tilt = 0;
      this->lights = 0;
    }
  }

  explicit Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch = 0;
      this->roll = 0;
      this->throttle = 0;
      this->yaw = 0;
      this->forward = 0;
      this->lateral = 0;
      this->camera_pan = 0;
      this->camera_tilt = 0;
      this->lights = 0;
    }
  }

  // field types and members
  using _pitch_type =
    uint16_t;
  _pitch_type pitch;
  using _roll_type =
    uint16_t;
  _roll_type roll;
  using _throttle_type =
    uint16_t;
  _throttle_type throttle;
  using _yaw_type =
    uint16_t;
  _yaw_type yaw;
  using _forward_type =
    uint16_t;
  _forward_type forward;
  using _lateral_type =
    uint16_t;
  _lateral_type lateral;
  using _camera_pan_type =
    uint16_t;
  _camera_pan_type camera_pan;
  using _camera_tilt_type =
    uint16_t;
  _camera_tilt_type camera_tilt;
  using _lights_type =
    uint16_t;
  _lights_type lights;

  // setters for named parameter idiom
  Type & set__pitch(
    const uint16_t & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__roll(
    const uint16_t & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__throttle(
    const uint16_t & _arg)
  {
    this->throttle = _arg;
    return *this;
  }
  Type & set__yaw(
    const uint16_t & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__forward(
    const uint16_t & _arg)
  {
    this->forward = _arg;
    return *this;
  }
  Type & set__lateral(
    const uint16_t & _arg)
  {
    this->lateral = _arg;
    return *this;
  }
  Type & set__camera_pan(
    const uint16_t & _arg)
  {
    this->camera_pan = _arg;
    return *this;
  }
  Type & set__camera_tilt(
    const uint16_t & _arg)
  {
    this->camera_tilt = _arg;
    return *this;
  }
  Type & set__lights(
    const uint16_t & _arg)
  {
    this->lights = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_interfaces::msg::Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_interfaces::msg::Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_interfaces::msg::Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_interfaces__msg__Status
    std::shared_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_interfaces__msg__Status
    std::shared_ptr<bluerov2_interfaces::msg::Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_ & other) const
  {
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->throttle != other.throttle) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->forward != other.forward) {
      return false;
    }
    if (this->lateral != other.lateral) {
      return false;
    }
    if (this->camera_pan != other.camera_pan) {
      return false;
    }
    if (this->camera_tilt != other.camera_tilt) {
      return false;
    }
    if (this->lights != other.lights) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_

// alias to use template instance with default allocator
using Status =
  bluerov2_interfaces::msg::Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_interfaces

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_
