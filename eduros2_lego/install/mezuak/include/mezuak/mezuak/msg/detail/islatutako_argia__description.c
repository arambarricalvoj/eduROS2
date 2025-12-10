// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

#include "mezuak/msg/detail/islatutako_argia__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_type_hash_t *
mezuak__msg__IslatutakoArgia__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x60, 0x1d, 0xbc, 0x62, 0xfe, 0x69, 0xe3, 0x8e,
      0xcf, 0x84, 0xf0, 0x2b, 0x5a, 0xbe, 0x44, 0xa2,
      0xa2, 0x7f, 0x51, 0x85, 0x2e, 0xfb, 0xec, 0x64,
      0xae, 0x98, 0x03, 0xf7, 0x71, 0x90, 0x6d, 0xa4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mezuak__msg__IslatutakoArgia__TYPE_NAME[] = "mezuak/msg/IslatutakoArgia";

// Define type names, field names, and default values
static char mezuak__msg__IslatutakoArgia__FIELD_NAME__argi_intentsitateak[] = "argi_intentsitateak";

static rosidl_runtime_c__type_description__Field mezuak__msg__IslatutakoArgia__FIELDS[] = {
  {
    {mezuak__msg__IslatutakoArgia__FIELD_NAME__argi_intentsitateak, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mezuak__msg__IslatutakoArgia__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mezuak__msg__IslatutakoArgia__TYPE_NAME, 26, 26},
      {mezuak__msg__IslatutakoArgia__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Islatutako argi intentsitatea ehunekotan\n"
  "# 0 --> beltza; 1 --> zuria\n"
  "\n"
  "int8[2] argi_intentsitateak";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mezuak__msg__IslatutakoArgia__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mezuak__msg__IslatutakoArgia__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 100, 100},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mezuak__msg__IslatutakoArgia__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mezuak__msg__IslatutakoArgia__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
