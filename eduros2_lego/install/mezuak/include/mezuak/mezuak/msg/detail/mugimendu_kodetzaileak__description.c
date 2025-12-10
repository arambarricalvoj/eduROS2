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
      0x95, 0xf2, 0xa4, 0xdb, 0x0f, 0x03, 0x26, 0x93,
      0x45, 0x17, 0x79, 0x97, 0x51, 0xf1, 0x7c, 0x31,
      0x3a, 0xb4, 0x82, 0xe1, 0xf2, 0x08, 0x11, 0xb2,
      0x0e, 0x28, 0x77, 0xcb, 0x92, 0x9b, 0x9d, 0x5f,
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
static char mezuak__msg__MugimenduKodetzaileak__FIELD_NAME__abiadurak[] = "abiadurak";

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
  {
    {mezuak__msg__MugimenduKodetzaileak__FIELD_NAME__abiadurak, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16_ARRAY,
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
      {mezuak__msg__MugimenduKodetzaileak__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Mugimendu motorren kodetzaileak: graduak eta abiadurak\n"
  "# Ezkerretik eskuinera\n"
  "\n"
  "int8[2] graduak\n"
  "int16[2] abiadurak";

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
    {toplevel_type_raw_source, 116, 116},
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
