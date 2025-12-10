// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/mugimendu_kodetzaileak.hpp"


#ifndef MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__TRAITS_HPP_
#define MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mezuak/msg/detail/mugimendu_kodetzaileak__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mezuak
{

namespace msg
{

inline void to_flow_style_yaml(
  const MugimenduKodetzaileak & msg,
  std::ostream & out)
{
  out << "{";
  // member: graduak
  {
    if (msg.graduak.size() == 0) {
      out << "graduak: []";
    } else {
      out << "graduak: [";
      size_t pending_items = msg.graduak.size();
      for (auto item : msg.graduak) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: abiadurak
  {
    if (msg.abiadurak.size() == 0) {
      out << "abiadurak: []";
    } else {
      out << "abiadurak: [";
      size_t pending_items = msg.abiadurak.size();
      for (auto item : msg.abiadurak) {
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
  const MugimenduKodetzaileak & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: graduak
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.graduak.size() == 0) {
      out << "graduak: []\n";
    } else {
      out << "graduak:\n";
      for (auto item : msg.graduak) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: abiadurak
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.abiadurak.size() == 0) {
      out << "abiadurak: []\n";
    } else {
      out << "abiadurak:\n";
      for (auto item : msg.abiadurak) {
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

inline std::string to_yaml(const MugimenduKodetzaileak & msg, bool use_flow_style = false)
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
  const mezuak::msg::MugimenduKodetzaileak & msg,
  std::ostream & out, size_t indentation = 0)
{
  mezuak::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mezuak::msg::to_yaml() instead")]]
inline std::string to_yaml(const mezuak::msg::MugimenduKodetzaileak & msg)
{
  return mezuak::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mezuak::msg::MugimenduKodetzaileak>()
{
  return "mezuak::msg::MugimenduKodetzaileak";
}

template<>
inline const char * name<mezuak::msg::MugimenduKodetzaileak>()
{
  return "mezuak/msg/MugimenduKodetzaileak";
}

template<>
struct has_fixed_size<mezuak::msg::MugimenduKodetzaileak>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mezuak::msg::MugimenduKodetzaileak>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mezuak::msg::MugimenduKodetzaileak>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__TRAITS_HPP_
