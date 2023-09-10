// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bluerov2_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__FUNCTIONS_H_
#define BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bluerov2_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "bluerov2_interfaces/msg/detail/attitude__struct.h"

/// Initialize msg/Attitude message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bluerov2_interfaces__msg__Attitude
 * )) before or use
 * bluerov2_interfaces__msg__Attitude__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__Attitude__init(bluerov2_interfaces__msg__Attitude * msg);

/// Finalize msg/Attitude message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__Attitude__fini(bluerov2_interfaces__msg__Attitude * msg);

/// Create msg/Attitude message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bluerov2_interfaces__msg__Attitude__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bluerov2_interfaces__msg__Attitude *
bluerov2_interfaces__msg__Attitude__create();

/// Destroy msg/Attitude message.
/**
 * It calls
 * bluerov2_interfaces__msg__Attitude__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__Attitude__destroy(bluerov2_interfaces__msg__Attitude * msg);

/// Check for msg/Attitude message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__Attitude__are_equal(const bluerov2_interfaces__msg__Attitude * lhs, const bluerov2_interfaces__msg__Attitude * rhs);

/// Copy a msg/Attitude message.
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
bluerov2_interfaces__msg__Attitude__copy(
  const bluerov2_interfaces__msg__Attitude * input,
  bluerov2_interfaces__msg__Attitude * output);

/// Initialize array of msg/Attitude messages.
/**
 * It allocates the memory for the number of elements and calls
 * bluerov2_interfaces__msg__Attitude__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__Attitude__Sequence__init(bluerov2_interfaces__msg__Attitude__Sequence * array, size_t size);

/// Finalize array of msg/Attitude messages.
/**
 * It calls
 * bluerov2_interfaces__msg__Attitude__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__Attitude__Sequence__fini(bluerov2_interfaces__msg__Attitude__Sequence * array);

/// Create array of msg/Attitude messages.
/**
 * It allocates the memory for the array and calls
 * bluerov2_interfaces__msg__Attitude__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bluerov2_interfaces__msg__Attitude__Sequence *
bluerov2_interfaces__msg__Attitude__Sequence__create(size_t size);

/// Destroy array of msg/Attitude messages.
/**
 * It calls
 * bluerov2_interfaces__msg__Attitude__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
void
bluerov2_interfaces__msg__Attitude__Sequence__destroy(bluerov2_interfaces__msg__Attitude__Sequence * array);

/// Check for msg/Attitude message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_interfaces
bool
bluerov2_interfaces__msg__Attitude__Sequence__are_equal(const bluerov2_interfaces__msg__Attitude__Sequence * lhs, const bluerov2_interfaces__msg__Attitude__Sequence * rhs);

/// Copy an array of msg/Attitude messages.
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
bluerov2_interfaces__msg__Attitude__Sequence__copy(
  const bluerov2_interfaces__msg__Attitude__Sequence * input,
  bluerov2_interfaces__msg__Attitude__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_INTERFACES__MSG__DETAIL__ATTITUDE__FUNCTIONS_H_
