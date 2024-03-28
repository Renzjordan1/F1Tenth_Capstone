// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_messages:msg/PIDInput.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_HPP_
#define MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pid_error'
#include "my_messages/msg/detail/key_value__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_messages__msg__PIDInput __attribute__((deprecated))
#else
# define DEPRECATED__my_messages__msg__PIDInput __declspec(deprecated)
#endif

namespace my_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PIDInput_
{
  using Type = PIDInput_<ContainerAllocator>;

  explicit PIDInput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pid_vel = 0.0f;
    }
  }

  explicit PIDInput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pid_vel = 0.0f;
    }
  }

  // field types and members
  using _pid_vel_type =
    float;
  _pid_vel_type pid_vel;
  using _pid_error_type =
    std::vector<my_messages::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_messages::msg::KeyValue_<ContainerAllocator>>>;
  _pid_error_type pid_error;

  // setters for named parameter idiom
  Type & set__pid_vel(
    const float & _arg)
  {
    this->pid_vel = _arg;
    return *this;
  }
  Type & set__pid_error(
    const std::vector<my_messages::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_messages::msg::KeyValue_<ContainerAllocator>>> & _arg)
  {
    this->pid_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_messages::msg::PIDInput_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_messages::msg::PIDInput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_messages::msg::PIDInput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_messages::msg::PIDInput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_messages::msg::PIDInput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_messages::msg::PIDInput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_messages::msg::PIDInput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_messages::msg::PIDInput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_messages::msg::PIDInput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_messages::msg::PIDInput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_messages__msg__PIDInput
    std::shared_ptr<my_messages::msg::PIDInput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_messages__msg__PIDInput
    std::shared_ptr<my_messages::msg::PIDInput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PIDInput_ & other) const
  {
    if (this->pid_vel != other.pid_vel) {
      return false;
    }
    if (this->pid_error != other.pid_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const PIDInput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PIDInput_

// alias to use template instance with default allocator
using PIDInput =
  my_messages::msg::PIDInput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_messages

#endif  // MY_MESSAGES__MSG__DETAIL__PID_INPUT__STRUCT_HPP_
