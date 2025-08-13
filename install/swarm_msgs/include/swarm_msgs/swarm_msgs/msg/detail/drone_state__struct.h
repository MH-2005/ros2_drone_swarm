// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swarm_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/drone_state.h"


#ifndef SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_
#define SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'role'
// Member 'status'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/DroneState in the package swarm_msgs.
typedef struct swarm_msgs__msg__DroneState
{
  int32_t drone_id;
  rosidl_runtime_c__String role;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist velocity;
  bool is_armed;
  bool is_connected;
  double battery_level;
  rosidl_runtime_c__String status;
} swarm_msgs__msg__DroneState;

// Struct for a sequence of swarm_msgs__msg__DroneState.
typedef struct swarm_msgs__msg__DroneState__Sequence
{
  swarm_msgs__msg__DroneState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__msg__DroneState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWARM_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_
