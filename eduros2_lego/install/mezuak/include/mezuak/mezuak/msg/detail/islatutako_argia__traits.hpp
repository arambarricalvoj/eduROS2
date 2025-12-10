// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/islatutako_argia.hpp"


#ifndef MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__TRAITS_HPP_
#define MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mezuak/msg/detail/islatutako_argia__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mezuak
{

namespace msg
{

inline void to_flow_style_yaml(
  const IslatutakoArgia & msg,
  std::ostream & out)
{
  out << "{";
  // member: argi_intentsitateak
  {
    if (msg.argi_intentsitateak.size() == 0) {
      out << "argi_intentsitateak: []";
    } else {
      out << "argi_intentsitateak: [";
      size_t pending_items = msg.argi_intentsitateak.size();
      for (auto item : msg.argi_intentsitateak) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IslatutakoArgia & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: argi_intentsitateak
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.argi_intentsitateak.size() == 0) {
      out << "argi_intentsitateak: []\n";
    } else {
      out << "argi_intentsitateak:\n";
      for (auto item : msg.argi_intentsitateak) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IslatutakoArgia & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mezuak

namespace rosidl_generator_traits
{

[[deprecated("use mezuak::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mezuak::msg::IslatutakoArgia & msg,
  std::ostream & out, size_t indentation = 0)
{
  mezuak::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mezuak::msg::to_yaml() instead")]]
inline std::string to_yaml(const mezuak::msg::IslatutakoArgia & msg)
{
  return mezuak::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mezuak::msg::IslatutakoArgia>()
{
  return "mezuak::msg::IslatutakoArgia";
}

template<>
inline const char * name<mezuak::msg::IslatutakoArgia>()
{
  return "mezuak/msg/IslatutakoArgia";
}

template<>
struct has_fixed_size<mezuak::msg::IslatutakoArgia>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mezuak::msg::IslatutakoArgia>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mezuak::msg::IslatutakoArgia>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__TRAITS_HPP_
