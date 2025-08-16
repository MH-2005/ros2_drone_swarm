// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/change_formation.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_HPP_
#define SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Request __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Request __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeFormation_Request_
{
  using Type = ChangeFormation_Request_<ContainerAllocator>;

  explicit ChangeFormation_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_type = "";
      this->orientation = "";
      this->size = 0.0;
      this->altitude = 0.0;
      this->move_x = 0.0;
      this->move_y = 0.0;
      this->move_z = 0.0;
      this->rotate_x = 0.0;
      this->rotate_y = 0.0;
      this->rotate_z = 0.0;
      this->execute_simultaneously = false;
    }
  }

  explicit ChangeFormation_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : formation_type(_alloc),
    orientation(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_type = "";
      this->orientation = "";
      this->size = 0.0;
      this->altitude = 0.0;
      this->move_x = 0.0;
      this->move_y = 0.0;
      this->move_z = 0.0;
      this->rotate_x = 0.0;
      this->rotate_y = 0.0;
      this->rotate_z = 0.0;
      this->execute_simultaneously = false;
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
  using _move_x_type =
    double;
  _move_x_type move_x;
  using _move_y_type =
    double;
  _move_y_type move_y;
  using _move_z_type =
    double;
  _move_z_type move_z;
  using _rotate_x_type =
    double;
  _rotate_x_type rotate_x;
  using _rotate_y_type =
    double;
  _rotate_y_type rotate_y;
  using _rotate_z_type =
    double;
  _rotate_z_type rotate_z;
  using _execute_simultaneously_type =
    bool;
  _execute_simultaneously_type execute_simultaneously;

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
  Type & set__move_x(
    const double & _arg)
  {
    this->move_x = _arg;
    return *this;
  }
  Type & set__move_y(
    const double & _arg)
  {
    this->move_y = _arg;
    return *this;
  }
  Type & set__move_z(
    const double & _arg)
  {
    this->move_z = _arg;
    return *this;
  }
  Type & set__rotate_x(
    const double & _arg)
  {
    this->rotate_x = _arg;
    return *this;
  }
  Type & set__rotate_y(
    const double & _arg)
  {
    this->rotate_y = _arg;
    return *this;
  }
  Type & set__rotate_z(
    const double & _arg)
  {
    this->rotate_z = _arg;
    return *this;
  }
  Type & set__execute_simultaneously(
    const bool & _arg)
  {
    this->execute_simultaneously = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Request
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Request
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeFormation_Request_ & other) const
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
    if (this->move_x != other.move_x) {
      return false;
    }
    if (this->move_y != other.move_y) {
      return false;
    }
    if (this->move_z != other.move_z) {
      return false;
    }
    if (this->rotate_x != other.rotate_x) {
      return false;
    }
    if (this->rotate_y != other.rotate_y) {
      return false;
    }
    if (this->rotate_z != other.rotate_z) {
      return false;
    }
    if (this->execute_simultaneously != other.execute_simultaneously) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeFormation_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeFormation_Request_

// alias to use template instance with default allocator
using ChangeFormation_Request =
  swarm_msgs::srv::ChangeFormation_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs


#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Response __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Response __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeFormation_Response_
{
  using Type = ChangeFormation_Response_<ContainerAllocator>;

  explicit ChangeFormation_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->execution_time = 0.0;
    }
  }

  explicit ChangeFormation_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->execution_time = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _execution_time_type =
    double;
  _execution_time_type execution_time;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__execution_time(
    const double & _arg)
  {
    this->execution_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Response
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Response
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeFormation_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->execution_time != other.execution_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeFormation_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeFormation_Response_

// alias to use template instance with default allocator
using ChangeFormation_Response =
  swarm_msgs::srv::ChangeFormation_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Event __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__ChangeFormation_Event __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeFormation_Event_
{
  using Type = ChangeFormation_Event_<ContainerAllocator>;

  explicit ChangeFormation_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ChangeFormation_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::ChangeFormation_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::ChangeFormation_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Event
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__ChangeFormation_Event
    std::shared_ptr<swarm_msgs::srv::ChangeFormation_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeFormation_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeFormation_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeFormation_Event_

// alias to use template instance with default allocator
using ChangeFormation_Event =
  swarm_msgs::srv::ChangeFormation_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs

namespace swarm_msgs
{

namespace srv
{

struct ChangeFormation
{
  using Request = swarm_msgs::srv::ChangeFormation_Request;
  using Response = swarm_msgs::srv::ChangeFormation_Response;
  using Event = swarm_msgs::srv::ChangeFormation_Event;
};

}  // namespace srv

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_HPP_
