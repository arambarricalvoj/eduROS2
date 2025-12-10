// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mezuak/msg/detail/ikas_datuak__rosidl_typesupport_introspection_c.h"
#include "mezuak/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mezuak/msg/detail/ikas_datuak__functions.h"
#include "mezuak/msg/detail/ikas_datuak__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mezuak__msg__IkasDatuak__init(message_memory);
}

void mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_fini_function(void * message_memory)
{
  mezuak__msg__IkasDatuak__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_member_array[10] = {
  {
    "pos_izq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, pos_izq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_der",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, pos_der),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel_izq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, vel_izq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel_der",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, vel_der),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_traj",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, error_traj),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, delta_v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dist_restante",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, dist_restante),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reward",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, reward),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "done",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mezuak__msg__IkasDatuak, done),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_members = {
  "mezuak__msg",  // message namespace
  "IkasDatuak",  // message name
  10,  // number of fields
  sizeof(mezuak__msg__IkasDatuak),
  false,  // has_any_key_member_
  mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_member_array,  // message members
  mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_init_function,  // function to initialize message memory (memory has to be allocated)
  mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_type_support_handle = {
  0,
  &mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_members,
  get_message_typesupport_handle_function,
  &mezuak__msg__IkasDatuak__get_type_hash,
  &mezuak__msg__IkasDatuak__get_type_description,
  &mezuak__msg__IkasDatuak__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mezuak
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mezuak, msg, IkasDatuak)() {
  if (!mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_type_support_handle.typesupport_identifier) {
    mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mezuak__msg__IkasDatuak__rosidl_typesupport_introspection_c__IkasDatuak_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
