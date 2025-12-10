// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

#include "mezuak/msg/detail/ikas_datuak__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_type_hash_t *
mezuak__msg__IkasDatuak__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe3, 0x62, 0x33, 0x27, 0x4f, 0xc4, 0xdb, 0x6b,
      0xe8, 0x16, 0xbc, 0x90, 0x75, 0xa3, 0xd8, 0x15,
      0x25, 0x2d, 0x18, 0x6e, 0x58, 0xaa, 0x9b, 0x30,
      0x20, 0xa8, 0x9c, 0xb6, 0xb2, 0x1e, 0xdb, 0x3c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mezuak__msg__IkasDatuak__TYPE_NAME[] = "mezuak/msg/IkasDatuak";

// Define type names, field names, and default values
static char mezuak__msg__IkasDatuak__FIELD_NAME__pos_izq[] = "pos_izq";
static char mezuak__msg__IkasDatuak__FIELD_NAME__pos_der[] = "pos_der";
static char mezuak__msg__IkasDatuak__FIELD_NAME__vel_izq[] = "vel_izq";
static char mezuak__msg__IkasDatuak__FIELD_NAME__vel_der[] = "vel_der";
static char mezuak__msg__IkasDatuak__FIELD_NAME__yaw[] = "yaw";
static char mezuak__msg__IkasDatuak__FIELD_NAME__error_traj[] = "error_traj";
static char mezuak__msg__IkasDatuak__FIELD_NAME__delta_v[] = "delta_v";
static char mezuak__msg__IkasDatuak__FIELD_NAME__dist_restante[] = "dist_restante";
static char mezuak__msg__IkasDatuak__FIELD_NAME__reward[] = "reward";
static char mezuak__msg__IkasDatuak__FIELD_NAME__done[] = "done";

static rosidl_runtime_c__type_description__Field mezuak__msg__IkasDatuak__FIELDS[] = {
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__pos_izq, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__pos_der, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__vel_izq, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__vel_der, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__error_traj, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__delta_v, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__dist_restante, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__reward, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mezuak__msg__IkasDatuak__FIELD_NAME__done, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mezuak__msg__IkasDatuak__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mezuak__msg__IkasDatuak__TYPE_NAME, 21, 21},
      {mezuak__msg__IkasDatuak__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Neurona-sarea ONLINE ikasteko datuak \n"
  "\n"
  "float64 pos_izq\n"
  "float64 pos_der\n"
  "float64 vel_izq\n"
  "float64 vel_der\n"
  "float64 yaw\n"
  "float64 error_traj\n"
  "float64 delta_v\n"
  "float64 dist_restante\n"
  "float32 reward #hutsik NN ikasteko (soilik RL ikasteko)\n"
  "bool done #hutsik NN ikasteko (soilik RL ikasteko)\n"
  "\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mezuak__msg__IkasDatuak__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mezuak__msg__IkasDatuak__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 283, 283},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mezuak__msg__IkasDatuak__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mezuak__msg__IkasDatuak__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
