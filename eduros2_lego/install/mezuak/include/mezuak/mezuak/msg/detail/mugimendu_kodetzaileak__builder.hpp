// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/mugimendu_kodetzaileak.hpp"


#ifndef MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__BUILDER_HPP_
#define MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mezuak/msg/detail/mugimendu_kodetzaileak__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mezuak
{

namespace msg
{

namespace builder
{

class Init_MugimenduKodetzaileak_abiadurak
{
public:
  explicit Init_MugimenduKodetzaileak_abiadurak(::mezuak::msg::MugimenduKodetzaileak & msg)
  : msg_(msg)
  {}
  ::mezuak::msg::MugimenduKodetzaileak abiadurak(::mezuak::msg::MugimenduKodetzaileak::_abiadurak_type arg)
  {
    msg_.abiadurak = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mezuak::msg::MugimenduKodetzaileak msg_;
};

class Init_MugimenduKodetzaileak_graduak
{
public:
  Init_MugimenduKodetzaileak_graduak()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MugimenduKodetzaileak_abiadurak graduak(::mezuak::msg::MugimenduKodetzaileak::_graduak_type arg)
  {
    msg_.graduak = std::move(arg);
    return Init_MugimenduKodetzaileak_abiadurak(msg_);
  }

private:
  ::mezuak::msg::MugimenduKodetzaileak msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mezuak::msg::MugimenduKodetzaileak>()
{
  return mezuak::msg::builder::Init_MugimenduKodetzaileak_graduak();
}

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__BUILDER_HPP_
