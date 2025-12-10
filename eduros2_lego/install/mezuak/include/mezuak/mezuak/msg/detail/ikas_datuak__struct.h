// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/ikas_datuak.h"


#ifndef MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_H_
#define MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/IkasDatuak in the package mezuak.
/**
  * Neurona-sarea ONLINE ikasteko datuak 
 */
typedef struct mezuak__msg__IkasDatuak
{
  double pos_izq;
  double pos_der;
  double vel_izq;
  double vel_der;
  double yaw;
  double error_traj;
  double delta_v;
  double dist_restante;
  /// hutsik NN ikasteko (soilik RL ikasteko)
  float reward;
  /// hutsik NN ikasteko (soilik RL ikasteko)
  bool done;
} mezuak__msg__IkasDatuak;

// Struct for a sequence of mezuak__msg__IkasDatuak.
typedef struct mezuak__msg__IkasDatuak__Sequence
{
  mezuak__msg__IkasDatuak * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mezuak__msg__IkasDatuak__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_H_
