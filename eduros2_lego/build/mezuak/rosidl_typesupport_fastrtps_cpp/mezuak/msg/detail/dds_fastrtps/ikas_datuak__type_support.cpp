// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/ikas_datuak__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mezuak/msg/detail/ikas_datuak__functions.h"
#include "mezuak/msg/detail/ikas_datuak__struct.hpp"

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
  const mezuak::msg::IkasDatuak & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pos_izq
  cdr << ros_message.pos_izq;

  // Member: pos_der
  cdr << ros_message.pos_der;

  // Member: vel_izq
  cdr << ros_message.vel_izq;

  // Member: vel_der
  cdr << ros_message.vel_der;

  // Member: yaw
  cdr << ros_message.yaw;

  // Member: error_traj
  cdr << ros_message.error_traj;

  // Member: delta_v
  cdr << ros_message.delta_v;

  // Member: dist_restante
  cdr << ros_message.dist_restante;

  // Member: reward
  cdr << ros_message.reward;

  // Member: done
  cdr << (ros_message.done ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mezuak::msg::IkasDatuak & ros_message)
{
  // Member: pos_izq
  cdr >> ros_message.pos_izq;

  // Member: pos_der
  cdr >> ros_message.pos_der;

  // Member: vel_izq
  cdr >> ros_message.vel_izq;

  // Member: vel_der
  cdr >> ros_message.vel_der;

  // Member: yaw
  cdr >> ros_message.yaw;

  // Member: error_traj
  cdr >> ros_message.error_traj;

  // Member: delta_v
  cdr >> ros_message.delta_v;

  // Member: dist_restante
  cdr >> ros_message.dist_restante;

  // Member: reward
  cdr >> ros_message.reward;

  // Member: done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.done = tmp ? true : false;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
get_serialized_size(
  const mezuak::msg::IkasDatuak & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pos_izq
  {
    size_t item_size = sizeof(ros_message.pos_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pos_der
  {
    size_t item_size = sizeof(ros_message.pos_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: vel_izq
  {
    size_t item_size = sizeof(ros_message.vel_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: vel_der
  {
    size_t item_size = sizeof(ros_message.vel_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw
  {
    size_t item_size = sizeof(ros_message.yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_traj
  {
    size_t item_size = sizeof(ros_message.error_traj);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: delta_v
  {
    size_t item_size = sizeof(ros_message.delta_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: dist_restante
  {
    size_t item_size = sizeof(ros_message.dist_restante);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: reward
  {
    size_t item_size = sizeof(ros_message.reward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: done
  {
    size_t item_size = sizeof(ros_message.done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
max_serialized_size_IkasDatuak(
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

  // Member: pos_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: pos_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: vel_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: vel_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: error_traj
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: delta_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: dist_restante
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: reward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: done
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
    using DataType = mezuak::msg::IkasDatuak;
    is_plain =
      (
      offsetof(DataType, done) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
cdr_serialize_key(
  const mezuak::msg::IkasDatuak & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pos_izq
  cdr << ros_message.pos_izq;

  // Member: pos_der
  cdr << ros_message.pos_der;

  // Member: vel_izq
  cdr << ros_message.vel_izq;

  // Member: vel_der
  cdr << ros_message.vel_der;

  // Member: yaw
  cdr << ros_message.yaw;

  // Member: error_traj
  cdr << ros_message.error_traj;

  // Member: delta_v
  cdr << ros_message.delta_v;

  // Member: dist_restante
  cdr << ros_message.dist_restante;

  // Member: reward
  cdr << ros_message.reward;

  // Member: done
  cdr << (ros_message.done ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
get_serialized_size_key(
  const mezuak::msg::IkasDatuak & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pos_izq
  {
    size_t item_size = sizeof(ros_message.pos_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pos_der
  {
    size_t item_size = sizeof(ros_message.pos_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: vel_izq
  {
    size_t item_size = sizeof(ros_message.vel_izq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: vel_der
  {
    size_t item_size = sizeof(ros_message.vel_der);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw
  {
    size_t item_size = sizeof(ros_message.yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_traj
  {
    size_t item_size = sizeof(ros_message.error_traj);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: delta_v
  {
    size_t item_size = sizeof(ros_message.delta_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: dist_restante
  {
    size_t item_size = sizeof(ros_message.dist_restante);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: reward
  {
    size_t item_size = sizeof(ros_message.reward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: done
  {
    size_t item_size = sizeof(ros_message.done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mezuak
max_serialized_size_key_IkasDatuak(
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

  // Member: pos_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pos_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_izq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_der
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: error_traj
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: delta_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: dist_restante
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: reward
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: done
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
    using DataType = mezuak::msg::IkasDatuak;
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
  auto typed_message =
    static_cast<const mezuak::msg::IkasDatuak *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IkasDatuak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mezuak::msg::IkasDatuak *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IkasDatuak__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mezuak::msg::IkasDatuak *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IkasDatuak__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_IkasDatuak(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _IkasDatuak__callbacks = {
  "mezuak::msg",
  "IkasDatuak",
  _IkasDatuak__cdr_serialize,
  _IkasDatuak__cdr_deserialize,
  _IkasDatuak__get_serialized_size,
  _IkasDatuak__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _IkasDatuak__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IkasDatuak__callbacks,
  get_message_typesupport_handle_function,
  &mezuak__msg__IkasDatuak__get_type_hash,
  &mezuak__msg__IkasDatuak__get_type_description,
  &mezuak__msg__IkasDatuak__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mezuak

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mezuak
const rosidl_message_type_support_t *
get_message_type_support_handle<mezuak::msg::IkasDatuak>()
{
  return &mezuak::msg::typesupport_fastrtps_cpp::_IkasDatuak__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mezuak, msg, IkasDatuak)() {
  return &mezuak::msg::typesupport_fastrtps_cpp::_IkasDatuak__handle;
}

#ifdef __cplusplus
}
#endif
