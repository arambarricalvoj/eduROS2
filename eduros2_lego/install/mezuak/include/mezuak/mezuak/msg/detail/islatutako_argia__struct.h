// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/islatutako_argia.h"


#ifndef MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_H_
#define MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/IslatutakoArgia in the package mezuak.
/**
  * Islatutako argi intentsitatea ehunekotan
  * 0 --> beltza; 1 --> zuria
 */
typedef struct mezuak__msg__IslatutakoArgia
{
  int8_t argi_intentsitateak[2];
} mezuak__msg__IslatutakoArgia;

// Struct for a sequence of mezuak__msg__IslatutakoArgia.
typedef struct mezuak__msg__IslatutakoArgia__Sequence
{
  mezuak__msg__IslatutakoArgia * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mezuak__msg__IslatutakoArgia__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_H_
