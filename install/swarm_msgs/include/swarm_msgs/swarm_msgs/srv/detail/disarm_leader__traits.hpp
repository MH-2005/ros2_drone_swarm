// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/disarm_leader.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__TRAITS_HPP_
#define SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swarm_msgs/srv/detail/disarm_leader__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace swarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DisarmLeader_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: leader_id
  {
    out << "leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.leader_id, out);
    out << ", ";
  }

  // member: return_to_home
  {
    out << "return_to_home: ";
    rosidl_generator_traits::value_to_yaml(msg.return_to_home, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DisarmLeader_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: leader_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.leader_id, out);
    out << "\n";
  }

  // member: return_to_home
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "return_to_home: ";
    rosidl_generator_traits::value_to_yaml(msg.return_to_home, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DisarmLeader_Request & msg, bool use_flow_style = false)
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
  const swarm_msgs::srv::DisarmLeader_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::DisarmLeader_Request & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::DisarmLeader_Request>()
{
  return "swarm_msgs::srv::DisarmLeader_Request";
}

template<>
inline const char * name<swarm_msgs::srv::DisarmLeader_Request>()
{
  return "swarm_msgs/srv/DisarmLeader_Request";
}

template<>
struct has_fixed_size<swarm_msgs::srv::DisarmLeader_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<swarm_msgs::srv::DisarmLeader_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<swarm_msgs::srv::DisarmLeader_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace swarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DisarmLeader_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: old_leader_id
  {
    out << "old_leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.old_leader_id, out);
    out << ", ";
  }

  // member: new_leader_id
  {
    out << "new_leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.new_leader_id, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DisarmLeader_Response & msg,
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

  // member: old_leader_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "old_leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.old_leader_id, out);
    out << "\n";
  }

  // member: new_leader_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_leader_id: ";
    rosidl_generator_traits::value_to_yaml(msg.new_leader_id, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DisarmLeader_Response & msg, bool use_flow_style = false)
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
  const swarm_msgs::srv::DisarmLeader_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::DisarmLeader_Response & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::DisarmLeader_Response>()
{
  return "swarm_msgs::srv::DisarmLeader_Response";
}

template<>
inline const char * name<swarm_msgs::srv::DisarmLeader_Response>()
{
  return "swarm_msgs/srv/DisarmLeader_Response";
}

template<>
struct has_fixed_size<swarm_msgs::srv::DisarmLeader_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::srv::DisarmLeader_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::srv::DisarmLeader_Response>
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
  const DisarmLeader_Event & msg,
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
  const DisarmLeader_Event & msg,
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

inline std::string to_yaml(const DisarmLeader_Event & msg, bool use_flow_style = false)
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
  const swarm_msgs::srv::DisarmLeader_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::srv::DisarmLeader_Event & msg)
{
  return swarm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::srv::DisarmLeader_Event>()
{
  return "swarm_msgs::srv::DisarmLeader_Event";
}

template<>
inline const char * name<swarm_msgs::srv::DisarmLeader_Event>()
{
  return "swarm_msgs/srv/DisarmLeader_Event";
}

template<>
struct has_fixed_size<swarm_msgs::srv::DisarmLeader_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::srv::DisarmLeader_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<swarm_msgs::srv::DisarmLeader_Request>::value && has_bounded_size<swarm_msgs::srv::DisarmLeader_Response>::value> {};

template<>
struct is_message<swarm_msgs::srv::DisarmLeader_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<swarm_msgs::srv::DisarmLeader>()
{
  return "swarm_msgs::srv::DisarmLeader";
}

template<>
inline const char * name<swarm_msgs::srv::DisarmLeader>()
{
  return "swarm_msgs/srv/DisarmLeader";
}

template<>
struct has_fixed_size<swarm_msgs::srv::DisarmLeader>
  : std::integral_constant<
    bool,
    has_fixed_size<swarm_msgs::srv::DisarmLeader_Request>::value &&
    has_fixed_size<swarm_msgs::srv::DisarmLeader_Response>::value
  >
{
};

template<>
struct has_bounded_size<swarm_msgs::srv::DisarmLeader>
  : std::integral_constant<
    bool,
    has_bounded_size<swarm_msgs::srv::DisarmLeader_Request>::value &&
    has_bounded_size<swarm_msgs::srv::DisarmLeader_Response>::value
  >
{
};

template<>
struct is_service<swarm_msgs::srv::DisarmLeader>
  : std::true_type
{
};

template<>
struct is_service_request<swarm_msgs::srv::DisarmLeader_Request>
  : std::true_type
{
};

template<>
struct is_service_response<swarm_msgs::srv::DisarmLeader_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__TRAITS_HPP_
