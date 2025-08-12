// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swarm_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/drone_state.hpp"


#ifndef SWARM_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
#define SWARM_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swarm_msgs/msg/detail/drone_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swarm_msgs
{

namespace msg
{

namespace builder
{

class Init_DroneState_status
{
public:
  explicit Init_DroneState_status(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::msg::DroneState status(::swarm_msgs::msg::DroneState::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_battery_level
{
public:
  explicit Init_DroneState_battery_level(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_status battery_level(::swarm_msgs::msg::DroneState::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_DroneState_status(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_is_connected
{
public:
  explicit Init_DroneState_is_connected(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_battery_level is_connected(::swarm_msgs::msg::DroneState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_DroneState_battery_level(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_is_armed
{
public:
  explicit Init_DroneState_is_armed(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_is_connected is_armed(::swarm_msgs::msg::DroneState::_is_armed_type arg)
  {
    msg_.is_armed = std::move(arg);
    return Init_DroneState_is_connected(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_velocity
{
public:
  explicit Init_DroneState_velocity(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_is_armed velocity(::swarm_msgs::msg::DroneState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_DroneState_is_armed(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_pose
{
public:
  explicit Init_DroneState_pose(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_velocity pose(::swarm_msgs::msg::DroneState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_DroneState_velocity(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_role
{
public:
  explicit Init_DroneState_role(::swarm_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_pose role(::swarm_msgs::msg::DroneState::_role_type arg)
  {
    msg_.role = std::move(arg);
    return Init_DroneState_pose(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

class Init_DroneState_drone_id
{
public:
  Init_DroneState_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneState_role drone_id(::swarm_msgs::msg::DroneState::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneState_role(msg_);
  }

private:
  ::swarm_msgs::msg::DroneState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::msg::DroneState>()
{
  return swarm_msgs::msg::builder::Init_DroneState_drone_id();
}

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
