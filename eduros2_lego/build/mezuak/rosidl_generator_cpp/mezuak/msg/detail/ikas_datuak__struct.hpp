// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/ikas_datuak.hpp"


#ifndef MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_HPP_
#define MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mezuak__msg__IkasDatuak __attribute__((deprecated))
#else
# define DEPRECATED__mezuak__msg__IkasDatuak __declspec(deprecated)
#endif

namespace mezuak
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IkasDatuak_
{
  using Type = IkasDatuak_<ContainerAllocator>;

  explicit IkasDatuak_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_izq = 0.0;
      this->pos_der = 0.0;
      this->vel_izq = 0.0;
      this->vel_der = 0.0;
      this->yaw = 0.0;
      this->error_traj = 0.0;
      this->delta_v = 0.0;
      this->dist_restante = 0.0;
      this->reward = 0.0f;
      this->done = false;
    }
  }

  explicit IkasDatuak_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_izq = 0.0;
      this->pos_der = 0.0;
      this->vel_izq = 0.0;
      this->vel_der = 0.0;
      this->yaw = 0.0;
      this->error_traj = 0.0;
      this->delta_v = 0.0;
      this->dist_restante = 0.0;
      this->reward = 0.0f;
      this->done = false;
    }
  }

  // field types and members
  using _pos_izq_type =
    double;
  _pos_izq_type pos_izq;
  using _pos_der_type =
    double;
  _pos_der_type pos_der;
  using _vel_izq_type =
    double;
  _vel_izq_type vel_izq;
  using _vel_der_type =
    double;
  _vel_der_type vel_der;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _error_traj_type =
    double;
  _error_traj_type error_traj;
  using _delta_v_type =
    double;
  _delta_v_type delta_v;
  using _dist_restante_type =
    double;
  _dist_restante_type dist_restante;
  using _reward_type =
    float;
  _reward_type reward;
  using _done_type =
    bool;
  _done_type done;

  // setters for named parameter idiom
  Type & set__pos_izq(
    const double & _arg)
  {
    this->pos_izq = _arg;
    return *this;
  }
  Type & set__pos_der(
    const double & _arg)
  {
    this->pos_der = _arg;
    return *this;
  }
  Type & set__vel_izq(
    const double & _arg)
  {
    this->vel_izq = _arg;
    return *this;
  }
  Type & set__vel_der(
    const double & _arg)
  {
    this->vel_der = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__error_traj(
    const double & _arg)
  {
    this->error_traj = _arg;
    return *this;
  }
  Type & set__delta_v(
    const double & _arg)
  {
    this->delta_v = _arg;
    return *this;
  }
  Type & set__dist_restante(
    const double & _arg)
  {
    this->dist_restante = _arg;
    return *this;
  }
  Type & set__reward(
    const float & _arg)
  {
    this->reward = _arg;
    return *this;
  }
  Type & set__done(
    const bool & _arg)
  {
    this->done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mezuak::msg::IkasDatuak_<ContainerAllocator> *;
  using ConstRawPtr =
    const mezuak::msg::IkasDatuak_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::IkasDatuak_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::IkasDatuak_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mezuak__msg__IkasDatuak
    std::shared_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mezuak__msg__IkasDatuak
    std::shared_ptr<mezuak::msg::IkasDatuak_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IkasDatuak_ & other) const
  {
    if (this->pos_izq != other.pos_izq) {
      return false;
    }
    if (this->pos_der != other.pos_der) {
      return false;
    }
    if (this->vel_izq != other.vel_izq) {
      return false;
    }
    if (this->vel_der != other.vel_der) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->error_traj != other.error_traj) {
      return false;
    }
    if (this->delta_v != other.delta_v) {
      return false;
    }
    if (this->dist_restante != other.dist_restante) {
      return false;
    }
    if (this->reward != other.reward) {
      return false;
    }
    if (this->done != other.done) {
      return false;
    }
    return true;
  }
  bool operator!=(const IkasDatuak_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IkasDatuak_

// alias to use template instance with default allocator
using IkasDatuak =
  mezuak::msg::IkasDatuak_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__IKAS_DATUAK__STRUCT_HPP_
