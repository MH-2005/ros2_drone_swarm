// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice

#include "swarm_msgs/srv/detail/change_formation__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__ChangeFormation__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf2, 0x53, 0x85, 0xa3, 0xdb, 0x97, 0x0f, 0x6f,
      0x5f, 0xfb, 0x97, 0xbc, 0x31, 0xb5, 0x66, 0xf9,
      0x3f, 0x17, 0xea, 0x09, 0xbb, 0xdc, 0x26, 0x69,
      0x8e, 0x02, 0x80, 0x1f, 0x86, 0x52, 0xd3, 0x97,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__ChangeFormation_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x26, 0xe0, 0xda, 0x75, 0xe6, 0xf8, 0xa7, 0x86,
      0xbf, 0xd8, 0x62, 0x91, 0xbe, 0xa6, 0x06, 0x8c,
      0xf1, 0x23, 0x0b, 0x37, 0x45, 0x01, 0xa5, 0x66,
      0x2c, 0x1c, 0xa6, 0x09, 0xda, 0x19, 0xfe, 0xec,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__ChangeFormation_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf2, 0x16, 0xdf, 0xca, 0x83, 0x39, 0x43, 0x86,
      0xdd, 0xd3, 0xee, 0xc0, 0x21, 0x00, 0xb7, 0x4d,
      0xc4, 0xc6, 0x82, 0x3f, 0xcb, 0x74, 0xda, 0xcc,
      0x8e, 0x51, 0xeb, 0xe9, 0x03, 0xc8, 0xe4, 0x34,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__srv__ChangeFormation_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd9, 0x58, 0x64, 0x3b, 0x8e, 0xf1, 0x54, 0x0a,
      0xde, 0xe8, 0x0f, 0x8c, 0x0b, 0xed, 0x71, 0x7e,
      0xa0, 0x85, 0x51, 0x75, 0xe5, 0xa7, 0xc4, 0xa4,
      0x99, 0x96, 0x89, 0x7c, 0x0e, 0x4a, 0x16, 0xc4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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

static char swarm_msgs__srv__ChangeFormation__TYPE_NAME[] = "swarm_msgs/srv/ChangeFormation";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char swarm_msgs__srv__ChangeFormation_Event__TYPE_NAME[] = "swarm_msgs/srv/ChangeFormation_Event";
static char swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME[] = "swarm_msgs/srv/ChangeFormation_Request";
static char swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME[] = "swarm_msgs/srv/ChangeFormation_Response";

// Define type names, field names, and default values
static char swarm_msgs__srv__ChangeFormation__FIELD_NAME__request_message[] = "request_message";
static char swarm_msgs__srv__ChangeFormation__FIELD_NAME__response_message[] = "response_message";
static char swarm_msgs__srv__ChangeFormation__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__ChangeFormation__FIELDS[] = {
  {
    {swarm_msgs__srv__ChangeFormation__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {swarm_msgs__srv__ChangeFormation_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swarm_msgs__srv__ChangeFormation__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__ChangeFormation__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__ChangeFormation__TYPE_NAME, 30, 30},
      {swarm_msgs__srv__ChangeFormation__FIELDS, 3, 3},
    },
    {swarm_msgs__srv__ChangeFormation__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = swarm_msgs__srv__ChangeFormation_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = swarm_msgs__srv__ChangeFormation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = swarm_msgs__srv__ChangeFormation_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__formation_type[] = "formation_type";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__orientation[] = "orientation";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__size[] = "size";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__altitude[] = "altitude";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_x[] = "move_x";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_y[] = "move_y";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_z[] = "move_z";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_x[] = "rotate_x";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_y[] = "rotate_y";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_z[] = "rotate_z";
static char swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__execute_simultaneously[] = "execute_simultaneously";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__ChangeFormation_Request__FIELDS[] = {
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__formation_type, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__orientation, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__size, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__altitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__move_z, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__rotate_z, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__FIELD_NAME__execute_simultaneously, 22, 22},
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
swarm_msgs__srv__ChangeFormation_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
      {swarm_msgs__srv__ChangeFormation_Request__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__success[] = "success";
static char swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__message[] = "message";
static char swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__execution_time[] = "execution_time";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__ChangeFormation_Response__FIELDS[] = {
  {
    {swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Response__FIELD_NAME__execution_time, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__ChangeFormation_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
      {swarm_msgs__srv__ChangeFormation_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__info[] = "info";
static char swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__request[] = "request";
static char swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field swarm_msgs__srv__ChangeFormation_Event__FIELDS[] = {
  {
    {swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swarm_msgs__srv__ChangeFormation_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__srv__ChangeFormation_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__srv__ChangeFormation_Event__TYPE_NAME, 36, 36},
      {swarm_msgs__srv__ChangeFormation_Event__FIELDS, 3, 3},
    },
    {swarm_msgs__srv__ChangeFormation_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = swarm_msgs__srv__ChangeFormation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = swarm_msgs__srv__ChangeFormation_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string formation_type\n"
  "string orientation\n"
  "float64 size\n"
  "float64 altitude\n"
  "float64 move_x\n"
  "float64 move_y\n"
  "float64 move_z\n"
  "float64 rotate_x\n"
  "float64 rotate_y\n"
  "float64 rotate_z\n"
  "bool execute_simultaneously\n"
  "---\n"
  "bool success\n"
  "string message\n"
  "float64 execution_time";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__ChangeFormation__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__ChangeFormation__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 250, 250},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__ChangeFormation_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__ChangeFormation_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__ChangeFormation_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__ChangeFormation_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__srv__ChangeFormation_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__srv__ChangeFormation_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__ChangeFormation__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__ChangeFormation__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *swarm_msgs__srv__ChangeFormation_Event__get_individual_type_description_source(NULL);
    sources[4] = *swarm_msgs__srv__ChangeFormation_Request__get_individual_type_description_source(NULL);
    sources[5] = *swarm_msgs__srv__ChangeFormation_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__ChangeFormation_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__ChangeFormation_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__ChangeFormation_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__ChangeFormation_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__srv__ChangeFormation_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__srv__ChangeFormation_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *swarm_msgs__srv__ChangeFormation_Request__get_individual_type_description_source(NULL);
    sources[4] = *swarm_msgs__srv__ChangeFormation_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
