// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mezuak/msg/islatutako_argia.hpp"


#ifndef MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_HPP_
#define MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mezuak__msg__IslatutakoArgia __attribute__((deprecated))
#else
# define DEPRECATED__mezuak__msg__IslatutakoArgia __declspec(deprecated)
#endif

namespace mezuak
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IslatutakoArgia_
{
  using Type = IslatutakoArgia_<ContainerAllocator>;

  explicit IslatutakoArgia_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->argi_intentsitateak.begin(), this->argi_intentsitateak.end(), 0);
    }
  }

  explicit IslatutakoArgia_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : argi_intentsitateak(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->argi_intentsitateak.begin(), this->argi_intentsitateak.end(), 0);
    }
  }

  // field types and members
  using _argi_intentsitateak_type =
    std::array<int8_t, 2>;
  _argi_intentsitateak_type argi_intentsitateak;

  // setters for named parameter idiom
  Type & set__argi_intentsitateak(
    const std::array<int8_t, 2> & _arg)
  {
    this->argi_intentsitateak = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mezuak::msg::IslatutakoArgia_<ContainerAllocator> *;
  using ConstRawPtr =
    const mezuak::msg::IslatutakoArgia_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::IslatutakoArgia_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mezuak::msg::IslatutakoArgia_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mezuak__msg__IslatutakoArgia
    std::shared_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mezuak__msg__IslatutakoArgia
    std::shared_ptr<mezuak::msg::IslatutakoArgia_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IslatutakoArgia_ & other) const
  {
    if (this->argi_intentsitateak != other.argi_intentsitateak) {
      return false;
    }
    return true;
  }
  bool operator!=(const IslatutakoArgia_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IslatutakoArgia_

// alias to use template instance with default allocator
using IslatutakoArgia =
  mezuak::msg::IslatutakoArgia_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mezuak

#endif  // MEZUAK__MSG__DETAIL__ISLATUTAKO_ARGIA__STRUCT_HPP_
