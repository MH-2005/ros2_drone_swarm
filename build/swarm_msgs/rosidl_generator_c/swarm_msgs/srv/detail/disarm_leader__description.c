// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice

#include "swarm_msgs/srv/detail/disarm_leader__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__DisarmLeader__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0c, 0x43, 0x0b, 0xab, 0x0f, 0x0a, 0x07, 0xd4,
      0xb6, 0xd8, 0x17, 0x68, 0xef, 0x8d, 0x2d, 0x4c,
      0x3d, 0xd7, 0x70, 0xa6, 0xfb, 0x07, 0x69, 0x23,
      0xe9, 0x11, 0x82, 0x0a, 0xf8, 0xdd, 0xc1, 0x76,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__DisarmLeader_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x80, 0xfa, 0x40, 0xf1, 0x0e, 0xb4, 0x3e, 0x87,
      0x7b, 0x9c, 0x09, 0x61, 0xac, 0x66, 0x61, 0x33,
      0x03, 0xd1, 0xc8, 0x14, 0x27, 0xe8, 0xcd, 0x31,
      0x6a, 0x88, 0xd3, 0xed, 0x1a, 0x8b, 0x0e, 0xc7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__DisarmLeader_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb8, 0xbc, 0x60, 0x05, 0xd0, 0xec, 0xae, 0x9d,
      0x76, 0xea, 0x4e, 0xf7, 0x9f, 0x83, 0x54, 0xd2,
      0x5a, 0x8f, 0xb3, 0x14, 0x70, 0x85, 0xdf, 0xd5,
      0xff, 0xff, 0x85, 0x3d, 0xac, 0x68, 0x7c, 0x94,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__DisarmLeader_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0xc9, 0x6e, 0xb1, 0x71, 0x0f, 0xff, 0xf3,
      0x10, 0xa3, 0x85, 0xb9, 0x78, 0x00, 0x8d, 0x2a,
      0xb5, 0xf1, 0xe7, 0xc7, 0xa5, 0xcb, 0x18, 0x82,
      0xb8, 0x15, 0x85, 0x97, 0x25, 0xb7, 0x4e, 0xa7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char swarm_msgs__srv__DisarmLeader__TYPE_NAME[] = "swarm_msgs/srv/DisarmLeader";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char swarm_msgs__srv__DisarmLeader_Event__TYPE_NAME[] = "swarm_msgs/srv/DisarmLeader_Event";
static char swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME[] = "swarm_msgs/srv/DisarmLeader_Request";
static char swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME[] = "swarm_msgs/srv/DisarmLeader_Response";

// Define type names, field names, and default values
static char swarm_msgs__srv__DisarmLeader__FIELD_NAME__request_message[] = "request_message";
static char swarm_msgs__srv__DisarmLeader__FIELD_NAME__response_message[] = "response_message";
static char swarm_msgs__srv__DisarmLeader__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__DisarmLeader__FIELDS[] = {
  {
    {swarm_msgs__srv__DisarmLeader__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__DisarmLeader_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swarm_msgs__srv__DisarmLeader__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__DisarmLeader__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__DisarmLeader__TYPE_NAME, 27, 27},
      {swarm_msgs__srv__DisarmLeader__FIELDS, 3, 3},
    },
    {swarm_msgs__srv__DisarmLeader__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = swarm_msgs__srv__DisarmLeader_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = swarm_msgs__srv__DisarmLeader_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = swarm_msgs__srv__DisarmLeader_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__DisarmLeader_Request__FIELD_NAME__leader_id[] = "leader_id";
static char swarm_msgs__srv__DisarmLeader_Request__FIELD_NAME__return_to_home[] = "return_to_home";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__DisarmLeader_Request__FIELDS[] = {
  {
    {swarm_msgs__srv__DisarmLeader_Request__FIELD_NAME__leader_id, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Request__FIELD_NAME__return_to_home, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__DisarmLeader_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
      {swarm_msgs__srv__DisarmLeader_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__success[] = "success";
static char swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__old_leader_id[] = "old_leader_id";
static char swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__new_leader_id[] = "new_leader_id";
static char swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__DisarmLeader_Response__FIELDS[] = {
  {
    {swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__old_leader_id, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__new_leader_id, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__DisarmLeader_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
      {swarm_msgs__srv__DisarmLeader_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__info[] = "info";
static char swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__request[] = "request";
static char swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__DisarmLeader_Event__FIELDS[] = {
  {
    {swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swarm_msgs__srv__DisarmLeader_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__DisarmLeader_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__DisarmLeader_Event__TYPE_NAME, 33, 33},
      {swarm_msgs__srv__DisarmLeader_Event__FIELDS, 3, 3},
    },
    {swarm_msgs__srv__DisarmLeader_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = swarm_msgs__srv__DisarmLeader_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = swarm_msgs__srv__DisarmLeader_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 leader_id\n"
  "bool return_to_home\n"
  "---\n"
  "bool success\n"
  "int32 old_leader_id\n"
  "int32 new_leader_id\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__DisarmLeader__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__DisarmLeader__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 108, 108},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__DisarmLeader_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__DisarmLeader_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__DisarmLeader_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__DisarmLeader_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__DisarmLeader_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__DisarmLeader_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__DisarmLeader__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__DisarmLeader__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *swarm_msgs__srv__DisarmLeader_Event__get_individual_type_description_source(NULL);
    sources[4] = *swarm_msgs__srv__DisarmLeader_Request__get_individual_type_description_source(NULL);
    sources[5] = *swarm_msgs__srv__DisarmLeader_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__DisarmLeader_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__DisarmLeader_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__DisarmLeader_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__DisarmLeader_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__DisarmLeader_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__DisarmLeader_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *swarm_msgs__srv__DisarmLeader_Request__get_individual_type_description_source(NULL);
    sources[4] = *swarm_msgs__srv__DisarmLeader_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
