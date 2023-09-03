// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bluerov2_interfaces:msg/SetTarget.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__FUNCTIONS_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bluerov2_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "bluerov2_interfaces/msg/detail/set_target__struct.h"

/// Initialize msg/SetTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bluerov2_interfaces__msg__SetTarget
 * )) before or use
 * bluerov2_interfaces__msg__SetTarget__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__init(bluerov2_interfaces__msg__SetTarget * msg);

/// Finalize msg/SetTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__SetTarget__fini(bluerov2_interfaces__msg__SetTarget * msg);

/// Create msg/SetTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bluerov2_interfaces__msg__SetTarget__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bluerov2_interfaces__msg__SetTarget *
bluerov2_interfaces__msg__SetTarget__create();

/// Destroy msg/SetTarget message.
/**
 * It calls
 * bluerov2_interfaces__msg__SetTarget__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__SetTarget__destroy(bluerov2_interfaces__msg__SetTarget * msg);

/// Check for msg/SetTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__are_equal(const bluerov2_interfaces__msg__SetTarget * lhs, const bluerov2_interfaces__msg__SetTarget * rhs);

/// Copy a msg/SetTarget message.
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
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__copy(
  const bluerov2_interfaces__msg__SetTarget * input,
  bluerov2_interfaces__msg__SetTarget * output);

/// Initialize array of msg/SetTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * bluerov2_interfaces__msg__SetTarget__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__Sequence__init(bluerov2_interfaces__msg__SetTarget__Sequence * array, size_t size);

/// Finalize array of msg/SetTarget messages.
/**
 * It calls
 * bluerov2_interfaces__msg__SetTarget__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__SetTarget__Sequence__fini(bluerov2_interfaces__msg__SetTarget__Sequence * array);

/// Create array of msg/SetTarget messages.
/**
 * It allocates the memory for the array and calls
 * bluerov2_interfaces__msg__SetTarget__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bluerov2_interfaces__msg__SetTarget__Sequence *
bluerov2_interfaces__msg__SetTarget__Sequence__create(size_t size);

/// Destroy array of msg/SetTarget messages.
/**
 * It calls
 * bluerov2_interfaces__msg__SetTarget__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__SetTarget__Sequence__destroy(bluerov2_interfaces__msg__SetTarget__Sequence * array);

/// Check for msg/SetTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__Sequence__are_equal(const bluerov2_interfaces__msg__SetTarget__Sequence * lhs, const bluerov2_interfaces__msg__SetTarget__Sequence * rhs);

/// Copy an array of msg/SetTarget messages.
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
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__SetTarget__Sequence__copy(
  const bluerov2_interfaces__msg__SetTarget__Sequence * input,
  bluerov2_interfaces__msg__SetTarget__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__SET_TARGET__FUNCTIONS_H_
