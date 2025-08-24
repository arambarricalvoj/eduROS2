// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/mugimendu_kodetzaileak.h"


#ifndef MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_H_
#define MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/MugimenduKodetzaileak in the package mezuak.
/**
  * Mugimendu motorren kodetzaileak gradutan
  * Ezkerretik eskuinera
 */
typedef struct mezuak__msg__MugimenduKodetzaileak
{
  int8_t graduak[2];
} mezuak__msg__MugimenduKodetzaileak;

// Struct for a sequence of mezuak__msg__MugimenduKodetzaileak.
typedef struct mezuak__msg__MugimenduKodetzaileak__Sequence
{
  mezuak__msg__MugimenduKodetzaileak * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mezuak__msg__MugimenduKodetzaileak__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_H_
