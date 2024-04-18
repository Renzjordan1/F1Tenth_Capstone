// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qlearn_interfaces:msg/IntStamped.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_HPP_
#define QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__qlearn_interfaces__msg__IntStamped __attribute__((deprecated))
#else
# define DEPRECATED__qlearn_interfaces__msg__IntStamped __declspec(deprecated)
#endif

namespace qlearn_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IntStamped_
{
  using Type = IntStamped_<ContainerAllocator>;

  explicit IntStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0l;
    }
  }

  explicit IntStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _data_type =
    int32_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__data(
    const int32_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qlearn_interfaces::msg::IntStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const qlearn_interfaces::msg::IntStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::msg::IntStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::msg::IntStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qlearn_interfaces__msg__IntStamped
    std::shared_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qlearn_interfaces__msg__IntStamped
    std::shared_ptr<qlearn_interfaces::msg::IntStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntStamped_

// alias to use template instance with default allocator
using IntStamped =
  qlearn_interfaces::msg::IntStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__MSG__DETAIL__INT_STAMPED__STRUCT_HPP_
