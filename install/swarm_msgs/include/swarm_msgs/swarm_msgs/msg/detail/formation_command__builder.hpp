// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swarm_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/formation_command.hpp"


#ifndef SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_
#define SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swarm_msgs/msg/detail/formation_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swarm_msgs
{

namespace msg
{

namespace builder
{

class Init_FormationCommand_translation
{
public:
  explicit Init_FormationCommand_translation(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  ::swarm_msgs::msg::FormationCommand translation(::swarm_msgs::msg::FormationCommand::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_rotation_angle
{
public:
  explicit Init_FormationCommand_rotation_angle(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_translation rotation_angle(::swarm_msgs::msg::FormationCommand::_rotation_angle_type arg)
  {
    msg_.rotation_angle = std::move(arg);
    return Init_FormationCommand_translation(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_center_point
{
public:
  explicit Init_FormationCommand_center_point(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_rotation_angle center_point(::swarm_msgs::msg::FormationCommand::_center_point_type arg)
  {
    msg_.center_point = std::move(arg);
    return Init_FormationCommand_rotation_angle(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_spacing
{
public:
  explicit Init_FormationCommand_spacing(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_center_point spacing(::swarm_msgs::msg::FormationCommand::_spacing_type arg)
  {
    msg_.spacing = std::move(arg);
    return Init_FormationCommand_center_point(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_altitude
{
public:
  explicit Init_FormationCommand_altitude(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_spacing altitude(::swarm_msgs::msg::FormationCommand::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_FormationCommand_spacing(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_size
{
public:
  explicit Init_FormationCommand_size(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_altitude size(::swarm_msgs::msg::FormationCommand::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_FormationCommand_altitude(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_orientation
{
public:
  explicit Init_FormationCommand_orientation(::swarm_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_size orientation(::swarm_msgs::msg::FormationCommand::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_FormationCommand_size(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_formation_type
{
public:
  Init_FormationCommand_formation_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FormationCommand_orientation formation_type(::swarm_msgs::msg::FormationCommand::_formation_type_type arg)
  {
    msg_.formation_type = std::move(arg);
    return Init_FormationCommand_orientation(msg_);
  }

private:
  ::swarm_msgs::msg::FormationCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swarm_msgs::msg::FormationCommand>()
{
  return swarm_msgs::msg::builder::Init_FormationCommand_formation_type();
}

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_
