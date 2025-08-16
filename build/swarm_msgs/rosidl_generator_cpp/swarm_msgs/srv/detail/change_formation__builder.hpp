// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/change_formation.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__BUILDER_HPP_
#define SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swarm_msgs/srv/detail/change_formation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeFormation_Request_execute_simultaneously
{
public:
  explicit Init_ChangeFormation_Request_execute_simultaneously(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::ChangeFormation_Request execute_simultaneously(::swarm_msgs::srv::ChangeFormation_Request::_execute_simultaneously_type arg)
  {
    msg_.execute_simultaneously = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_rotate_z
{
public:
  explicit Init_ChangeFormation_Request_rotate_z(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_execute_simultaneously rotate_z(::swarm_msgs::srv::ChangeFormation_Request::_rotate_z_type arg)
  {
    msg_.rotate_z = std::move(arg);
    return Init_ChangeFormation_Request_execute_simultaneously(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_rotate_y
{
public:
  explicit Init_ChangeFormation_Request_rotate_y(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_rotate_z rotate_y(::swarm_msgs::srv::ChangeFormation_Request::_rotate_y_type arg)
  {
    msg_.rotate_y = std::move(arg);
    return Init_ChangeFormation_Request_rotate_z(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_rotate_x
{
public:
  explicit Init_ChangeFormation_Request_rotate_x(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_rotate_y rotate_x(::swarm_msgs::srv::ChangeFormation_Request::_rotate_x_type arg)
  {
    msg_.rotate_x = std::move(arg);
    return Init_ChangeFormation_Request_rotate_y(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_move_z
{
public:
  explicit Init_ChangeFormation_Request_move_z(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_rotate_x move_z(::swarm_msgs::srv::ChangeFormation_Request::_move_z_type arg)
  {
    msg_.move_z = std::move(arg);
    return Init_ChangeFormation_Request_rotate_x(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_move_y
{
public:
  explicit Init_ChangeFormation_Request_move_y(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_move_z move_y(::swarm_msgs::srv::ChangeFormation_Request::_move_y_type arg)
  {
    msg_.move_y = std::move(arg);
    return Init_ChangeFormation_Request_move_z(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_move_x
{
public:
  explicit Init_ChangeFormation_Request_move_x(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_move_y move_x(::swarm_msgs::srv::ChangeFormation_Request::_move_x_type arg)
  {
    msg_.move_x = std::move(arg);
    return Init_ChangeFormation_Request_move_y(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_altitude
{
public:
  explicit Init_ChangeFormation_Request_altitude(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_move_x altitude(::swarm_msgs::srv::ChangeFormation_Request::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_ChangeFormation_Request_move_x(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_size
{
public:
  explicit Init_ChangeFormation_Request_size(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_altitude size(::swarm_msgs::srv::ChangeFormation_Request::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_ChangeFormation_Request_altitude(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_orientation
{
public:
  explicit Init_ChangeFormation_Request_orientation(::swarm_msgs::srv::ChangeFormation_Request & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Request_size orientation(::swarm_msgs::srv::ChangeFormation_Request::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_ChangeFormation_Request_size(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

class Init_ChangeFormation_Request_formation_type
{
public:
  Init_ChangeFormation_Request_formation_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeFormation_Request_orientation formation_type(::swarm_msgs::srv::ChangeFormation_Request::_formation_type_type arg)
  {
    msg_.formation_type = std::move(arg);
    return Init_ChangeFormation_Request_orientation(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::ChangeFormation_Request>()
{
  return swarm_msgs::srv::builder::Init_ChangeFormation_Request_formation_type();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeFormation_Response_execution_time
{
public:
  explicit Init_ChangeFormation_Response_execution_time(::swarm_msgs::srv::ChangeFormation_Response & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::ChangeFormation_Response execution_time(::swarm_msgs::srv::ChangeFormation_Response::_execution_time_type arg)
  {
    msg_.execution_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Response msg_;
};

class Init_ChangeFormation_Response_message
{
public:
  explicit Init_ChangeFormation_Response_message(::swarm_msgs::srv::ChangeFormation_Response & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Response_execution_time message(::swarm_msgs::srv::ChangeFormation_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ChangeFormation_Response_execution_time(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Response msg_;
};

class Init_ChangeFormation_Response_success
{
public:
  Init_ChangeFormation_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeFormation_Response_message success(::swarm_msgs::srv::ChangeFormation_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ChangeFormation_Response_message(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::ChangeFormation_Response>()
{
  return swarm_msgs::srv::builder::Init_ChangeFormation_Response_success();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeFormation_Event_response
{
public:
  explicit Init_ChangeFormation_Event_response(::swarm_msgs::srv::ChangeFormation_Event & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::ChangeFormation_Event response(::swarm_msgs::srv::ChangeFormation_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Event msg_;
};

class Init_ChangeFormation_Event_request
{
public:
  explicit Init_ChangeFormation_Event_request(::swarm_msgs::srv::ChangeFormation_Event & msg)
  : msg_(msg)
  {}
  Init_ChangeFormation_Event_response request(::swarm_msgs::srv::ChangeFormation_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ChangeFormation_Event_response(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Event msg_;
};

class Init_ChangeFormation_Event_info
{
public:
  Init_ChangeFormation_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeFormation_Event_request info(::swarm_msgs::srv::ChangeFormation_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ChangeFormation_Event_request(msg_);
  }

private:
  ::swarm_msgs::srv::ChangeFormation_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::ChangeFormation_Event>()
{
  return swarm_msgs::srv::builder::Init_ChangeFormation_Event_info();
}

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__BUILDER_HPP_
