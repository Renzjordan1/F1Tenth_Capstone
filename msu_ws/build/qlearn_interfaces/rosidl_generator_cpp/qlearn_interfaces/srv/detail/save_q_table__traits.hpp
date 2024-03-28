// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qlearn_interfaces:srv/SaveQTable.idl
// generated code does not contain a copyright notice

#ifndef QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__TRAITS_HPP_
#define QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qlearn_interfaces/srv/detail/save_q_table__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qlearn_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveQTable_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveQTable_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveQTable_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qlearn_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use qlearn_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qlearn_interfaces::srv::SaveQTable_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  qlearn_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qlearn_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const qlearn_interfaces::srv::SaveQTable_Request & msg)
{
  return qlearn_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qlearn_interfaces::srv::SaveQTable_Request>()
{
  return "qlearn_interfaces::srv::SaveQTable_Request";
}

template<>
inline const char * name<qlearn_interfaces::srv::SaveQTable_Request>()
{
  return "qlearn_interfaces/srv/SaveQTable_Request";
}

template<>
struct has_fixed_size<qlearn_interfaces::srv::SaveQTable_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qlearn_interfaces::srv::SaveQTable_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qlearn_interfaces::srv::SaveQTable_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace qlearn_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveQTable_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveQTable_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveQTable_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qlearn_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use qlearn_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qlearn_interfaces::srv::SaveQTable_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  qlearn_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qlearn_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const qlearn_interfaces::srv::SaveQTable_Response & msg)
{
  return qlearn_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qlearn_interfaces::srv::SaveQTable_Response>()
{
  return "qlearn_interfaces::srv::SaveQTable_Response";
}

template<>
inline const char * name<qlearn_interfaces::srv::SaveQTable_Response>()
{
  return "qlearn_interfaces/srv/SaveQTable_Response";
}

template<>
struct has_fixed_size<qlearn_interfaces::srv::SaveQTable_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qlearn_interfaces::srv::SaveQTable_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qlearn_interfaces::srv::SaveQTable_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qlearn_interfaces::srv::SaveQTable>()
{
  return "qlearn_interfaces::srv::SaveQTable";
}

template<>
inline const char * name<qlearn_interfaces::srv::SaveQTable>()
{
  return "qlearn_interfaces/srv/SaveQTable";
}

template<>
struct has_fixed_size<qlearn_interfaces::srv::SaveQTable>
  : std::integral_constant<
    bool,
    has_fixed_size<qlearn_interfaces::srv::SaveQTable_Request>::value &&
    has_fixed_size<qlearn_interfaces::srv::SaveQTable_Response>::value
  >
{
};

template<>
struct has_bounded_size<qlearn_interfaces::srv::SaveQTable>
  : std::integral_constant<
    bool,
    has_bounded_size<qlearn_interfaces::srv::SaveQTable_Request>::value &&
    has_bounded_size<qlearn_interfaces::srv::SaveQTable_Response>::value
  >
{
};

template<>
struct is_service<qlearn_interfaces::srv::SaveQTable>
  : std::true_type
{
};

template<>
struct is_service_request<qlearn_interfaces::srv::SaveQTable_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qlearn_interfaces::srv::SaveQTable_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QLEARN_INTERFACES__SRV__DETAIL__SAVE_Q_TABLE__TRAITS_HPP_
