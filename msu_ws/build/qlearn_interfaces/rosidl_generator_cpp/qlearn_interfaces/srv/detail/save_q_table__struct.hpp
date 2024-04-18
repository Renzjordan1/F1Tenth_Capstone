// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qlearn_interfaces:srv/SaveQTable.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__STRUCT_HPP_
#define QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qlearn_interfaces__srv__SaveQTable_Request __attribute__((deprecated))
#else
# define DEPRECATED__qlearn_interfaces__srv__SaveQTable_Request __declspec(deprecated)
#endif

namespace qlearn_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveQTable_Request_
{
  using Type = SaveQTable_Request_<ContainerAllocator>;

  explicit SaveQTable_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  explicit SaveQTable_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  // field types and members
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;

  // setters for named parameter idiom
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qlearn_interfaces__srv__SaveQTable_Request
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qlearn_interfaces__srv__SaveQTable_Request
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveQTable_Request_ & other) const
  {
    if (this->filename != other.filename) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveQTable_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveQTable_Request_

// alias to use template instance with default allocator
using SaveQTable_Request =
  qlearn_interfaces::srv::SaveQTable_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qlearn_interfaces


#ifndef _WIN32
# define DEPRECATED__qlearn_interfaces__srv__SaveQTable_Response __attribute__((deprecated))
#else
# define DEPRECATED__qlearn_interfaces__srv__SaveQTable_Response __declspec(deprecated)
#endif

namespace qlearn_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SaveQTable_Response_
{
  using Type = SaveQTable_Response_<ContainerAllocator>;

  explicit SaveQTable_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SaveQTable_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qlearn_interfaces__srv__SaveQTable_Response
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qlearn_interfaces__srv__SaveQTable_Response
    std::shared_ptr<qlearn_interfaces::srv::SaveQTable_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SaveQTable_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SaveQTable_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SaveQTable_Response_

// alias to use template instance with default allocator
using SaveQTable_Response =
  qlearn_interfaces::srv::SaveQTable_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qlearn_interfaces

namespace qlearn_interfaces
{

namespace srv
{

struct SaveQTable
{
  using Request = qlearn_interfaces::srv::SaveQTable_Request;
  using Response = qlearn_interfaces::srv::SaveQTable_Response;
};

}  // namespace srv

}  // namespace qlearn_interfaces

#endif  // QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__STRUCT_HPP_
