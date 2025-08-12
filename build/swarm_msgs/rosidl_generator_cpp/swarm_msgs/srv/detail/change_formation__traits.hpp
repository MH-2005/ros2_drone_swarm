// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/change_formation.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__TRAITS_HPP_
#define SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swarm_msgs/srv/detail/change_formation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace swarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeFormation_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: formation_type
  {
    out << "formation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_type, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << ", ";
  }

  // member: move_x
  {
    out << "move_x: ";
    rosidl_generator_traits::value_to_yaml(msg.move_x, out);
    out << ", ";
  }

  // member: move_y
  {
    out << "move_y: ";
    rosidl_generator_traits::value_to_yaml(msg.move_y, out);
    out << ", ";
  }

  // member: move_z
  {
    out << "move_z: ";
    rosidl_generator_traits::value_to_yaml(msg.move_z, out);
    out << ", ";
  }

  // member: rotate_x
  {
    out << "rotate_x: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_x, out);
    out << ", ";
  }

  // member: rotate_y
  {
    out << "rotate_y: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_y, out);
    out << ", ";
  }

  // member: rotate_z
  {
    out << "rotate_z: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_z, out);
    out << ", ";
  }

  // member: execute_simultaneously
  {
    out << "execute_simultaneously: ";
    rosidl_generator_traits::value_to_yaml(msg.execute_simultaneously, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeFormation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: formation_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_type, out);
    out << "\n";
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << "\n";
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: move_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_x: ";
    rosidl_generator_traits::value_to_yaml(msg.move_x, out);
    out << "\n";
  }

  // member: move_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_y: ";
    rosidl_generator_traits::value_to_yaml(msg.move_y, out);
    out << "\n";
  }

  // member: move_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_z: ";
    rosidl_generator_traits::value_to_yaml(msg.move_z, out);
    out << "\n";
  }

  // member: rotate_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotate_x: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_x, out);
    out << "\n";
  }

  // member: rotate_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotate_y: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_y, out);
    out << "\n";
  }

  // member: rotate_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotate_z: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_z, out);
    out << "\n";
  }

  // member: execute_simultaneously
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execute_simultaneously: ";
    rosidl_generator_traits::value_to_yaml(msg.execute_simultaneously, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeFormation_Request & msg, bool use_flow_style = false)
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

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::srv::ChangeFormation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::ChangeFormation_Request & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::ChangeFormation_Request>()
{
  return "swarm_msgs::srv::ChangeFormation_Request";
}

template<>
inline const char * name<swarm_msgs::srv::ChangeFormation_Request>()
{
  return "swarm_msgs/srv/ChangeFormation_Request";
}

template<>
struct has_fixed_size<swarm_msgs::srv::ChangeFormation_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::srv::ChangeFormation_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::srv::ChangeFormation_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace swarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeFormation_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: execution_time
  {
    out << "execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeFormation_Response & msg,
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: execution_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeFormation_Response & msg, bool use_flow_style = false)
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

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::srv::ChangeFormation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::ChangeFormation_Response & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::ChangeFormation_Response>()
{
  return "swarm_msgs::srv::ChangeFormation_Response";
}

template<>
inline const char * name<swarm_msgs::srv::ChangeFormation_Response>()
{
  return "swarm_msgs/srv/ChangeFormation_Response";
}

template<>
struct has_fixed_size<swarm_msgs::srv::ChangeFormation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::srv::ChangeFormation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::srv::ChangeFormation_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace swarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeFormation_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeFormation_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeFormation_Event & msg, bool use_flow_style = false)
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

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::srv::ChangeFormation_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::ChangeFormation_Event & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::ChangeFormation_Event>()
{
  return "swarm_msgs::srv::ChangeFormation_Event";
}

template<>
inline const char * name<swarm_msgs::srv::ChangeFormation_Event>()
{
  return "swarm_msgs/srv/ChangeFormation_Event";
}

template<>
struct has_fixed_size<swarm_msgs::srv::ChangeFormation_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::srv::ChangeFormation_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<swarm_msgs::srv::ChangeFormation_Request>::value && has_bounded_size<swarm_msgs::srv::ChangeFormation_Response>::value> {};

template<>
struct is_message<swarm_msgs::srv::ChangeFormation_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<swarm_msgs::srv::ChangeFormation>()
{
  return "swarm_msgs::srv::ChangeFormation";
}

template<>
inline const char * name<swarm_msgs::srv::ChangeFormation>()
{
  return "swarm_msgs/srv/ChangeFormation";
}

template<>
struct has_fixed_size<swarm_msgs::srv::ChangeFormation>
  : std::integral_constant<
    bool,
    has_fixed_size<swarm_msgs::srv::ChangeFormation_Request>::value &&
    has_fixed_size<swarm_msgs::srv::ChangeFormation_Response>::value
  >
{
};

template<>
struct has_bounded_size<swarm_msgs::srv::ChangeFormation>
  : std::integral_constant<
    bool,
    has_bounded_size<swarm_msgs::srv::ChangeFormation_Request>::value &&
    has_bounded_size<swarm_msgs::srv::ChangeFormation_Response>::value
  >
{
};

template<>
struct is_service<swarm_msgs::srv::ChangeFormation>
  : std::true_type
{
};

template<>
struct is_service_request<swarm_msgs::srv::ChangeFormation_Request>
  : std::true_type
{
};

template<>
struct is_service_response<swarm_msgs::srv::ChangeFormation_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__TRAITS_HPP_
