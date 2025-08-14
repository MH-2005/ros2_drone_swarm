// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from swarm_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
#include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "swarm_msgs/action/detail/execute_mission__functions.h"
#include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `mission_type`
// Member `path_file`
// Member `formation_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "geometry_msgs/msg/point.h"
// Member `waypoints`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_Goal__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_Goal__fini(message_memory);
}

size_t swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Goal__waypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Goal__waypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Goal__waypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Goal__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Goal__waypoints(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Goal__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Goal__waypoints(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Goal__waypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_member_array[6] = {
  {
    "mission_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, mission_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_file",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, path_file),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "formation_spacing",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, formation_spacing),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "formation_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, formation_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, waypoints),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Goal__waypoints,  // size() function pointer
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Goal__waypoints,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Goal__waypoints,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Goal__waypoints,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Goal__waypoints,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Goal__waypoints  // resize(index) function pointer
  },
  {
    "max_duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Goal, max_duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_Goal",  // message name
  6,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_Goal),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_Goal__get_type_hash,
  &swarm_msgs__action__ExecuteMission_Goal__get_type_description,
  &swarm_msgs__action__ExecuteMission_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Goal)() {
  swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `final_status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `final_positions`
#include "geometry_msgs/msg/pose.h"
// Member `final_positions`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_Result__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_Result__fini(message_memory);
}

size_t swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Result__final_positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Result__final_positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Result__final_positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Result__final_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose * item =
    ((const geometry_msgs__msg__Pose *)
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Result__final_positions(untyped_member, index));
  geometry_msgs__msg__Pose * value =
    (geometry_msgs__msg__Pose *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Result__final_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose * item =
    ((geometry_msgs__msg__Pose *)
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Result__final_positions(untyped_member, index));
  const geometry_msgs__msg__Pose * value =
    (const geometry_msgs__msg__Pose *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Result__final_positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_member_array[5] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "total_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Result, total_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints_completed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Result, waypoints_completed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "final_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Result, final_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "final_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Result, final_positions),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Result__final_positions,  // size() function pointer
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Result__final_positions,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Result__final_positions,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Result__final_positions,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Result__final_positions,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Result__final_positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_Result",  // message name
  5,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_Result),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_Result__get_type_hash,
  &swarm_msgs__action__ExecuteMission_Result__get_type_description,
  &swarm_msgs__action__ExecuteMission_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Result)() {
  swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `leader_pose`
// Member `follower_poses`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `leader_pose`
// Member `follower_poses`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `status_message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_Feedback__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_Feedback__fini(message_memory);
}

size_t swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Feedback__follower_poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Feedback__follower_poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Feedback__follower_poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Feedback__follower_poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose * item =
    ((const geometry_msgs__msg__Pose *)
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Feedback__follower_poses(untyped_member, index));
  geometry_msgs__msg__Pose * value =
    (geometry_msgs__msg__Pose *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Feedback__follower_poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose * item =
    ((geometry_msgs__msg__Pose *)
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Feedback__follower_poses(untyped_member, index));
  const geometry_msgs__msg__Pose * value =
    (const geometry_msgs__msg__Pose *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Feedback__follower_poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[6] = {
  {
    "current_waypoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, current_waypoint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_to_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, distance_to_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "elapsed_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, elapsed_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "leader_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, leader_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "follower_poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, follower_poses),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__size_function__ExecuteMission_Feedback__follower_poses,  // size() function pointer
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_Feedback__follower_poses,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__get_function__ExecuteMission_Feedback__follower_poses,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_Feedback__follower_poses,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_Feedback__follower_poses,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_Feedback__follower_poses  // resize(index) function pointer
  },
  {
    "status_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_Feedback, status_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_Feedback",  // message name
  6,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_Feedback),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_Feedback__get_type_hash,
  &swarm_msgs__action__ExecuteMission_Feedback__get_type_description,
  &swarm_msgs__action__ExecuteMission_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Feedback)() {
  swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "swarm_msgs/action/execute_mission.h"
// Member `goal`
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_SendGoal_Request__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_SendGoal_Request),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_SendGoal_Request__get_type_hash,
  &swarm_msgs__action__ExecuteMission_SendGoal_Request__get_type_description,
  &swarm_msgs__action__ExecuteMission_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Request)() {
  swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Goal)();
  if (!swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_SendGoal_Response__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_SendGoal_Response),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_SendGoal_Response__get_type_hash,
  &swarm_msgs__action__ExecuteMission_SendGoal_Response__get_type_description,
  &swarm_msgs__action__ExecuteMission_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Response)() {
  swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/action/execute_mission.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_SendGoal_Event__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Event__fini(message_memory);
}

size_t swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_SendGoal_Event__request(
  const void * untyped_member)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence * member =
    (swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Request * item =
    ((const swarm_msgs__action__ExecuteMission_SendGoal_Request *)
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__request(untyped_member, index));
  swarm_msgs__action__ExecuteMission_SendGoal_Request * value =
    (swarm_msgs__action__ExecuteMission_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Request * item =
    ((swarm_msgs__action__ExecuteMission_SendGoal_Request *)
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__request(untyped_member, index));
  const swarm_msgs__action__ExecuteMission_SendGoal_Request * value =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence * member =
    (swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence *)(untyped_member);
  swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence__fini(member);
  return swarm_msgs__action__ExecuteMission_SendGoal_Request__Sequence__init(member, size);
}

size_t swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_SendGoal_Event__response(
  const void * untyped_member)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence * member =
    (swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__action__ExecuteMission_SendGoal_Response * item =
    ((const swarm_msgs__action__ExecuteMission_SendGoal_Response *)
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__response(untyped_member, index));
  swarm_msgs__action__ExecuteMission_SendGoal_Response * value =
    (swarm_msgs__action__ExecuteMission_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Response * item =
    ((swarm_msgs__action__ExecuteMission_SendGoal_Response *)
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__response(untyped_member, index));
  const swarm_msgs__action__ExecuteMission_SendGoal_Response * value =
    (const swarm_msgs__action__ExecuteMission_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence * member =
    (swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence *)(untyped_member);
  swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence__fini(member);
  return swarm_msgs__action__ExecuteMission_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_SendGoal_Event__request,  // size() function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__request,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__request,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_SendGoal_Event__request,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_SendGoal_Event__request,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_SendGoal_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_SendGoal_Event__response,  // size() function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_SendGoal_Event__response,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_SendGoal_Event__response,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_SendGoal_Event__response,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_SendGoal_Event__response,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_SendGoal_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_SendGoal_Event),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_SendGoal_Event__get_type_hash,
  &swarm_msgs__action__ExecuteMission_SendGoal_Event__get_type_description,
  &swarm_msgs__action__ExecuteMission_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Event)() {
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Request)();
  swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Response)();
  if (!swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_members = {
  "swarm_msgs__action",  // service namespace
  "ExecuteMission_SendGoal",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle = {
  0,
  &swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle,
  &swarm_msgs__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle,
  &swarm_msgs__action__ExecuteMission_SendGoal_Event__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    action,
    ExecuteMission_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    action,
    ExecuteMission_SendGoal
  ),
  &swarm_msgs__action__ExecuteMission_SendGoal__get_type_hash,
  &swarm_msgs__action__ExecuteMission_SendGoal__get_type_description,
  &swarm_msgs__action__ExecuteMission_SendGoal__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal)(void) {
  if (!swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_SendGoal_Event)()->data;
  }

  return &swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_GetResult_Request__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_GetResult_Request),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_GetResult_Request__get_type_hash,
  &swarm_msgs__action__ExecuteMission_GetResult_Request__get_type_description,
  &swarm_msgs__action__ExecuteMission_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Request)() {
  swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "swarm_msgs/action/execute_mission.h"
// Member `result`
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_GetResult_Response__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_GetResult_Response),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_GetResult_Response__get_type_hash,
  &swarm_msgs__action__ExecuteMission_GetResult_Response__get_type_description,
  &swarm_msgs__action__ExecuteMission_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Response)() {
  swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Result)();
  if (!swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/action/execute_mission.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_GetResult_Event__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_GetResult_Event__fini(message_memory);
}

size_t swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_GetResult_Event__request(
  const void * untyped_member)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence * member =
    (swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Request * item =
    ((const swarm_msgs__action__ExecuteMission_GetResult_Request *)
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__request(untyped_member, index));
  swarm_msgs__action__ExecuteMission_GetResult_Request * value =
    (swarm_msgs__action__ExecuteMission_GetResult_Request *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__action__ExecuteMission_GetResult_Request * item =
    ((swarm_msgs__action__ExecuteMission_GetResult_Request *)
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__request(untyped_member, index));
  const swarm_msgs__action__ExecuteMission_GetResult_Request * value =
    (const swarm_msgs__action__ExecuteMission_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence * member =
    (swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence *)(untyped_member);
  swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence__fini(member);
  return swarm_msgs__action__ExecuteMission_GetResult_Request__Sequence__init(member, size);
}

size_t swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_GetResult_Event__response(
  const void * untyped_member)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence * member =
    (const swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence * member =
    (swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__action__ExecuteMission_GetResult_Response * item =
    ((const swarm_msgs__action__ExecuteMission_GetResult_Response *)
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__response(untyped_member, index));
  swarm_msgs__action__ExecuteMission_GetResult_Response * value =
    (swarm_msgs__action__ExecuteMission_GetResult_Response *)(untyped_value);
  *value = *item;
}

void swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__action__ExecuteMission_GetResult_Response * item =
    ((swarm_msgs__action__ExecuteMission_GetResult_Response *)
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__response(untyped_member, index));
  const swarm_msgs__action__ExecuteMission_GetResult_Response * value =
    (const swarm_msgs__action__ExecuteMission_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence * member =
    (swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence *)(untyped_member);
  swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence__fini(member);
  return swarm_msgs__action__ExecuteMission_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_GetResult_Event__request,  // size() function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__request,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__request,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_GetResult_Event__request,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_GetResult_Event__request,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_GetResult_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__size_function__ExecuteMission_GetResult_Event__response,  // size() function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__ExecuteMission_GetResult_Event__response,  // get_const(index) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__get_function__ExecuteMission_GetResult_Event__response,  // get(index) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__ExecuteMission_GetResult_Event__response,  // fetch(index, &value) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__ExecuteMission_GetResult_Event__response,  // assign(index, value) function pointer
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__ExecuteMission_GetResult_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_GetResult_Event),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_GetResult_Event__get_type_hash,
  &swarm_msgs__action__ExecuteMission_GetResult_Event__get_type_description,
  &swarm_msgs__action__ExecuteMission_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Event)() {
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Request)();
  swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Response)();
  if (!swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_members = {
  "swarm_msgs__action",  // service namespace
  "ExecuteMission_GetResult",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle = {
  0,
  &swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_members,
  get_service_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle,
  &swarm_msgs__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle,
  &swarm_msgs__action__ExecuteMission_GetResult_Event__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    action,
    ExecuteMission_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    action,
    ExecuteMission_GetResult
  ),
  &swarm_msgs__action__ExecuteMission_GetResult__get_type_hash,
  &swarm_msgs__action__ExecuteMission_GetResult__get_type_description,
  &swarm_msgs__action__ExecuteMission_GetResult__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult)(void) {
  if (!swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_GetResult_Event)()->data;
  }

  return &swarm_msgs__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__functions.h"
// already included above
// #include "swarm_msgs/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "swarm_msgs/action/execute_mission.h"
// Member `feedback`
// already included above
// #include "swarm_msgs/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__action__ExecuteMission_FeedbackMessage__init(message_memory);
}

void swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_fini_function(void * message_memory)
{
  swarm_msgs__action__ExecuteMission_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__action__ExecuteMission_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_members = {
  "swarm_msgs__action",  // message namespace
  "ExecuteMission_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(swarm_msgs__action__ExecuteMission_FeedbackMessage),
  false,  // has_any_key_member_
  swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array,  // message members
  swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle = {
  0,
  &swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__action__ExecuteMission_FeedbackMessage__get_type_hash,
  &swarm_msgs__action__ExecuteMission_FeedbackMessage__get_type_description,
  &swarm_msgs__action__ExecuteMission_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_FeedbackMessage)() {
  swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, action, ExecuteMission_Feedback)();
  if (!swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
