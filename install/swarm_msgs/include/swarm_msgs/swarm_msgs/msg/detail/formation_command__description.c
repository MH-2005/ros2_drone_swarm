// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swarm_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

#include "swarm_msgs/msg/detail/formation_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swarm_msgs
const rosidl_type_hash_t *
swarm_msgs__msg__FormationCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0x70, 0xc8, 0xb7, 0xd4, 0xda, 0x9e, 0x0b,
      0x47, 0xcf, 0xcc, 0xd3, 0x4a, 0x92, 0x5d, 0xdc,
      0x00, 0x22, 0x7c, 0xe2, 0x7b, 0x04, 0xb7, 0x9b,
      0x71, 0x6e, 0x2b, 0x77, 0x4f, 0x6f, 0xdc, 0xec,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
#endif

static char swarm_msgs__msg__FormationCommand__TYPE_NAME[] = "swarm_msgs/msg/FormationCommand";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";

// Define type names, field names, and default values
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__formation_type[] = "formation_type";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__orientation[] = "orientation";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__size[] = "size";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__altitude[] = "altitude";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__spacing[] = "spacing";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__center_point[] = "center_point";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__rotation_angle[] = "rotation_angle";
static char swarm_msgs__msg__FormationCommand__FIELD_NAME__translation[] = "translation";

static rosidl_runtime_c__type_description__Field swarm_msgs__msg__FormationCommand__FIELDS[] = {
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__formation_type, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__orientation, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__size, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__altitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__spacing, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__center_point, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__rotation_angle, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swarm_msgs__msg__FormationCommand__FIELD_NAME__translation, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription swarm_msgs__msg__FormationCommand__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swarm_msgs__msg__FormationCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swarm_msgs__msg__FormationCommand__TYPE_NAME, 31, 31},
      {swarm_msgs__msg__FormationCommand__FIELDS, 8, 8},
    },
    {swarm_msgs__msg__FormationCommand__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string formation_type\n"
  "string orientation\n"
  "float64 size\n"
  "float64 altitude\n"
  "float64 spacing\n"
  "geometry_msgs/Point center_point\n"
  "float64 rotation_angle\n"
  "geometry_msgs/Vector3 translation";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swarm_msgs__msg__FormationCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swarm_msgs__msg__FormationCommand__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 177, 177},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swarm_msgs__msg__FormationCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swarm_msgs__msg__FormationCommand__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
