// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/ikas_datuak.hpp"


#ifndef MEZUAK__MSG__DETAIL__IKAS_DATUAK__BUILDER_HPP_
#define MEZUAK__MSG__DETAIL__IKAS_DATUAK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mezuak/msg/detail/ikas_datuak__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mezuak
{

namespace msg
{

namespace builder
{

class Init_IkasDatuak_done
{
public:
  explicit Init_IkasDatuak_done(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  ::mezuak::msg::IkasDatuak done(::mezuak::msg::IkasDatuak::_done_type arg)
  {
    msg_.done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_reward
{
public:
  explicit Init_IkasDatuak_reward(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_done reward(::mezuak::msg::IkasDatuak::_reward_type arg)
  {
    msg_.reward = std::move(arg);
    return Init_IkasDatuak_done(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_dist_restante
{
public:
  explicit Init_IkasDatuak_dist_restante(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_reward dist_restante(::mezuak::msg::IkasDatuak::_dist_restante_type arg)
  {
    msg_.dist_restante = std::move(arg);
    return Init_IkasDatuak_reward(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_delta_v
{
public:
  explicit Init_IkasDatuak_delta_v(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_dist_restante delta_v(::mezuak::msg::IkasDatuak::_delta_v_type arg)
  {
    msg_.delta_v = std::move(arg);
    return Init_IkasDatuak_dist_restante(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_error_traj
{
public:
  explicit Init_IkasDatuak_error_traj(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_delta_v error_traj(::mezuak::msg::IkasDatuak::_error_traj_type arg)
  {
    msg_.error_traj = std::move(arg);
    return Init_IkasDatuak_delta_v(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_yaw
{
public:
  explicit Init_IkasDatuak_yaw(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_error_traj yaw(::mezuak::msg::IkasDatuak::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_IkasDatuak_error_traj(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_vel_der
{
public:
  explicit Init_IkasDatuak_vel_der(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_yaw vel_der(::mezuak::msg::IkasDatuak::_vel_der_type arg)
  {
    msg_.vel_der = std::move(arg);
    return Init_IkasDatuak_yaw(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_vel_izq
{
public:
  explicit Init_IkasDatuak_vel_izq(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_vel_der vel_izq(::mezuak::msg::IkasDatuak::_vel_izq_type arg)
  {
    msg_.vel_izq = std::move(arg);
    return Init_IkasDatuak_vel_der(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_pos_der
{
public:
  explicit Init_IkasDatuak_pos_der(::mezuak::msg::IkasDatuak & msg)
  : msg_(msg)
  {}
  Init_IkasDatuak_vel_izq pos_der(::mezuak::msg::IkasDatuak::_pos_der_type arg)
  {
    msg_.pos_der = std::move(arg);
    return Init_IkasDatuak_vel_izq(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

class Init_IkasDatuak_pos_izq
{
public:
  Init_IkasDatuak_pos_izq()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IkasDatuak_pos_der pos_izq(::mezuak::msg::IkasDatuak::_pos_izq_type arg)
  {
    msg_.pos_izq = std::move(arg);
    return Init_IkasDatuak_pos_der(msg_);
  }

private:
  ::mezuak::msg::IkasDatuak msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mezuak::msg::IkasDatuak>()
{
  return mezuak::msg::builder::Init_IkasDatuak_pos_izq();
}

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__IKAS_DATUAK__BUILDER_HPP_
