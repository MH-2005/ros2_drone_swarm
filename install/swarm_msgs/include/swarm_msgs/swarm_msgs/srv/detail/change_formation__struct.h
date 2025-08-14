// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/srv/change_formation.h"


#ifndef SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_H_
#define SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'formation_type'
// Member 'orientation'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeFormation in the package swarm_msgs.
typedef struct swarm_msgs__srv__ChangeFormation_Request
{
  rosidl_runtime_c__String formation_type;
  rosidl_runtime_c__String orientation;
  double size;
  double altitude;
  double move_x;
  double move_y;
  double move_z;
  double rotate_x;
  double rotate_y;
  double rotate_z;
  bool execute_simultaneously;
} swarm_msgs__srv__ChangeFormation_Request;

// Struct for a sequence of swarm_msgs__srv__ChangeFormation_Request.
typedef struct swarm_msgs__srv__ChangeFormation_Request__Sequence
{
  swarm_msgs__srv__ChangeFormation_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__ChangeFormation_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeFormation in the package swarm_msgs.
typedef struct swarm_msgs__srv__ChangeFormation_Response
{
  bool success;
  rosidl_runtime_c__String message;
  double execution_time;
} swarm_msgs__srv__ChangeFormation_Response;

// Struct for a sequence of swarm_msgs__srv__ChangeFormation_Response.
typedef struct swarm_msgs__srv__ChangeFormation_Response__Sequence
{
  swarm_msgs__srv__ChangeFormation_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__ChangeFormation_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  swarm_msgs__srv__ChangeFormation_Event__request__MAX_SIZE = 1
};
// response
enum
{
  swarm_msgs__srv__ChangeFormation_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ChangeFormation in the package swarm_msgs.
typedef struct swarm_msgs__srv__ChangeFormation_Event
{
  service_msgs__msg__ServiceEventInfo info;
  swarm_msgs__srv__ChangeFormation_Request__Sequence request;
  swarm_msgs__srv__ChangeFormation_Response__Sequence response;
} swarm_msgs__srv__ChangeFormation_Event;

// Struct for a sequence of swarm_msgs__srv__ChangeFormation_Event.
typedef struct swarm_msgs__srv__ChangeFormation_Event__Sequence
{
  swarm_msgs__srv__ChangeFormation_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__srv__ChangeFormation_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWARM_MSGS__SRV__DETAIL__CHANGE_FORMATION__STRUCT_H_
