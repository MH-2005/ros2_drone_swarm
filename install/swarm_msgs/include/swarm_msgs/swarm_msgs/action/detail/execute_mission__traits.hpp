// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swarm_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/action/execute_mission.hpp"


#ifndef SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__TRAITS_HPP_
#define SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swarm_msgs/action/detail/execute_mission__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: mission_type
  {
    out << "mission_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_type, out);
    out << ", ";
  }

  // member: path_file
  {
    out << "path_file: ";
    rosidl_generator_traits::value_to_yaml(msg.path_file, out);
    out << ", ";
  }

  // member: formation_spacing
  {
    out << "formation_spacing: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_spacing, out);
    out << ", ";
  }

  // member: formation_type
  {
    out << "formation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_type, out);
    out << ", ";
  }

  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: max_duration
  {
    out << "max_duration: ";
    rosidl_generator_traits::value_to_yaml(msg.max_duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mission_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_type, out);
    out << "\n";
  }

  // member: path_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_file: ";
    rosidl_generator_traits::value_to_yaml(msg.path_file, out);
    out << "\n";
  }

  // member: formation_spacing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_spacing: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_spacing, out);
    out << "\n";
  }

  // member: formation_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_type, out);
    out << "\n";
  }

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: max_duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_duration: ";
    rosidl_generator_traits::value_to_yaml(msg.max_duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_Goal & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_Goal>()
{
  return "swarm_msgs::action::ExecuteMission_Goal";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_Goal>()
{
  return "swarm_msgs/action/ExecuteMission_Goal";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'final_positions'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: total_time
  {
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
    out << ", ";
  }

  // member: waypoints_completed
  {
    out << "waypoints_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.waypoints_completed, out);
    out << ", ";
  }

  // member: final_status
  {
    out << "final_status: ";
    rosidl_generator_traits::value_to_yaml(msg.final_status, out);
    out << ", ";
  }

  // member: final_positions
  {
    if (msg.final_positions.size() == 0) {
      out << "final_positions: []";
    } else {
      out << "final_positions: [";
      size_t pending_items = msg.final_positions.size();
      for (auto item : msg.final_positions) {
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
  const ExecuteMission_Result & msg,
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

  // member: total_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
    out << "\n";
  }

  // member: waypoints_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "waypoints_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.waypoints_completed, out);
    out << "\n";
  }

  // member: final_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_status: ";
    rosidl_generator_traits::value_to_yaml(msg.final_status, out);
    out << "\n";
  }

  // member: final_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.final_positions.size() == 0) {
      out << "final_positions: []\n";
    } else {
      out << "final_positions:\n";
      for (auto item : msg.final_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_Result & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_Result>()
{
  return "swarm_msgs::action::ExecuteMission_Result";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_Result>()
{
  return "swarm_msgs/action/ExecuteMission_Result";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'leader_pose'
// Member 'follower_poses'
// already included above
// #include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_waypoint
  {
    out << "current_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.current_waypoint, out);
    out << ", ";
  }

  // member: distance_to_target
  {
    out << "distance_to_target: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_target, out);
    out << ", ";
  }

  // member: elapsed_time
  {
    out << "elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_time, out);
    out << ", ";
  }

  // member: leader_pose
  {
    out << "leader_pose: ";
    to_flow_style_yaml(msg.leader_pose, out);
    out << ", ";
  }

  // member: follower_poses
  {
    if (msg.follower_poses.size() == 0) {
      out << "follower_poses: []";
    } else {
      out << "follower_poses: [";
      size_t pending_items = msg.follower_poses.size();
      for (auto item : msg.follower_poses) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.current_waypoint, out);
    out << "\n";
  }

  // member: distance_to_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_target: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_target, out);
    out << "\n";
  }

  // member: elapsed_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_time, out);
    out << "\n";
  }

  // member: leader_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leader_pose:\n";
    to_block_style_yaml(msg.leader_pose, out, indentation + 2);
  }

  // member: follower_poses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.follower_poses.size() == 0) {
      out << "follower_poses: []\n";
    } else {
      out << "follower_poses:\n";
      for (auto item : msg.follower_poses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_Feedback & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_Feedback>()
{
  return "swarm_msgs::action::ExecuteMission_Feedback";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_Feedback>()
{
  return "swarm_msgs/action/ExecuteMission_Feedback";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "swarm_msgs/action/detail/execute_mission__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_SendGoal_Request & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_SendGoal_Request>()
{
  return "swarm_msgs::action::ExecuteMission_SendGoal_Request";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_SendGoal_Request>()
{
  return "swarm_msgs/action/ExecuteMission_SendGoal_Request";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<swarm_msgs::action::ExecuteMission_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<swarm_msgs::action::ExecuteMission_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_SendGoal_Response & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_SendGoal_Response>()
{
  return "swarm_msgs::action::ExecuteMission_SendGoal_Response";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_SendGoal_Response>()
{
  return "swarm_msgs/action/ExecuteMission_SendGoal_Response";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_SendGoal_Event & msg,
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
  const ExecuteMission_SendGoal_Event & msg,
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

inline std::string to_yaml(const ExecuteMission_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_SendGoal_Event & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_SendGoal_Event>()
{
  return "swarm_msgs::action::ExecuteMission_SendGoal_Event";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_SendGoal_Event>()
{
  return "swarm_msgs/action/ExecuteMission_SendGoal_Event";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Request>::value && has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Response>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_SendGoal>()
{
  return "swarm_msgs::action::ExecuteMission_SendGoal";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_SendGoal>()
{
  return "swarm_msgs/action/ExecuteMission_SendGoal";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal_Request>::value &&
    has_fixed_size<swarm_msgs::action::ExecuteMission_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Request>::value &&
    has_bounded_size<swarm_msgs::action::ExecuteMission_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<swarm_msgs::action::ExecuteMission_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<swarm_msgs::action::ExecuteMission_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<swarm_msgs::action::ExecuteMission_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_GetResult_Request & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_GetResult_Request>()
{
  return "swarm_msgs::action::ExecuteMission_GetResult_Request";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_GetResult_Request>()
{
  return "swarm_msgs/action/ExecuteMission_GetResult_Request";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "swarm_msgs/action/detail/execute_mission__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_GetResult_Response & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_GetResult_Response>()
{
  return "swarm_msgs::action::ExecuteMission_GetResult_Response";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_GetResult_Response>()
{
  return "swarm_msgs/action/ExecuteMission_GetResult_Response";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<swarm_msgs::action::ExecuteMission_Result>::value> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<swarm_msgs::action::ExecuteMission_Result>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_GetResult_Event & msg,
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
  const ExecuteMission_GetResult_Event & msg,
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

inline std::string to_yaml(const ExecuteMission_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_GetResult_Event & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_GetResult_Event>()
{
  return "swarm_msgs::action::ExecuteMission_GetResult_Event";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_GetResult_Event>()
{
  return "swarm_msgs/action/ExecuteMission_GetResult_Event";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Request>::value && has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Response>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_GetResult>()
{
  return "swarm_msgs::action::ExecuteMission_GetResult";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_GetResult>()
{
  return "swarm_msgs/action/ExecuteMission_GetResult";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult_Request>::value &&
    has_fixed_size<swarm_msgs::action::ExecuteMission_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Request>::value &&
    has_bounded_size<swarm_msgs::action::ExecuteMission_GetResult_Response>::value
  >
{
};

template<>
struct is_service<swarm_msgs::action::ExecuteMission_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<swarm_msgs::action::ExecuteMission_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<swarm_msgs::action::ExecuteMission_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "swarm_msgs/action/detail/execute_mission__traits.hpp"

namespace swarm_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteMission_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteMission_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteMission_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace swarm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use swarm_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swarm_msgs::action::ExecuteMission_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  swarm_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swarm_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const swarm_msgs::action::ExecuteMission_FeedbackMessage & msg)
{
  return swarm_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<swarm_msgs::action::ExecuteMission_FeedbackMessage>()
{
  return "swarm_msgs::action::ExecuteMission_FeedbackMessage";
}

template<>
inline const char * name<swarm_msgs::action::ExecuteMission_FeedbackMessage>()
{
  return "swarm_msgs/action/ExecuteMission_FeedbackMessage";
}

template<>
struct has_fixed_size<swarm_msgs::action::ExecuteMission_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<swarm_msgs::action::ExecuteMission_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<swarm_msgs::action::ExecuteMission_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<swarm_msgs::action::ExecuteMission_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<swarm_msgs::action::ExecuteMission_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<swarm_msgs::action::ExecuteMission>
  : std::true_type
{
};

template<>
struct is_action_goal<swarm_msgs::action::ExecuteMission_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<swarm_msgs::action::ExecuteMission_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<swarm_msgs::action::ExecuteMission_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__TRAITS_HPP_
