// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swarm_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/action/execute_mission.h"


#ifndef SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
#define SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission_type'
// Member 'path_file'
// Member 'formation_type'
#include "rosidl_runtime_c/string.h"
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_Goal
{
  rosidl_runtime_c__String mission_type;
  rosidl_runtime_c__String path_file;
  double formation_spacing;
  rosidl_runtime_c__String formation_type;
  geometry_msgs__msg__Point__Sequence waypoints;
  double max_duration;
} swarm_msgs__action__ExecuteMission_Goal;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_Goal.
typedef struct swarm_msgs__action__ExecuteMission_Goal__Sequence
{
  swarm_msgs__action__ExecuteMission_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'final_status'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'final_positions'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_Result
{
  bool success;
  double total_time;
  int32_t waypoints_completed;
  rosidl_runtime_c__String final_status;
  geometry_msgs__msg__Pose__Sequence final_positions;
} swarm_msgs__action__ExecuteMission_Result;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_Result.
typedef struct swarm_msgs__action__ExecuteMission_Result__Sequence
{
  swarm_msgs__action__ExecuteMission_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'leader_pose'
// Member 'follower_poses'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'status_message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_Feedback
{
  int32_t current_waypoint;
  double distance_to_target;
  double elapsed_time;
  geometry_msgs__msg__Pose leader_pose;
  geometry_msgs__msg__Pose__Sequence follower_poses;
  rosidl_runtime_c__String status_message;
} swarm_msgs__action__ExecuteMission_Feedback;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_Feedback.
typedef struct swarm_msgs__action__ExecuteMission_Feedback__Sequence
{
  swarm_msgs__action__ExecuteMission_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "swarm_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  swarm_msgs__action__ExecuteMission_Goal goal;
} swarm_msgs__action__ExecuteMission_SendGoal_Request;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_SendGoal_Request.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence
{
  swarm_msgs__action__ExecuteMission_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} swarm_msgs__action__ExecuteMission_SendGoal_Response;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_SendGoal_Response.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence
{
  swarm_msgs__action__ExecuteMission_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  swarm_msgs__action__ExecuteMission_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  swarm_msgs__action__ExecuteMission_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence request;
  swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence response;
} swarm_msgs__action__ExecuteMission_SendGoal_Event;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_SendGoal_Event.
typedef struct swarm_msgs__action__ExecuteMission_SendGoal_Event__Sequence
{
  swarm_msgs__action__ExecuteMission_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} swarm_msgs__action__ExecuteMission_GetResult_Request;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_GetResult_Request.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence
{
  swarm_msgs__action__ExecuteMission_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Response
{
  int8_t status;
  swarm_msgs__action__ExecuteMission_Result result;
} swarm_msgs__action__ExecuteMission_GetResult_Response;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_GetResult_Response.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence
{
  swarm_msgs__action__ExecuteMission_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  swarm_msgs__action__ExecuteMission_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  swarm_msgs__action__ExecuteMission_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence request;
  swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence response;
} swarm_msgs__action__ExecuteMission_GetResult_Event;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_GetResult_Event.
typedef struct swarm_msgs__action__ExecuteMission_GetResult_Event__Sequence
{
  swarm_msgs__action__ExecuteMission_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package swarm_msgs.
typedef struct swarm_msgs__action__ExecuteMission_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  swarm_msgs__action__ExecuteMission_Feedback feedback;
} swarm_msgs__action__ExecuteMission_FeedbackMessage;

// Struct for a sequence of swarm_msgs__action__ExecuteMission_FeedbackMessage.
typedef struct swarm_msgs__action__ExecuteMission_FeedbackMessage__Sequence
{
  swarm_msgs__action__ExecuteMission_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__action__ExecuteMission_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWARM_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
