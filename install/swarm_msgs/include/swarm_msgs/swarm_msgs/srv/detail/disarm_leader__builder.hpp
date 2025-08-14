// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/disarm_leader.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__BUILDER_HPP_
#define SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swarm_msgs/srv/detail/disarm_leader__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_DisarmLeader_Request_return_to_home
{
public:
  explicit Init_DisarmLeader_Request_return_to_home(::swarm_msgs::srv::DisarmLeader_Request & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::DisarmLeader_Request return_to_home(::swarm_msgs::srv::DisarmLeader_Request::_return_to_home_type arg)
  {
    msg_.return_to_home = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Request msg_;
};

class Init_DisarmLeader_Request_leader_id
{
public:
  Init_DisarmLeader_Request_leader_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DisarmLeader_Request_return_to_home leader_id(::swarm_msgs::srv::DisarmLeader_Request::_leader_id_type arg)
  {
    msg_.leader_id = std::move(arg);
    return Init_DisarmLeader_Request_return_to_home(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::DisarmLeader_Request>()
{
  return swarm_msgs::srv::builder::Init_DisarmLeader_Request_leader_id();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_DisarmLeader_Response_message
{
public:
  explicit Init_DisarmLeader_Response_message(::swarm_msgs::srv::DisarmLeader_Response & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::DisarmLeader_Response message(::swarm_msgs::srv::DisarmLeader_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Response msg_;
};

class Init_DisarmLeader_Response_new_leader_id
{
public:
  explicit Init_DisarmLeader_Response_new_leader_id(::swarm_msgs::srv::DisarmLeader_Response & msg)
  : msg_(msg)
  {}
  Init_DisarmLeader_Response_message new_leader_id(::swarm_msgs::srv::DisarmLeader_Response::_new_leader_id_type arg)
  {
    msg_.new_leader_id = std::move(arg);
    return Init_DisarmLeader_Response_message(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Response msg_;
};

class Init_DisarmLeader_Response_old_leader_id
{
public:
  explicit Init_DisarmLeader_Response_old_leader_id(::swarm_msgs::srv::DisarmLeader_Response & msg)
  : msg_(msg)
  {}
  Init_DisarmLeader_Response_new_leader_id old_leader_id(::swarm_msgs::srv::DisarmLeader_Response::_old_leader_id_type arg)
  {
    msg_.old_leader_id = std::move(arg);
    return Init_DisarmLeader_Response_new_leader_id(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Response msg_;
};

class Init_DisarmLeader_Response_success
{
public:
  Init_DisarmLeader_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DisarmLeader_Response_old_leader_id success(::swarm_msgs::srv::DisarmLeader_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DisarmLeader_Response_old_leader_id(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::DisarmLeader_Response>()
{
  return swarm_msgs::srv::builder::Init_DisarmLeader_Response_success();
}

}  // namespace swarm_msgs


namespace swarm_msgs
{

namespace srv
{

namespace builder
{

class Init_DisarmLeader_Event_response
{
public:
  explicit Init_DisarmLeader_Event_response(::swarm_msgs::srv::DisarmLeader_Event & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::srv::DisarmLeader_Event response(::swarm_msgs::srv::DisarmLeader_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Event msg_;
};

class Init_DisarmLeader_Event_request
{
public:
  explicit Init_DisarmLeader_Event_request(::swarm_msgs::srv::DisarmLeader_Event & msg)
  : msg_(msg)
  {}
  Init_DisarmLeader_Event_response request(::swarm_msgs::srv::DisarmLeader_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DisarmLeader_Event_response(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Event msg_;
};

class Init_DisarmLeader_Event_info
{
public:
  Init_DisarmLeader_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DisarmLeader_Event_request info(::swarm_msgs::srv::DisarmLeader_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DisarmLeader_Event_request(msg_);
  }

private:
  ::swarm_msgs::srv::DisarmLeader_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::srv::DisarmLeader_Event>()
{
  return swarm_msgs::srv::builder::Init_DisarmLeader_Event_info();
}

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__BUILDER_HPP_
