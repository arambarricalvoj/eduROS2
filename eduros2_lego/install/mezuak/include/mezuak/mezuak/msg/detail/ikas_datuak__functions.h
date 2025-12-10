// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/ikas_datuak.h"


#ifndef MEZUAK__MSG__DETAIL__IKAS_DATUAK__FUNCTIONS_H_
#define MEZUAK__MSG__DETAIL__IKAS_DATUAK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "mezuak/msg/rosidl_generator_c__visibility_control.h"

#include "mezuak/msg/detail/ikas_datuak__struct.h"

/// Initialize msg/IkasDatuak message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mezuak__msg__IkasDatuak
 * )) before or use
 * mezuak__msg__IkasDatuak__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__init(mezuak__msg__IkasDatuak * msg);

/// Finalize msg/IkasDatuak message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
void
mezuak__msg__IkasDatuak__fini(mezuak__msg__IkasDatuak * msg);

/// Create msg/IkasDatuak message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mezuak__msg__IkasDatuak__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
mezuak__msg__IkasDatuak *
mezuak__msg__IkasDatuak__create(void);

/// Destroy msg/IkasDatuak message.
/**
 * It calls
 * mezuak__msg__IkasDatuak__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
void
mezuak__msg__IkasDatuak__destroy(mezuak__msg__IkasDatuak * msg);

/// Check for msg/IkasDatuak message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__are_equal(const mezuak__msg__IkasDatuak * lhs, const mezuak__msg__IkasDatuak * rhs);

/// Copy a msg/IkasDatuak message.
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
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__copy(
  const mezuak__msg__IkasDatuak * input,
  mezuak__msg__IkasDatuak * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_type_hash_t *
mezuak__msg__IkasDatuak__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_runtime_c__type_description__TypeDescription *
mezuak__msg__IkasDatuak__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_runtime_c__type_description__TypeSource *
mezuak__msg__IkasDatuak__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_runtime_c__type_description__TypeSource__Sequence *
mezuak__msg__IkasDatuak__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/IkasDatuak messages.
/**
 * It allocates the memory for the number of elements and calls
 * mezuak__msg__IkasDatuak__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__Sequence__init(mezuak__msg__IkasDatuak__Sequence * array, size_t size);

/// Finalize array of msg/IkasDatuak messages.
/**
 * It calls
 * mezuak__msg__IkasDatuak__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
void
mezuak__msg__IkasDatuak__Sequence__fini(mezuak__msg__IkasDatuak__Sequence * array);

/// Create array of msg/IkasDatuak messages.
/**
 * It allocates the memory for the array and calls
 * mezuak__msg__IkasDatuak__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
mezuak__msg__IkasDatuak__Sequence *
mezuak__msg__IkasDatuak__Sequence__create(size_t size);

/// Destroy array of msg/IkasDatuak messages.
/**
 * It calls
 * mezuak__msg__IkasDatuak__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
void
mezuak__msg__IkasDatuak__Sequence__destroy(mezuak__msg__IkasDatuak__Sequence * array);

/// Check for msg/IkasDatuak message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__Sequence__are_equal(const mezuak__msg__IkasDatuak__Sequence * lhs, const mezuak__msg__IkasDatuak__Sequence * rhs);

/// Copy an array of msg/IkasDatuak messages.
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
ROSIDL_GENERATOR_C_PUBLIC_mezuak
bool
mezuak__msg__IkasDatuak__Sequence__copy(
  const mezuak__msg__IkasDatuak__Sequence * input,
  mezuak__msg__IkasDatuak__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MEZUAK__MSG__DETAIL__IKAS_DATUAK__FUNCTIONS_H_
