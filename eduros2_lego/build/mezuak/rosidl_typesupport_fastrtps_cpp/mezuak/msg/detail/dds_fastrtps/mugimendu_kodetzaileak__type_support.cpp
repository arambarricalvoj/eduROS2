// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/mugimendu_kodetzaileak__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__functions.h"
#include "mezuak/msg/detail/mugimendu_kodetzaileak__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace mezuak
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
cdr_serialize(
  const mezuak::msg::MugimenduKodetzaileak & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: graduak
  {
    cdr << ros_message.graduak;
  }

  // Member: abiadurak
  {
    cdr << ros_message.abiadurak;
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mezuak::msg::MugimenduKodetzaileak & ros_message)
{
  // Member: graduak
  {
    cdr >> ros_message.graduak;
  }

  // Member: abiadurak
  {
    cdr >> ros_message.abiadurak;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
get_serialized_size(
  const mezuak::msg::MugimenduKodetzaileak & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: graduak
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.graduak[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: abiadurak
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.abiadurak[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
max_serialized_size_MugimenduKodetzaileak(
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

  // Member: graduak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: abiadurak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak::msg::MugimenduKodetzaileak;
    is_plain =
      (
      offsetof(DataType, abiadurak) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
cdr_serialize_key(
  const mezuak::msg::MugimenduKodetzaileak & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: graduak
  {
    cdr << ros_message.graduak;
  }

  // Member: abiadurak
  {
    cdr << ros_message.abiadurak;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
get_serialized_size_key(
  const mezuak::msg::MugimenduKodetzaileak & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: graduak
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.graduak[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: abiadurak
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.abiadurak[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
max_serialized_size_key_MugimenduKodetzaileak(
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

  // Member: graduak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: abiadurak
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mezuak::msg::MugimenduKodetzaileak;
    is_plain =
      (
      offsetof(DataType, abiadurak) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _MugimenduKodetzaileak__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mezuak::msg::MugimenduKodetzaileak *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MugimenduKodetzaileak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mezuak::msg::MugimenduKodetzaileak *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MugimenduKodetzaileak__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mezuak::msg::MugimenduKodetzaileak *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MugimenduKodetzaileak__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MugimenduKodetzaileak(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MugimenduKodetzaileak__callbacks = {
  "mezuak::msg",
  "MugimenduKodetzaileak",
  _MugimenduKodetzaileak__cdr_serialize,
  _MugimenduKodetzaileak__cdr_deserialize,
  _MugimenduKodetzaileak__get_serialized_size,
  _MugimenduKodetzaileak__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MugimenduKodetzaileak__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MugimenduKodetzaileak__callbacks,
  get_message_typesupport_handle_function,
  &mezuak__msg__MugimenduKodetzaileak__get_type_hash,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description,
  &mezuak__msg__MugimenduKodetzaileak__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mezuak

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mezuak
const rosidl_message_type_support_t *
get_message_type_support_handle<mezuak::msg::MugimenduKodetzaileak>()
{
  return &mezuak::msg::typesupport_fastrtps_cpp::_MugimenduKodetzaileak__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mezuak, msg, MugimenduKodetzaileak)() {
  return &mezuak::msg::typesupport_fastrtps_cpp::_MugimenduKodetzaileak__handle;
}

#ifdef __cplusplus
}
#endif
