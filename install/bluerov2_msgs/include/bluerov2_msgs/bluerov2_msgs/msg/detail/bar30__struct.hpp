// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluerov2_msgs:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__BAR30__STRUCT_HPP_
#define BLUEROV2_MSGS__MSG__DETAIL__BAR30__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluerov2_msgs__msg__Bar30 __attribute__((deprecated))
#else
# define DEPRECATED__bluerov2_msgs__msg__Bar30 __declspec(deprecated)
#endif

namespace bluerov2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Bar30_
{
  using Type = Bar30_<ContainerAllocator>;

  explicit Bar30_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->press_abs = 0.0;
      this->press_diff = 0.0;
      this->temperature = 0;
    }
  }

  explicit Bar30_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->press_abs = 0.0;
      this->press_diff = 0.0;
      this->temperature = 0;
    }
  }

  // field types and members
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _press_abs_type =
    double;
  _press_abs_type press_abs;
  using _press_diff_type =
    double;
  _press_diff_type press_diff;
  using _temperature_type =
    int16_t;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__time_boot_ms(
    const uint32_t & _arg)
  {
    this->time_boot_ms = _arg;
    return *this;
  }
  Type & set__press_abs(
    const double & _arg)
  {
    this->press_abs = _arg;
    return *this;
  }
  Type & set__press_diff(
    const double & _arg)
  {
    this->press_diff = _arg;
    return *this;
  }
  Type & set__temperature(
    const int16_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluerov2_msgs::msg::Bar30_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluerov2_msgs::msg::Bar30_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluerov2_msgs::msg::Bar30_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluerov2_msgs::msg::Bar30_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluerov2_msgs__msg__Bar30
    std::shared_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluerov2_msgs__msg__Bar30
    std::shared_ptr<bluerov2_msgs::msg::Bar30_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bar30_ & other) const
  {
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->press_abs != other.press_abs) {
      return false;
    }
    if (this->press_diff != other.press_diff) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bar30_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bar30_

// alias to use template instance with default allocator
using Bar30 =
  bluerov2_msgs::msg::Bar30_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bluerov2_msgs

#endif  // BLUEROV2_MSGS__MSG__DETAIL__BAR30__STRUCT_HPP_
