// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tritech_micron_interfaces:msg/TritechMicronConfig.idl
// generated code does not contain a copyright notice

#ifndef TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__FUNCTIONS_H_
#define TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tritech_micron_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tritech_micron_interfaces/msg/detail/tritech_micron_config__struct.h"

/// Initialize msg/TritechMicronConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tritech_micron_interfaces__msg__TritechMicronConfig
 * )) before or use
 * tritech_micron_interfaces__msg__TritechMicronConfig__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__init(tritech_micron_interfaces__msg__TritechMicronConfig * msg);

/// Finalize msg/TritechMicronConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
void
tritech_micron_interfaces__msg__TritechMicronConfig__fini(tritech_micron_interfaces__msg__TritechMicronConfig * msg);

/// Create msg/TritechMicronConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
tritech_micron_interfaces__msg__TritechMicronConfig *
tritech_micron_interfaces__msg__TritechMicronConfig__create();

/// Destroy msg/TritechMicronConfig message.
/**
 * It calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
void
tritech_micron_interfaces__msg__TritechMicronConfig__destroy(tritech_micron_interfaces__msg__TritechMicronConfig * msg);

/// Check for msg/TritechMicronConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__are_equal(const tritech_micron_interfaces__msg__TritechMicronConfig * lhs, const tritech_micron_interfaces__msg__TritechMicronConfig * rhs);

/// Copy a msg/TritechMicronConfig message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__copy(
  const tritech_micron_interfaces__msg__TritechMicronConfig * input,
  tritech_micron_interfaces__msg__TritechMicronConfig * output);

/// Initialize array of msg/TritechMicronConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__init(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array, size_t size);

/// Finalize array of msg/TritechMicronConfig messages.
/**
 * It calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
void
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__fini(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array);

/// Create array of msg/TritechMicronConfig messages.
/**
 * It allocates the memory for the array and calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence *
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__create(size_t size);

/// Destroy array of msg/TritechMicronConfig messages.
/**
 * It calls
 * tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
void
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__destroy(tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * array);

/// Check for msg/TritechMicronConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__are_equal(const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * lhs, const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * rhs);

/// Copy an array of msg/TritechMicronConfig messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tritech_micron_interfaces
bool
tritech_micron_interfaces__msg__TritechMicronConfig__Sequence__copy(
  const tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * input,
  tritech_micron_interfaces__msg__TritechMicronConfig__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TRITECH_MICRON_INTERFACES__MSG__DETAIL__TRITECH_MICRON_CONFIG__FUNCTIONS_H_
