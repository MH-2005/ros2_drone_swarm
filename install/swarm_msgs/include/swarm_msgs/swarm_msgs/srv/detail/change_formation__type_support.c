// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "swarm_msgs/srv/detail/change_formation__rosidl_typesupport_introspection_c.h"
#include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "swarm_msgs/srv/detail/change_formation__functions.h"
#include "swarm_msgs/srv/detail/change_formation__struct.h"


// Include directives for member types
// Member `formation_type`
// Member `orientation`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__srv__ChangeFormation_Request__init(message_memory);
}

void swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_fini_function(void * message_memory)
{
  swarm_msgs__srv__ChangeFormation_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_member_array[11] = {
  {
    "formation_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, formation_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, orientation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "altitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, altitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, move_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, move_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "move_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, move_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotate_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, rotate_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotate_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, rotate_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotate_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, rotate_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "execute_simultaneously",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Request, execute_simultaneously),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_members = {
  "swarm_msgs__srv",  // message namespace
  "ChangeFormation_Request",  // message name
  11,  // number of fields
  sizeof(swarm_msgs__srv__ChangeFormation_Request),
  false,  // has_any_key_member_
  swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_member_array,  // message members
  swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle = {
  0,
  &swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__srv__ChangeFormation_Request__get_type_hash,
  &swarm_msgs__srv__ChangeFormation_Request__get_type_description,
  &swarm_msgs__srv__ChangeFormation_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Request)() {
  if (!swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/srv/detail/change_formation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/srv/detail/change_formation__functions.h"
// already included above
// #include "swarm_msgs/srv/detail/change_formation__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__srv__ChangeFormation_Response__init(message_memory);
}

void swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_fini_function(void * message_memory)
{
  swarm_msgs__srv__ChangeFormation_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "execution_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Response, execution_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_members = {
  "swarm_msgs__srv",  // message namespace
  "ChangeFormation_Response",  // message name
  3,  // number of fields
  sizeof(swarm_msgs__srv__ChangeFormation_Response),
  false,  // has_any_key_member_
  swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_member_array,  // message members
  swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle = {
  0,
  &swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__srv__ChangeFormation_Response__get_type_hash,
  &swarm_msgs__srv__ChangeFormation_Response__get_type_description,
  &swarm_msgs__srv__ChangeFormation_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Response)() {
  if (!swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "swarm_msgs/srv/detail/change_formation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "swarm_msgs/srv/detail/change_formation__functions.h"
// already included above
// #include "swarm_msgs/srv/detail/change_formation__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "swarm_msgs/srv/change_formation.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/srv/detail/change_formation__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swarm_msgs__srv__ChangeFormation_Event__init(message_memory);
}

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_fini_function(void * message_memory)
{
  swarm_msgs__srv__ChangeFormation_Event__fini(message_memory);
}

size_t swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__size_function__ChangeFormation_Event__request(
  const void * untyped_member)
{
  const swarm_msgs__srv__ChangeFormation_Request__Sequence * member =
    (const swarm_msgs__srv__ChangeFormation_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__request(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__srv__ChangeFormation_Request__Sequence * member =
    (const swarm_msgs__srv__ChangeFormation_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__request(
  void * untyped_member, size_t index)
{
  swarm_msgs__srv__ChangeFormation_Request__Sequence * member =
    (swarm_msgs__srv__ChangeFormation_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__fetch_function__ChangeFormation_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__srv__ChangeFormation_Request * item =
    ((const swarm_msgs__srv__ChangeFormation_Request *)
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__request(untyped_member, index));
  swarm_msgs__srv__ChangeFormation_Request * value =
    (swarm_msgs__srv__ChangeFormation_Request *)(untyped_value);
  *value = *item;
}

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__assign_function__ChangeFormation_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__srv__ChangeFormation_Request * item =
    ((swarm_msgs__srv__ChangeFormation_Request *)
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__request(untyped_member, index));
  const swarm_msgs__srv__ChangeFormation_Request * value =
    (const swarm_msgs__srv__ChangeFormation_Request *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__resize_function__ChangeFormation_Event__request(
  void * untyped_member, size_t size)
{
  swarm_msgs__srv__ChangeFormation_Request__Sequence * member =
    (swarm_msgs__srv__ChangeFormation_Request__Sequence *)(untyped_member);
  swarm_msgs__srv__ChangeFormation_Request__Sequence__fini(member);
  return swarm_msgs__srv__ChangeFormation_Request__Sequence__init(member, size);
}

size_t swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__size_function__ChangeFormation_Event__response(
  const void * untyped_member)
{
  const swarm_msgs__srv__ChangeFormation_Response__Sequence * member =
    (const swarm_msgs__srv__ChangeFormation_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__response(
  const void * untyped_member, size_t index)
{
  const swarm_msgs__srv__ChangeFormation_Response__Sequence * member =
    (const swarm_msgs__srv__ChangeFormation_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__response(
  void * untyped_member, size_t index)
{
  swarm_msgs__srv__ChangeFormation_Response__Sequence * member =
    (swarm_msgs__srv__ChangeFormation_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__fetch_function__ChangeFormation_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const swarm_msgs__srv__ChangeFormation_Response * item =
    ((const swarm_msgs__srv__ChangeFormation_Response *)
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__response(untyped_member, index));
  swarm_msgs__srv__ChangeFormation_Response * value =
    (swarm_msgs__srv__ChangeFormation_Response *)(untyped_value);
  *value = *item;
}

void swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__assign_function__ChangeFormation_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  swarm_msgs__srv__ChangeFormation_Response * item =
    ((swarm_msgs__srv__ChangeFormation_Response *)
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__response(untyped_member, index));
  const swarm_msgs__srv__ChangeFormation_Response * value =
    (const swarm_msgs__srv__ChangeFormation_Response *)(untyped_value);
  *item = *value;
}

bool swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__resize_function__ChangeFormation_Event__response(
  void * untyped_member, size_t size)
{
  swarm_msgs__srv__ChangeFormation_Response__Sequence * member =
    (swarm_msgs__srv__ChangeFormation_Response__Sequence *)(untyped_member);
  swarm_msgs__srv__ChangeFormation_Response__Sequence__fini(member);
  return swarm_msgs__srv__ChangeFormation_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swarm_msgs__srv__ChangeFormation_Event, info),  // bytes offset in struct
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
    offsetof(swarm_msgs__srv__ChangeFormation_Event, request),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__size_function__ChangeFormation_Event__request,  // size() function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__request,  // get_const(index) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__request,  // get(index) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__fetch_function__ChangeFormation_Event__request,  // fetch(index, &value) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__assign_function__ChangeFormation_Event__request,  // assign(index, value) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__resize_function__ChangeFormation_Event__request  // resize(index) function pointer
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
    offsetof(swarm_msgs__srv__ChangeFormation_Event, response),  // bytes offset in struct
    NULL,  // default value
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__size_function__ChangeFormation_Event__response,  // size() function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_const_function__ChangeFormation_Event__response,  // get_const(index) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__get_function__ChangeFormation_Event__response,  // get(index) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__fetch_function__ChangeFormation_Event__response,  // fetch(index, &value) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__assign_function__ChangeFormation_Event__response,  // assign(index, value) function pointer
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__resize_function__ChangeFormation_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_members = {
  "swarm_msgs__srv",  // message namespace
  "ChangeFormation_Event",  // message name
  3,  // number of fields
  sizeof(swarm_msgs__srv__ChangeFormation_Event),
  false,  // has_any_key_member_
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_member_array,  // message members
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_type_support_handle = {
  0,
  &swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_members,
  get_message_typesupport_handle_function,
  &swarm_msgs__srv__ChangeFormation_Event__get_type_hash,
  &swarm_msgs__srv__ChangeFormation_Event__get_type_description,
  &swarm_msgs__srv__ChangeFormation_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Event)() {
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Request)();
  swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Response)();
  if (!swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_type_support_handle.typesupport_identifier) {
    swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "swarm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "swarm_msgs/srv/detail/change_formation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_members = {
  "swarm_msgs__srv",  // service namespace
  "ChangeFormation",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle,
  NULL,  // response message
  // swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle
  NULL  // event_message
  // swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle
};


static rosidl_service_type_support_t swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_type_support_handle = {
  0,
  &swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_members,
  get_service_typesupport_handle_function,
  &swarm_msgs__srv__ChangeFormation_Request__rosidl_typesupport_introspection_c__ChangeFormation_Request_message_type_support_handle,
  &swarm_msgs__srv__ChangeFormation_Response__rosidl_typesupport_introspection_c__ChangeFormation_Response_message_type_support_handle,
  &swarm_msgs__srv__ChangeFormation_Event__rosidl_typesupport_introspection_c__ChangeFormation_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    srv,
    ChangeFormation
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    swarm_msgs,
    srv,
    ChangeFormation
  ),
  &swarm_msgs__srv__ChangeFormation__get_type_hash,
  &swarm_msgs__srv__ChangeFormation__get_type_description,
  &swarm_msgs__srv__ChangeFormation__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swarm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation)(void) {
  if (!swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_type_support_handle.typesupport_identifier) {
    swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swarm_msgs, srv, ChangeFormation_Event)()->data;
  }

  return &swarm_msgs__srv__detail__change_formation__rosidl_typesupport_introspection_c__ChangeFormation_service_type_support_handle;
}
