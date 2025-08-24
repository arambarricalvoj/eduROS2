// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/mugimendu_kodetzaileak__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mezuak/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__struct.h"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__functions.h"
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


using _MugimenduKodetzaileak__ros_msg_type = mezuak__msg__MugimenduKodetzaileak;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_serialize_mezuak__msg__MugimenduKodetzaileak(
  const mezuak__msg__MugimenduKodetzaileak * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: graduak
  {
    size_t size = 2;
    auto array_ptr = ros_message->graduak;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_deserialize_mezuak__msg__MugimenduKodetzaileak(
  eprosima::fastcdr::Cdr & cdr,
  mezuak__msg__MugimenduKodetzaileak * ros_message)
{
  // Field name: graduak
  {
    size_t size = 2;
    auto array_ptr = ros_message->graduak;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t get_serialized_size_mezuak__msg__MugimenduKodetzaileak(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MugimenduKodetzaileak__ros_msg_type * ros_message = static_cast<const _MugimenduKodetzaileak__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: graduak
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->graduak;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t max_serialized_size_mezuak__msg__MugimenduKodetzaileak(
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

  // Field name: graduak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak__msg__MugimenduKodetzaileak;
    is_plain =
      (
      offsetof(DataType, graduak) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
bool cdr_serialize_key_mezuak__msg__MugimenduKodetzaileak(
  const mezuak__msg__MugimenduKodetzaileak * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: graduak
  {
    size_t size = 2;
    auto array_ptr = ros_message->graduak;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t get_serialized_size_key_mezuak__msg__MugimenduKodetzaileak(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MugimenduKodetzaileak__ros_msg_type * ros_message = static_cast<const _MugimenduKodetzaileak__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: graduak
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->graduak;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mezuak
size_t max_serialized_size_key_mezuak__msg__MugimenduKodetzaileak(
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
  // Field name: graduak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak__msg__MugimenduKodetzaileak;
    is_plain =
      (
      offsetof(DataType, graduak) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _MugimenduKodetzaileak__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const mezuak__msg__MugimenduKodetzaileak * ros_message = static_cast<const mezuak__msg__MugimenduKodetzaileak *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_mezuak__msg__MugimenduKodetzaileak(ros_message, cdr);
}

static bool _MugimenduKodetzaileak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  mezuak__msg__MugimenduKodetzaileak * ros_message = static_cast<mezuak__msg__MugimenduKodetzaileak *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_mezuak__msg__MugimenduKodetzaileak(cdr, ros_message);
}

static uint32_t _MugimenduKodetzaileak__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mezuak__msg__MugimenduKodetzaileak(
      untyped_ros_message, 0));
}

static size_t _MugimenduKodetzaileak__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mezuak__msg__MugimenduKodetzaileak(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MugimenduKodetzaileak = {
  "mezuak::msg",
  "MugimenduKodetzaileak",
  _MugimenduKodetzaileak__cdr_serialize,
  _MugimenduKodetzaileak__cdr_deserialize,
  _MugimenduKodetzaileak__get_serialized_size,
  _MugimenduKodetzaileak__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MugimenduKodetzaileak__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MugimenduKodetzaileak,
  get_message_typesupport_handle_function,
  &mezuak__msg__MugimenduKodetzaileak__get_type_hash,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mezuak, msg, MugimenduKodetzaileak)() {
  return &_MugimenduKodetzaileak__type_support;
}

#if defined(__cplusplus)
}
#endif
