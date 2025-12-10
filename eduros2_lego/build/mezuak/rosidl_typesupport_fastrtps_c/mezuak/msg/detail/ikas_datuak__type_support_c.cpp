// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/ikas_datuak__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mezuak/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mezuak/msg/detail/ikas_datuak__struct.h"
#include "mezuak/msg/detail/ikas_datuak__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _IkasDatuak__ros_msg_type = mezuak__msg__IkasDatuak;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_serialize_mezuak__msg__IkasDatuak(
  const mezuak__msg__IkasDatuak * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pos_izq
  {
    cdr << ros_message->pos_izq;
  }

  // Field name: pos_der
  {
    cdr << ros_message->pos_der;
  }

  // Field name: vel_izq
  {
    cdr << ros_message->vel_izq;
  }

  // Field name: vel_der
  {
    cdr << ros_message->vel_der;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: error_traj
  {
    cdr << ros_message->error_traj;
  }

  // Field name: delta_v
  {
    cdr << ros_message->delta_v;
  }

  // Field name: dist_restante
  {
    cdr << ros_message->dist_restante;
  }

  // Field name: reward
  {
    cdr << ros_message->reward;
  }

  // Field name: done
  {
    cdr << (ros_message->done ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_deserialize_mezuak__msg__IkasDatuak(
  eprosima::fastcdr::Cdr & cdr,
  mezuak__msg__IkasDatuak * ros_message)
{
  // Field name: pos_izq
  {
    cdr >> ros_message->pos_izq;
  }

  // Field name: pos_der
  {
    cdr >> ros_message->pos_der;
  }

  // Field name: vel_izq
  {
    cdr >> ros_message->vel_izq;
  }

  // Field name: vel_der
  {
    cdr >> ros_message->vel_der;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  // Field name: error_traj
  {
    cdr >> ros_message->error_traj;
  }

  // Field name: delta_v
  {
    cdr >> ros_message->delta_v;
  }

  // Field name: dist_restante
  {
    cdr >> ros_message->dist_restante;
  }

  // Field name: reward
  {
    cdr >> ros_message->reward;
  }

  // Field name: done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->done = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t get_serialized_size_mezuak__msg__IkasDatuak(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IkasDatuak__ros_msg_type * ros_message = static_cast<const _IkasDatuak__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pos_izq
  {
    size_t item_size = sizeof(ros_message->pos_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pos_der
  {
    size_t item_size = sizeof(ros_message->pos_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_izq
  {
    size_t item_size = sizeof(ros_message->vel_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_der
  {
    size_t item_size = sizeof(ros_message->vel_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: error_traj
  {
    size_t item_size = sizeof(ros_message->error_traj);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delta_v
  {
    size_t item_size = sizeof(ros_message->delta_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dist_restante
  {
    size_t item_size = sizeof(ros_message->dist_restante);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reward
  {
    size_t item_size = sizeof(ros_message->reward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: done
  {
    size_t item_size = sizeof(ros_message->done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t max_serialized_size_mezuak__msg__IkasDatuak(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: pos_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pos_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: error_traj
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: delta_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dist_restante
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: reward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: done
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak__msg__IkasDatuak;
    is_plain =
      (
      offsetof(DataType, done) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_serialize_key_mezuak__msg__IkasDatuak(
  const mezuak__msg__IkasDatuak * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pos_izq
  {
    cdr << ros_message->pos_izq;
  }

  // Field name: pos_der
  {
    cdr << ros_message->pos_der;
  }

  // Field name: vel_izq
  {
    cdr << ros_message->vel_izq;
  }

  // Field name: vel_der
  {
    cdr << ros_message->vel_der;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: error_traj
  {
    cdr << ros_message->error_traj;
  }

  // Field name: delta_v
  {
    cdr << ros_message->delta_v;
  }

  // Field name: dist_restante
  {
    cdr << ros_message->dist_restante;
  }

  // Field name: reward
  {
    cdr << ros_message->reward;
  }

  // Field name: done
  {
    cdr << (ros_message->done ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t get_serialized_size_key_mezuak__msg__IkasDatuak(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IkasDatuak__ros_msg_type * ros_message = static_cast<const _IkasDatuak__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pos_izq
  {
    size_t item_size = sizeof(ros_message->pos_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pos_der
  {
    size_t item_size = sizeof(ros_message->pos_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_izq
  {
    size_t item_size = sizeof(ros_message->vel_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_der
  {
    size_t item_size = sizeof(ros_message->vel_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: error_traj
  {
    size_t item_size = sizeof(ros_message->error_traj);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delta_v
  {
    size_t item_size = sizeof(ros_message->delta_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dist_restante
  {
    size_t item_size = sizeof(ros_message->dist_restante);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reward
  {
    size_t item_size = sizeof(ros_message->reward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: done
  {
    size_t item_size = sizeof(ros_message->done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t max_serialized_size_key_mezuak__msg__IkasDatuak(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: pos_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pos_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: error_traj
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: delta_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dist_restante
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: reward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: done
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak__msg__IkasDatuak;
    is_plain =
      (
      offsetof(DataType, done) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _IkasDatuak__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const mezuak__msg__IkasDatuak * ros_message = static_cast<const mezuak__msg__IkasDatuak *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_mezuak__msg__IkasDatuak(ros_message, cdr);
}

static bool _IkasDatuak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  mezuak__msg__IkasDatuak * ros_message = static_cast<mezuak__msg__IkasDatuak *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_mezuak__msg__IkasDatuak(cdr, ros_message);
}

static uint32_t _IkasDatuak__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mezuak__msg__IkasDatuak(
      untyped_ros_message, 0));
}

static size_t _IkasDatuak__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mezuak__msg__IkasDatuak(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_IkasDatuak = {
  "mezuak::msg",
  "IkasDatuak",
  _IkasDatuak__cdr_serialize,
  _IkasDatuak__cdr_deserialize,
  _IkasDatuak__get_serialized_size,
  _IkasDatuak__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _IkasDatuak__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IkasDatuak,
  get_message_typesupport_handle_function,
  &mezuak__msg__IkasDatuak__get_type_hash,
  &mezuak__msg__IkasDatuak__get_type_description,
  &mezuak__msg__IkasDatuak__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mezuak, msg, IkasDatuak)() {
  return &_IkasDatuak__type_support;
}

#if defined(__cplusplus)
}
#endif
