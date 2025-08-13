// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swarm_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swarm_msgs/msg/formation_command.h"


#ifndef SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_
#define SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_

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
// Member 'center_point'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'translation'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/FormationCommand in the package swarm_msgs.
typedef struct swarm_msgs__msg__FormationCommand
{
  rosidl_runtime_c__String formation_type;
  rosidl_runtime_c__String orientation;
  double size;
  double altitude;
  double spacing;
  geometry_msgs__msg__Point center_point;
  double rotation_angle;
  geometry_msgs__msg__Vector3 translation;
} swarm_msgs__msg__FormationCommand;

// Struct for a sequence of swarm_msgs__msg__FormationCommand.
typedef struct swarm_msgs__msg__FormationCommand__Sequence
{
  swarm_msgs__msg__FormationCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swarm_msgs__msg__FormationCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWARM_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_
