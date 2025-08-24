// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mezuak/msg/detail/mugimendu_kodetzaileak__rosidl_typesupport_introspection_c.h"
#include "mezuak/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__functions.h"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mezuak__msg__MugimenduKodetzaileak__init(message_memory);
}

void mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_fini_function(void * message_memory)
{
  mezuak__msg__MugimenduKodetzaileak__fini(message_memory);
}

size_t mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__size_function__MugimenduKodetzaileak__graduak(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_const_function__MugimenduKodetzaileak__graduak(
  const void * untyped_member, size_t index)
{
  const int8_t * member =
    (const int8_t *)(untyped_member);
  return &member[index];
}

void * mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_function__MugimenduKodetzaileak__graduak(
  void * untyped_member, size_t index)
{
  int8_t * member =
    (int8_t *)(untyped_member);
  return &member[index];
}

void mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__fetch_function__MugimenduKodetzaileak__graduak(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_const_function__MugimenduKodetzaileak__graduak(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__assign_function__MugimenduKodetzaileak__graduak(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_function__MugimenduKodetzaileak__graduak(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_member_array[1] = {
  {
    "graduak",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__MugimenduKodetzaileak, graduak),  // bytes offset in struct
    NULL,  // default value
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__size_function__MugimenduKodetzaileak__graduak,  // size() function pointer
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_const_function__MugimenduKodetzaileak__graduak,  // get_const(index) function pointer
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__get_function__MugimenduKodetzaileak__graduak,  // get(index) function pointer
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__fetch_function__MugimenduKodetzaileak__graduak,  // fetch(index, &value) function pointer
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__assign_function__MugimenduKodetzaileak__graduak,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_members = {
  "mezuak__msg",  // message namespace
  "MugimenduKodetzaileak",  // message name
  1,  // number of fields
  sizeof(mezuak__msg__MugimenduKodetzaileak),
  false,  // has_any_key_member_
  mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_member_array,  // message members
  mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_init_function,  // function to initialize message memory (memory has to be allocated)
  mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_type_support_handle = {
  0,
  &mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_members,
  get_message_typesupport_handle_function,
  &mezuak__msg__MugimenduKodetzaileak__get_type_hash,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mezuak
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mezuak, msg, MugimenduKodetzaileak)() {
  if (!mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_type_support_handle.typesupport_identifier) {
    mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mezuak__msg__MugimenduKodetzaileak__rosidl_typesupport_introspection_c__MugimenduKodetzaileak_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
