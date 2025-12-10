// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mezuak/msg/detail/islatutako_argia__functions.h"
#include "mezuak/msg/detail/islatutako_argia__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mezuak
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IslatutakoArgia_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mezuak::msg::IslatutakoArgia(_init);
}

void IslatutakoArgia_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mezuak::msg::IslatutakoArgia *>(message_memory);
  typed_message->~IslatutakoArgia();
}

size_t size_function__IslatutakoArgia__argi_intentsitateak(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__IslatutakoArgia__argi_intentsitateak(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__IslatutakoArgia__argi_intentsitateak(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__IslatutakoArgia__argi_intentsitateak(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__IslatutakoArgia__argi_intentsitateak(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__IslatutakoArgia__argi_intentsitateak(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__IslatutakoArgia__argi_intentsitateak(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IslatutakoArgia_message_member_array[1] = {
  {
    "argi_intentsitateak",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(mezuak::msg::IslatutakoArgia, argi_intentsitateak),  // bytes offset in struct
    nullptr,  // default value
    size_function__IslatutakoArgia__argi_intentsitateak,  // size() function pointer
    get_const_function__IslatutakoArgia__argi_intentsitateak,  // get_const(index) function pointer
    get_function__IslatutakoArgia__argi_intentsitateak,  // get(index) function pointer
    fetch_function__IslatutakoArgia__argi_intentsitateak,  // fetch(index, &value) function pointer
    assign_function__IslatutakoArgia__argi_intentsitateak,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IslatutakoArgia_message_members = {
  "mezuak::msg",  // message namespace
  "IslatutakoArgia",  // message name
  1,  // number of fields
  sizeof(mezuak::msg::IslatutakoArgia),
  false,  // has_any_key_member_
  IslatutakoArgia_message_member_array,  // message members
  IslatutakoArgia_init_function,  // function to initialize message memory (memory has to be allocated)
  IslatutakoArgia_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IslatutakoArgia_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IslatutakoArgia_message_members,
  get_message_typesupport_handle_function,
  &mezuak__msg__IslatutakoArgia__get_type_hash,
  &mezuak__msg__IslatutakoArgia__get_type_description,
  &mezuak__msg__IslatutakoArgia__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mezuak


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mezuak::msg::IslatutakoArgia>()
{
  return &::mezuak::msg::rosidl_typesupport_introspection_cpp::IslatutakoArgia_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mezuak, msg, IslatutakoArgia)() {
  return &::mezuak::msg::rosidl_typesupport_introspection_cpp::IslatutakoArgia_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
