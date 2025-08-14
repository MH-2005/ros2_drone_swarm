// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swarm_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/action/execute_mission.hpp"


#ifndef SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
#define SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swarm_msgs/action/detail/execute_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Goal_max_duration
{
public:
  explicit Init_ExecuteMission_Goal_max_duration(::swarm_msgs::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_Goal max_duration(::swarm_msgs::action::ExecuteMission_Goal::_max_duration_type arg)
  {
    msg_.max_duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_waypoints
{
public:
  explicit Init_ExecuteMission_Goal_waypoints(::swarm_msgs::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_max_duration waypoints(::swarm_msgs::action::ExecuteMission_Goal::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_ExecuteMission_Goal_max_duration(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_formation_type
{
public:
  explicit Init_ExecuteMission_Goal_formation_type(::swarm_msgs::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_waypoints formation_type(::swarm_msgs::action::ExecuteMission_Goal::_formation_type_type arg)
  {
    msg_.formation_type = std::move(arg);
    return Init_ExecuteMission_Goal_waypoints(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_formation_spacing
{
public:
  explicit Init_ExecuteMission_Goal_formation_spacing(::swarm_msgs::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_formation_type formation_spacing(::swarm_msgs::action::ExecuteMission_Goal::_formation_spacing_type arg)
  {
    msg_.formation_spacing = std::move(arg);
    return Init_ExecuteMission_Goal_formation_type(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_path_file
{
public:
  explicit Init_ExecuteMission_Goal_path_file(::swarm_msgs::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_formation_spacing path_file(::swarm_msgs::action::ExecuteMission_Goal::_path_file_type arg)
  {
    msg_.path_file = std::move(arg);
    return Init_ExecuteMission_Goal_formation_spacing(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_mission_type
{
public:
  Init_ExecuteMission_Goal_mission_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Goal_path_file mission_type(::swarm_msgs::action::ExecuteMission_Goal::_mission_type_type arg)
  {
    msg_.mission_type = std::move(arg);
    return Init_ExecuteMission_Goal_path_file(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_Goal>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_Goal_mission_type();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Result_final_positions
{
public:
  explicit Init_ExecuteMission_Result_final_positions(::swarm_msgs::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_Result final_positions(::swarm_msgs::action::ExecuteMission_Result::_final_positions_type arg)
  {
    msg_.final_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_final_status
{
public:
  explicit Init_ExecuteMission_Result_final_status(::swarm_msgs::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_final_positions final_status(::swarm_msgs::action::ExecuteMission_Result::_final_status_type arg)
  {
    msg_.final_status = std::move(arg);
    return Init_ExecuteMission_Result_final_positions(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_waypoints_completed
{
public:
  explicit Init_ExecuteMission_Result_waypoints_completed(::swarm_msgs::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_final_status waypoints_completed(::swarm_msgs::action::ExecuteMission_Result::_waypoints_completed_type arg)
  {
    msg_.waypoints_completed = std::move(arg);
    return Init_ExecuteMission_Result_final_status(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_total_time
{
public:
  explicit Init_ExecuteMission_Result_total_time(::swarm_msgs::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_waypoints_completed total_time(::swarm_msgs::action::ExecuteMission_Result::_total_time_type arg)
  {
    msg_.total_time = std::move(arg);
    return Init_ExecuteMission_Result_waypoints_completed(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_success
{
public:
  Init_ExecuteMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Result_total_time success(::swarm_msgs::action::ExecuteMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteMission_Result_total_time(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_Result>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_Result_success();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Feedback_status_message
{
public:
  explicit Init_ExecuteMission_Feedback_status_message(::swarm_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_Feedback status_message(::swarm_msgs::action::ExecuteMission_Feedback::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_follower_poses
{
public:
  explicit Init_ExecuteMission_Feedback_follower_poses(::swarm_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_status_message follower_poses(::swarm_msgs::action::ExecuteMission_Feedback::_follower_poses_type arg)
  {
    msg_.follower_poses = std::move(arg);
    return Init_ExecuteMission_Feedback_status_message(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_leader_pose
{
public:
  explicit Init_ExecuteMission_Feedback_leader_pose(::swarm_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_follower_poses leader_pose(::swarm_msgs::action::ExecuteMission_Feedback::_leader_pose_type arg)
  {
    msg_.leader_pose = std::move(arg);
    return Init_ExecuteMission_Feedback_follower_poses(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_elapsed_time
{
public:
  explicit Init_ExecuteMission_Feedback_elapsed_time(::swarm_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_leader_pose elapsed_time(::swarm_msgs::action::ExecuteMission_Feedback::_elapsed_time_type arg)
  {
    msg_.elapsed_time = std::move(arg);
    return Init_ExecuteMission_Feedback_leader_pose(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_distance_to_target
{
public:
  explicit Init_ExecuteMission_Feedback_distance_to_target(::swarm_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_elapsed_time distance_to_target(::swarm_msgs::action::ExecuteMission_Feedback::_distance_to_target_type arg)
  {
    msg_.distance_to_target = std::move(arg);
    return Init_ExecuteMission_Feedback_elapsed_time(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_waypoint
{
public:
  Init_ExecuteMission_Feedback_current_waypoint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Feedback_distance_to_target current_waypoint(::swarm_msgs::action::ExecuteMission_Feedback::_current_waypoint_type arg)
  {
    msg_.current_waypoint = std::move(arg);
    return Init_ExecuteMission_Feedback_distance_to_target(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_Feedback>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_Feedback_current_waypoint();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteMission_SendGoal_Request_goal(::swarm_msgs::action::ExecuteMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_SendGoal_Request goal(::swarm_msgs::action::ExecuteMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Request msg_;
};

class Init_ExecuteMission_SendGoal_Request_goal_id
{
public:
  Init_ExecuteMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Request_goal goal_id(::swarm_msgs::action::ExecuteMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_SendGoal_Request_goal(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_SendGoal_Request>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_SendGoal_Request_goal_id();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteMission_SendGoal_Response_stamp(::swarm_msgs::action::ExecuteMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_SendGoal_Response stamp(::swarm_msgs::action::ExecuteMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Response msg_;
};

class Init_ExecuteMission_SendGoal_Response_accepted
{
public:
  Init_ExecuteMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Response_stamp accepted(::swarm_msgs::action::ExecuteMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_SendGoal_Response>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_SendGoal_Response_accepted();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Event_response
{
public:
  explicit Init_ExecuteMission_SendGoal_Event_response(::swarm_msgs::action::ExecuteMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_SendGoal_Event response(::swarm_msgs::action::ExecuteMission_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

class Init_ExecuteMission_SendGoal_Event_request
{
public:
  explicit Init_ExecuteMission_SendGoal_Event_request(::swarm_msgs::action::ExecuteMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_SendGoal_Event_response request(::swarm_msgs::action::ExecuteMission_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMission_SendGoal_Event_response(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

class Init_ExecuteMission_SendGoal_Event_info
{
public:
  Init_ExecuteMission_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Event_request info(::swarm_msgs::action::ExecuteMission_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMission_SendGoal_Event_request(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_SendGoal_Event>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_SendGoal_Event_info();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Request_goal_id
{
public:
  Init_ExecuteMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::swarm_msgs::action::ExecuteMission_GetResult_Request goal_id(::swarm_msgs::action::ExecuteMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_GetResult_Request>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_GetResult_Request_goal_id();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Response_result
{
public:
  explicit Init_ExecuteMission_GetResult_Response_result(::swarm_msgs::action::ExecuteMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_GetResult_Response result(::swarm_msgs::action::ExecuteMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Response msg_;
};

class Init_ExecuteMission_GetResult_Response_status
{
public:
  Init_ExecuteMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Response_result status(::swarm_msgs::action::ExecuteMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteMission_GetResult_Response_result(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_GetResult_Response>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_GetResult_Response_status();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Event_response
{
public:
  explicit Init_ExecuteMission_GetResult_Event_response(::swarm_msgs::action::ExecuteMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_GetResult_Event response(::swarm_msgs::action::ExecuteMission_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Event msg_;
};

class Init_ExecuteMission_GetResult_Event_request
{
public:
  explicit Init_ExecuteMission_GetResult_Event_request(::swarm_msgs::action::ExecuteMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_GetResult_Event_response request(::swarm_msgs::action::ExecuteMission_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMission_GetResult_Event_response(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Event msg_;
};

class Init_ExecuteMission_GetResult_Event_info
{
public:
  Init_ExecuteMission_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Event_request info(::swarm_msgs::action::ExecuteMission_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMission_GetResult_Event_request(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_GetResult_Event>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_GetResult_Event_info();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteMission_FeedbackMessage_feedback(::swarm_msgs::action::ExecuteMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::action::ExecuteMission_FeedbackMessage feedback(::swarm_msgs::action::ExecuteMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_FeedbackMessage msg_;
};

class Init_ExecuteMission_FeedbackMessage_goal_id
{
public:
  Init_ExecuteMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_FeedbackMessage_feedback goal_id(::swarm_msgs::action::ExecuteMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::swarm_msgs::action::ExecuteMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::action::ExecuteMission_FeedbackMessage>()
{
  return swarm_msgs::action::builder::Init_ExecuteMission_FeedbackMessage_goal_id();
}

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
