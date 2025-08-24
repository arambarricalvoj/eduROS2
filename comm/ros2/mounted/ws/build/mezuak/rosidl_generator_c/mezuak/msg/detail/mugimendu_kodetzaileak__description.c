// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

#include "mezuak/msg/detail/mugimendu_kodetzaileak__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mezuak
const rosidl_type_hash_t *
mezuak__msg__MugimenduKodetzaileak__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x51, 0x89, 0x5a, 0x97, 0x80, 0xa2, 0xe5, 0xb6,
      0x64, 0x06, 0x7a, 0x81, 0xa9, 0x7b, 0xff, 0x85,
      0xe4, 0x30, 0xde, 0x69, 0xf1, 0xfe, 0x7e, 0x36,
      0x97, 0x40, 0x92, 0x44, 0x27, 0x85, 0xae, 0x4d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mezuak__msg__MugimenduKodetzaileak__TYPE_NAME[] = "mezuak/msg/MugimenduKodetzaileak";

// Define type names, field names, and default values
static char mezuak__msg__MugimenduKodetzaileak__FIELD_NAME__graduak[] = "graduak";

static rosidl_runtime_c__type_description__Field mezuak__msg__MugimenduKodetzaileak__FIELDS[] = {
  {
    {mezuak__msg__MugimenduKodetzaileak__FIELD_NAME__graduak, 7, 7},
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
mezuak__msg__MugimenduKodetzaileak__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mezuak__msg__MugimenduKodetzaileak__TYPE_NAME, 32, 32},
      {mezuak__msg__MugimenduKodetzaileak__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Mugimendu motorren kodetzaileak gradutan\n"
  "# Ezkerretik eskuinera\n"
  "\n"
  "int8[2] graduak";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mezuak__msg__MugimenduKodetzaileak__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mezuak__msg__MugimenduKodetzaileak__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 83, 83},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mezuak__msg__MugimenduKodetzaileak__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mezuak__msg__MugimenduKodetzaileak__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
