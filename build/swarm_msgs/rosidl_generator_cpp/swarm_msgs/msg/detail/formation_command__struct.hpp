// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swarm_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/formation_command.hpp"


#ifndef SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_
#define SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center_point'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'translation'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__swarm_msgs__msg__FormationCommand __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__msg__FormationCommand __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FormationCommand_
{
  using Type = FormationCommand_<ContainerAllocator>;

  explicit FormationCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center_point(_init),
    translation(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_type = "";
      this->orientation = "";
      this->size = 0.0;
      this->altitude = 0.0;
      this->spacing = 0.0;
      this->rotation_angle = 0.0;
    }
  }

  explicit FormationCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : formation_type(_alloc),
    orientation(_alloc),
    center_point(_alloc, _init),
    translation(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_type = "";
      this->orientation = "";
      this->size = 0.0;
      this->altitude = 0.0;
      this->spacing = 0.0;
      this->rotation_angle = 0.0;
    }
  }

  // field types and members
  using _formation_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _formation_type_type formation_type;
  using _orientation_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _orientation_type orientation;
  using _size_type =
    double;
  _size_type size;
  using _altitude_type =
    double;
  _altitude_type altitude;
  using _spacing_type =
    double;
  _spacing_type spacing;
  using _center_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_point_type center_point;
  using _rotation_angle_type =
    double;
  _rotation_angle_type rotation_angle;
  using _translation_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _translation_type translation;

  // setters for named parameter idiom
  Type & set__formation_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->formation_type = _arg;
    return *this;
  }
  Type & set__orientation(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__size(
    const double & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__spacing(
    const double & _arg)
  {
    this->spacing = _arg;
    return *this;
  }
  Type & set__center_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center_point = _arg;
    return *this;
  }
  Type & set__rotation_angle(
    const double & _arg)
  {
    this->rotation_angle = _arg;
    return *this;
  }
  Type & set__translation(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->translation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::msg::FormationCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::msg::FormationCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::msg::FormationCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::msg::FormationCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__msg__FormationCommand
    std::shared_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__msg__FormationCommand
    std::shared_ptr<swarm_msgs::msg::FormationCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FormationCommand_ & other) const
  {
    if (this->formation_type != other.formation_type) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->spacing != other.spacing) {
      return false;
    }
    if (this->center_point != other.center_point) {
      return false;
    }
    if (this->rotation_angle != other.rotation_angle) {
      return false;
    }
    if (this->translation != other.translation) {
      return false;
    }
    return true;
  }
  bool operator!=(const FormationCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FormationCommand_

// alias to use template instance with default allocator
using FormationCommand =
  swarm_msgs::msg::FormationCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_
