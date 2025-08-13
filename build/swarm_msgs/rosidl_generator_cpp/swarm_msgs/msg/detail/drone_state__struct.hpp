// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swarm_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/drone_state.hpp"


#ifndef SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
#define SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__swarm_msgs__msg__DroneState __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__msg__DroneState __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DroneState_
{
  using Type = DroneState_<ContainerAllocator>;

  explicit DroneState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
      this->role = "";
      this->is_armed = false;
      this->is_connected = false;
      this->battery_level = 0.0;
      this->status = "";
    }
  }

  explicit DroneState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : role(_alloc),
    pose(_alloc, _init),
    velocity(_alloc, _init),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
      this->role = "";
      this->is_armed = false;
      this->is_connected = false;
      this->battery_level = 0.0;
      this->status = "";
    }
  }

  // field types and members
  using _drone_id_type =
    int32_t;
  _drone_id_type drone_id;
  using _role_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _role_type role;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _velocity_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _velocity_type velocity;
  using _is_armed_type =
    bool;
  _is_armed_type is_armed;
  using _is_connected_type =
    bool;
  _is_connected_type is_connected;
  using _battery_level_type =
    double;
  _battery_level_type battery_level;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__drone_id(
    const int32_t & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__role(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->role = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__is_armed(
    const bool & _arg)
  {
    this->is_armed = _arg;
    return *this;
  }
  Type & set__is_connected(
    const bool & _arg)
  {
    this->is_connected = _arg;
    return *this;
  }
  Type & set__battery_level(
    const double & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::msg::DroneState_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::msg::DroneState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::msg::DroneState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::msg::DroneState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__msg__DroneState
    std::shared_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__msg__DroneState
    std::shared_ptr<swarm_msgs::msg::DroneState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneState_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->role != other.role) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->is_armed != other.is_armed) {
      return false;
    }
    if (this->is_connected != other.is_connected) {
      return false;
    }
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneState_

// alias to use template instance with default allocator
using DroneState =
  swarm_msgs::msg::DroneState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
