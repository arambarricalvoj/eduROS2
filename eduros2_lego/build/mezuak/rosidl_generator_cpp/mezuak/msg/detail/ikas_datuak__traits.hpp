// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/ikas_datuak.hpp"


#ifndef MEZUAK__MSG__DETAIL__IKAS_DATUAK__TRAITS_HPP_
#define MEZUAK__MSG__DETAIL__IKAS_DATUAK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mezuak/msg/detail/ikas_datuak__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mezuak
{

namespace msg
{

inline void to_flow_style_yaml(
  const IkasDatuak & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos_izq
  {
    out << "pos_izq: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_izq, out);
    out << ", ";
  }

  // member: pos_der
  {
    out << "pos_der: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_der, out);
    out << ", ";
  }

  // member: vel_izq
  {
    out << "vel_izq: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_izq, out);
    out << ", ";
  }

  // member: vel_der
  {
    out << "vel_der: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_der, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: error_traj
  {
    out << "error_traj: ";
    rosidl_generator_traits::value_to_yaml(msg.error_traj, out);
    out << ", ";
  }

  // member: delta_v
  {
    out << "delta_v: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_v, out);
    out << ", ";
  }

  // member: dist_restante
  {
    out << "dist_restante: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_restante, out);
    out << ", ";
  }

  // member: reward
  {
    out << "reward: ";
    rosidl_generator_traits::value_to_yaml(msg.reward, out);
    out << ", ";
  }

  // member: done
  {
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IkasDatuak & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos_izq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_izq: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_izq, out);
    out << "\n";
  }

  // member: pos_der
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_der: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_der, out);
    out << "\n";
  }

  // member: vel_izq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_izq: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_izq, out);
    out << "\n";
  }

  // member: vel_der
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_der: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_der, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: error_traj
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_traj: ";
    rosidl_generator_traits::value_to_yaml(msg.error_traj, out);
    out << "\n";
  }

  // member: delta_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_v: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_v, out);
    out << "\n";
  }

  // member: dist_restante
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_restante: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_restante, out);
    out << "\n";
  }

  // member: reward
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reward: ";
    rosidl_generator_traits::value_to_yaml(msg.reward, out);
    out << "\n";
  }

  // member: done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IkasDatuak & msg, bool use_flow_style = false)
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
  const mezuak::msg::IkasDatuak & msg,
  std::ostream & out, size_t indentation = 0)
{
  mezuak::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mezuak::msg::to_yaml() instead")]]
inline std::string to_yaml(const mezuak::msg::IkasDatuak & msg)
{
  return mezuak::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mezuak::msg::IkasDatuak>()
{
  return "mezuak::msg::IkasDatuak";
}

template<>
inline const char * name<mezuak::msg::IkasDatuak>()
{
  return "mezuak/msg/IkasDatuak";
}

template<>
struct has_fixed_size<mezuak::msg::IkasDatuak>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mezuak::msg::IkasDatuak>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mezuak::msg::IkasDatuak>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MEZUAK__MSG__DETAIL__IKAS_DATUAK__TRAITS_HPP_
