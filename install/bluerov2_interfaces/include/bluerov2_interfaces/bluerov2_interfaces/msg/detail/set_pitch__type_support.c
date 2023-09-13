// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bluerov2_interfaces:msg/SetPitch.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bluerov2_interfaces/msg/detail/set_pitch__rosidl_typesupport_introspection_c.h"
#include "bluerov2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bluerov2_interfaces/msg/detail/set_pitch__functions.h"
#include "bluerov2_interfaces/msg/detail/set_pitch__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bluerov2_interfaces__msg__SetPitch__init(message_memory);
}

void bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_fini_function(void * message_memory)
{
  bluerov2_interfaces__msg__SetPitch__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_member_array[4] = {
  {
    "enable_pitch_ctrl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluerov2_interfaces__msg__SetPitch, enable_pitch_ctrl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pwm_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluerov2_interfaces__msg__SetPitch, pwm_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluerov2_interfaces__msg__SetPitch, kp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluerov2_interfaces__msg__SetPitch, kd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_members = {
  "bluerov2_interfaces__msg",  // message namespace
  "SetPitch",  // message name
  4,  // number of fields
  sizeof(bluerov2_interfaces__msg__SetPitch),
  bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_member_array,  // message members
  bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_init_function,  // function to initialize message memory (memory has to be allocated)
  bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_type_support_handle = {
  0,
  &bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bluerov2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluerov2_interfaces, msg, SetPitch)() {
  if (!bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_type_support_handle.typesupport_identifier) {
    bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &bluerov2_interfaces__msg__SetPitch__rosidl_typesupport_introspection_c__SetPitch_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif