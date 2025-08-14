// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/disarm_leader.hpp"


#ifndef SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_HPP_
#define SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Request __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Request __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DisarmLeader_Request_
{
  using Type = DisarmLeader_Request_<ContainerAllocator>;

  explicit DisarmLeader_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leader_id = 0l;
      this->return_to_home = false;
    }
  }

  explicit DisarmLeader_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leader_id = 0l;
      this->return_to_home = false;
    }
  }

  // field types and members
  using _leader_id_type =
    int32_t;
  _leader_id_type leader_id;
  using _return_to_home_type =
    bool;
  _return_to_home_type return_to_home;

  // setters for named parameter idiom
  Type & set__leader_id(
    const int32_t & _arg)
  {
    this->leader_id = _arg;
    return *this;
  }
  Type & set__return_to_home(
    const bool & _arg)
  {
    this->return_to_home = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Request
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Request
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DisarmLeader_Request_ & other) const
  {
    if (this->leader_id != other.leader_id) {
      return false;
    }
    if (this->return_to_home != other.return_to_home) {
      return false;
    }
    return true;
  }
  bool operator!=(const DisarmLeader_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DisarmLeader_Request_

// alias to use template instance with default allocator
using DisarmLeader_Request =
  swarm_msgs::srv::DisarmLeader_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs


#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Response __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Response __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DisarmLeader_Response_
{
  using Type = DisarmLeader_Response_<ContainerAllocator>;

  explicit DisarmLeader_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->old_leader_id = 0l;
      this->new_leader_id = 0l;
      this->message = "";
    }
  }

  explicit DisarmLeader_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->old_leader_id = 0l;
      this->new_leader_id = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _old_leader_id_type =
    int32_t;
  _old_leader_id_type old_leader_id;
  using _new_leader_id_type =
    int32_t;
  _new_leader_id_type new_leader_id;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__old_leader_id(
    const int32_t & _arg)
  {
    this->old_leader_id = _arg;
    return *this;
  }
  Type & set__new_leader_id(
    const int32_t & _arg)
  {
    this->new_leader_id = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Response
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Response
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DisarmLeader_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->old_leader_id != other.old_leader_id) {
      return false;
    }
    if (this->new_leader_id != other.new_leader_id) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const DisarmLeader_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DisarmLeader_Response_

// alias to use template instance with default allocator
using DisarmLeader_Response =
  swarm_msgs::srv::DisarmLeader_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Event __attribute__((deprecated))
#else
# define DEPRECATED__swarm_msgs__srv__DisarmLeader_Event __declspec(deprecated)
#endif

namespace swarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DisarmLeader_Event_
{
  using Type = DisarmLeader_Event_<ContainerAllocator>;

  explicit DisarmLeader_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit DisarmLeader_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::DisarmLeader_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swarm_msgs::srv::DisarmLeader_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Event
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swarm_msgs__srv__DisarmLeader_Event
    std::shared_ptr<swarm_msgs::srv::DisarmLeader_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DisarmLeader_Event_ & other) const
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
  bool operator!=(const DisarmLeader_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DisarmLeader_Event_

// alias to use template instance with default allocator
using DisarmLeader_Event =
  swarm_msgs::srv::DisarmLeader_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swarm_msgs

namespace swarm_msgs
{

namespace srv
{

struct DisarmLeader
{
  using Request = swarm_msgs::srv::DisarmLeader_Request;
  using Response = swarm_msgs::srv::DisarmLeader_Response;
  using Event = swarm_msgs::srv::DisarmLeader_Event;
};

}  // namespace srv

}  // namespace swarm_msgs

#endif  // SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_HPP_
