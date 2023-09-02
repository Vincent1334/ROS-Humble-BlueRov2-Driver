// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bluerov2_msgs:msg/Bar30.idl
// generated code does not contain a copyright notice

#ifndef BLUEROV2_MSGS__MSG__DETAIL__BAR30__FUNCTIONS_H_
#define BLUEROV2_MSGS__MSG__DETAIL__BAR30__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bluerov2_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "bluerov2_msgs/msg/detail/bar30__struct.h"

/// Initialize msg/Bar30 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bluerov2_msgs__msg__Bar30
 * )) before or use
 * bluerov2_msgs__msg__Bar30__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__init(bluerov2_msgs__msg__Bar30 * msg);

/// Finalize msg/Bar30 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
void
bluerov2_msgs__msg__Bar30__fini(bluerov2_msgs__msg__Bar30 * msg);

/// Create msg/Bar30 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bluerov2_msgs__msg__Bar30__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bluerov2_msgs__msg__Bar30 *
bluerov2_msgs__msg__Bar30__create();

/// Destroy msg/Bar30 message.
/**
 * It calls
 * bluerov2_msgs__msg__Bar30__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
void
bluerov2_msgs__msg__Bar30__destroy(bluerov2_msgs__msg__Bar30 * msg);

/// Check for msg/Bar30 message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__are_equal(const bluerov2_msgs__msg__Bar30 * lhs, const bluerov2_msgs__msg__Bar30 * rhs);

/// Copy a msg/Bar30 message.
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
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__copy(
  const bluerov2_msgs__msg__Bar30 * input,
  bluerov2_msgs__msg__Bar30 * output);

/// Initialize array of msg/Bar30 messages.
/**
 * It allocates the memory for the number of elements and calls
 * bluerov2_msgs__msg__Bar30__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__Sequence__init(bluerov2_msgs__msg__Bar30__Sequence * array, size_t size);

/// Finalize array of msg/Bar30 messages.
/**
 * It calls
 * bluerov2_msgs__msg__Bar30__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
void
bluerov2_msgs__msg__Bar30__Sequence__fini(bluerov2_msgs__msg__Bar30__Sequence * array);

/// Create array of msg/Bar30 messages.
/**
 * It allocates the memory for the array and calls
 * bluerov2_msgs__msg__Bar30__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bluerov2_msgs__msg__Bar30__Sequence *
bluerov2_msgs__msg__Bar30__Sequence__create(size_t size);

/// Destroy array of msg/Bar30 messages.
/**
 * It calls
 * bluerov2_msgs__msg__Bar30__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
void
bluerov2_msgs__msg__Bar30__Sequence__destroy(bluerov2_msgs__msg__Bar30__Sequence * array);

/// Check for msg/Bar30 message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__Sequence__are_equal(const bluerov2_msgs__msg__Bar30__Sequence * lhs, const bluerov2_msgs__msg__Bar30__Sequence * rhs);

/// Copy an array of msg/Bar30 messages.
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
ROSIDL_GENERATOR_C_PUBLIC_bluerov2_msgs
bool
bluerov2_msgs__msg__Bar30__Sequence__copy(
  const bluerov2_msgs__msg__Bar30__Sequence * input,
  bluerov2_msgs__msg__Bar30__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BLUEROV2_MSGS__MSG__DETAIL__BAR30__FUNCTIONS_H_
