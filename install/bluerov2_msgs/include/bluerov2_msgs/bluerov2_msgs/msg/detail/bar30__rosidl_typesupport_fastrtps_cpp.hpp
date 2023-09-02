// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from bluerov2_msgs:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__BAR30__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define BLUEROV2_MSGS__MSG__DETAIL__BAR30__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "bluerov2_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "bluerov2_msgs/msg/detail/bar30__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace bluerov2_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bluerov2_msgs
cdr_serialize(
  const bluerov2_msgs::msg::Bar30 & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bluerov2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bluerov2_msgs::msg::Bar30 & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bluerov2_msgs
get_serialized_size(
  const bluerov2_msgs::msg::Bar30 & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bluerov2_msgs
max_serialized_size_Bar30(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace bluerov2_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bluerov2_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bluerov2_msgs, msg, Bar30)();

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_MSGS__MSG__DETAIL__BAR30__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
