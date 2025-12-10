// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/islatutako_argia.hpp"


#ifndef MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__BUILDER_HPP_
#define MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mezuak/msg/detail/islatutako_argia__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mezuak
{

namespace msg
{

namespace builder
{

class Init_IslatutakoArgia_argi_intentsitateak
{
public:
  Init_IslatutakoArgia_argi_intentsitateak()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mezuak::msg::IslatutakoArgia argi_intentsitateak(::mezuak::msg::IslatutakoArgia::_argi_intentsitateak_type arg)
  {
    msg_.argi_intentsitateak = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mezuak::msg::IslatutakoArgia msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mezuak::msg::IslatutakoArgia>()
{
  return mezuak::msg::builder::Init_IslatutakoArgia_argi_intentsitateak();
}

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__BUILDER_HPP_
