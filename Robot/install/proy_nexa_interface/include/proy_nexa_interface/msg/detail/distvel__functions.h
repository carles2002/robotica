// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from proy_nexa_interface:msg/Distvel.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__FUNCTIONS_H_
#define PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "proy_nexa_interface/msg/rosidl_generator_c__visibility_control.h"

#include "proy_nexa_interface/msg/detail/distvel__struct.h"

/// Initialize msg/Distvel message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * proy_nexa_interface__msg__Distvel
 * )) before or use
 * proy_nexa_interface__msg__Distvel__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__init(proy_nexa_interface__msg__Distvel * msg);

/// Finalize msg/Distvel message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
void
proy_nexa_interface__msg__Distvel__fini(proy_nexa_interface__msg__Distvel * msg);

/// Create msg/Distvel message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * proy_nexa_interface__msg__Distvel__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
proy_nexa_interface__msg__Distvel *
proy_nexa_interface__msg__Distvel__create();

/// Destroy msg/Distvel message.
/**
 * It calls
 * proy_nexa_interface__msg__Distvel__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
void
proy_nexa_interface__msg__Distvel__destroy(proy_nexa_interface__msg__Distvel * msg);

/// Check for msg/Distvel message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__are_equal(const proy_nexa_interface__msg__Distvel * lhs, const proy_nexa_interface__msg__Distvel * rhs);

/// Copy a msg/Distvel message.
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
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__copy(
  const proy_nexa_interface__msg__Distvel * input,
  proy_nexa_interface__msg__Distvel * output);

/// Initialize array of msg/Distvel messages.
/**
 * It allocates the memory for the number of elements and calls
 * proy_nexa_interface__msg__Distvel__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__Sequence__init(proy_nexa_interface__msg__Distvel__Sequence * array, size_t size);

/// Finalize array of msg/Distvel messages.
/**
 * It calls
 * proy_nexa_interface__msg__Distvel__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
void
proy_nexa_interface__msg__Distvel__Sequence__fini(proy_nexa_interface__msg__Distvel__Sequence * array);

/// Create array of msg/Distvel messages.
/**
 * It allocates the memory for the array and calls
 * proy_nexa_interface__msg__Distvel__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
proy_nexa_interface__msg__Distvel__Sequence *
proy_nexa_interface__msg__Distvel__Sequence__create(size_t size);

/// Destroy array of msg/Distvel messages.
/**
 * It calls
 * proy_nexa_interface__msg__Distvel__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
void
proy_nexa_interface__msg__Distvel__Sequence__destroy(proy_nexa_interface__msg__Distvel__Sequence * array);

/// Check for msg/Distvel message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__Sequence__are_equal(const proy_nexa_interface__msg__Distvel__Sequence * lhs, const proy_nexa_interface__msg__Distvel__Sequence * rhs);

/// Copy an array of msg/Distvel messages.
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
ROSIDL_GENERATOR_C_PUBLIC_proy_nexa_interface
bool
proy_nexa_interface__msg__Distvel__Sequence__copy(
  const proy_nexa_interface__msg__Distvel__Sequence * input,
  proy_nexa_interface__msg__Distvel__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__FUNCTIONS_H_
