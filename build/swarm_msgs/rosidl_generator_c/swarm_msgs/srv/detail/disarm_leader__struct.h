// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/disarm_leader.h"


#ifndef SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_H_
#define SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DisarmLeader in the package swarm_msgs.
typedef struct swarm_msgs__srv__DisarmLeader_Request
{
  int32_t leader_id;
  bool return_to_home;
} swarm_msgs__srv__DisarmLeader_Request;

// Struct for a sequence of swarm_msgs__srv__DisarmLeader_Request.
typedef struct swarm_msgs__srv__DisarmLeader_Request__Sequence
{
  swarm_msgs__srv__DisarmLeader_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__DisarmLeader_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DisarmLeader in the package swarm_msgs.
typedef struct swarm_msgs__srv__DisarmLeader_Response
{
  bool success;
  int32_t old_leader_id;
  int32_t new_leader_id;
  rosidl_runtime_c__String message;
} swarm_msgs__srv__DisarmLeader_Response;

// Struct for a sequence of swarm_msgs__srv__DisarmLeader_Response.
typedef struct swarm_msgs__srv__DisarmLeader_Response__Sequence
{
  swarm_msgs__srv__DisarmLeader_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__DisarmLeader_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  swarm_msgs__srv__DisarmLeader_Event__request__MAX_SIZE = 1
};
// response
enum
{
  swarm_msgs__srv__DisarmLeader_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/DisarmLeader in the package swarm_msgs.
typedef struct swarm_msgs__srv__DisarmLeader_Event
{
  service_msgs__msg__ServiceEventInfo info;
  swarm_msgs__srv__DisarmLeader_Request__Sequence request;
  swarm_msgs__srv__DisarmLeader_Response__Sequence response;
} swarm_msgs__srv__DisarmLeader_Event;

// Struct for a sequence of swarm_msgs__srv__DisarmLeader_Event.
typedef struct swarm_msgs__srv__DisarmLeader_Event__Sequence
{
  swarm_msgs__srv__DisarmLeader_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__DisarmLeader_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWARM_MSGS__SRV__DETAIL__DISARM_LEADER__STRUCT_H_
