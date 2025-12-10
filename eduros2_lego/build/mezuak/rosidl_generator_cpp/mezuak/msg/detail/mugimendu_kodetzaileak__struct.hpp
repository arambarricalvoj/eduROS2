// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/mugimendu_kodetzaileak.hpp"


#ifndef MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_HPP_
#define MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mezuak__msg__MugimenduKodetzaileak __attribute__((deprecated))
#else
# define DEPRECATED__mezuak__msg__MugimenduKodetzaileak __declspec(deprecated)
#endif

namespace mezuak
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MugimenduKodetzaileak_
{
  using Type = MugimenduKodetzaileak_<ContainerAllocator>;

  explicit MugimenduKodetzaileak_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->graduak.begin(), this->graduak.end(), 0);
      std::fill<typename std::array<int16_t, 2>::iterator, int16_t>(this->abiadurak.begin(), this->abiadurak.end(), 0);
    }
  }

  explicit MugimenduKodetzaileak_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : graduak(_alloc),
    abiadurak(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->graduak.begin(), this->graduak.end(), 0);
      std::fill<typename std::array<int16_t, 2>::iterator, int16_t>(this->abiadurak.begin(), this->abiadurak.end(), 0);
    }
  }

  // field types and members
  using _graduak_type =
    std::array<int8_t, 2>;
  _graduak_type graduak;
  using _abiadurak_type =
    std::array<int16_t, 2>;
  _abiadurak_type abiadurak;

  // setters for named parameter idiom
  Type & set__graduak(
    const std::array<int8_t, 2> & _arg)
  {
    this->graduak = _arg;
    return *this;
  }
  Type & set__abiadurak(
    const std::array<int16_t, 2> & _arg)
  {
    this->abiadurak = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> *;
  using ConstRawPtr =
    const mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mezuak__msg__MugimenduKodetzaileak
    std::shared_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mezuak__msg__MugimenduKodetzaileak
    std::shared_ptr<mezuak::msg::MugimenduKodetzaileak_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MugimenduKodetzaileak_ & other) const
  {
    if (this->graduak != other.graduak) {
      return false;
    }
    if (this->abiadurak != other.abiadurak) {
      return false;
    }
    return true;
  }
  bool operator!=(const MugimenduKodetzaileak_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MugimenduKodetzaileak_

// alias to use template instance with default allocator
using MugimenduKodetzaileak =
  mezuak::msg::MugimenduKodetzaileak_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__MUGIMENDU_KODETZAILEAK__STRUCT_HPP_
