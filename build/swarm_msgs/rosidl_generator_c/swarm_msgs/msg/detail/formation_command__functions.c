// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swarm_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice
#include "swarm_msgs/msg/detail/formation_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `formation_type`
// Member `orientation`
#include "rosidl_runtime_c/string_functions.h"
// Member `center_point`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `translation`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
swarm_msgs__msg__FormationCommand__init(swarm_msgs__msg__FormationCommand * msg)
{
  if (!msg) {
    return false;
  }
  // formation_type
  if (!rosidl_runtime_c__String__init(&msg->formation_type)) {
    swarm_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  // orientation
  if (!rosidl_runtime_c__String__init(&msg->orientation)) {
    swarm_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  // size
  // altitude
  // spacing
  // center_point
  if (!geometry_msgs__msg__Point__init(&msg->center_point)) {
    swarm_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  // rotation_angle
  // translation
  if (!geometry_msgs__msg__Vector3__init(&msg->translation)) {
    swarm_msgs__msg__FormationCommand__fini(msg);
    return false;
  }
  return true;
}

void
swarm_msgs__msg__FormationCommand__fini(swarm_msgs__msg__FormationCommand * msg)
{
  if (!msg) {
    return;
  }
  // formation_type
  rosidl_runtime_c__String__fini(&msg->formation_type);
  // orientation
  rosidl_runtime_c__String__fini(&msg->orientation);
  // size
  // altitude
  // spacing
  // center_point
  geometry_msgs__msg__Point__fini(&msg->center_point);
  // rotation_angle
  // translation
  geometry_msgs__msg__Vector3__fini(&msg->translation);
}

bool
swarm_msgs__msg__FormationCommand__are_equal(const swarm_msgs__msg__FormationCommand * lhs, const swarm_msgs__msg__FormationCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // formation_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->formation_type), &(rhs->formation_type)))
  {
    return false;
  }
  // orientation
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // spacing
  if (lhs->spacing != rhs->spacing) {
    return false;
  }
  // center_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center_point), &(rhs->center_point)))
  {
    return false;
  }
  // rotation_angle
  if (lhs->rotation_angle != rhs->rotation_angle) {
    return false;
  }
  // translation
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->translation), &(rhs->translation)))
  {
    return false;
  }
  return true;
}

bool
swarm_msgs__msg__FormationCommand__copy(
  const swarm_msgs__msg__FormationCommand * input,
  swarm_msgs__msg__FormationCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // formation_type
  if (!rosidl_runtime_c__String__copy(
      &(input->formation_type), &(output->formation_type)))
  {
    return false;
  }
  // orientation
  if (!rosidl_runtime_c__String__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  // size
  output->size = input->size;
  // altitude
  output->altitude = input->altitude;
  // spacing
  output->spacing = input->spacing;
  // center_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->center_point), &(output->center_point)))
  {
    return false;
  }
  // rotation_angle
  output->rotation_angle = input->rotation_angle;
  // translation
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->translation), &(output->translation)))
  {
    return false;
  }
  return true;
}

swarm_msgs__msg__FormationCommand *
swarm_msgs__msg__FormationCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__msg__FormationCommand * msg = (swarm_msgs__msg__FormationCommand *)allocator.allocate(sizeof(swarm_msgs__msg__FormationCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__msg__FormationCommand));
  bool success = swarm_msgs__msg__FormationCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__msg__FormationCommand__destroy(swarm_msgs__msg__FormationCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__msg__FormationCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__msg__FormationCommand__Sequence__init(swarm_msgs__msg__FormationCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__msg__FormationCommand * data = NULL;

  if (size) {
    data = (swarm_msgs__msg__FormationCommand *)allocator.zero_allocate(size, sizeof(swarm_msgs__msg__FormationCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__msg__FormationCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__msg__FormationCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
swarm_msgs__msg__FormationCommand__Sequence__fini(swarm_msgs__msg__FormationCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      swarm_msgs__msg__FormationCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

swarm_msgs__msg__FormationCommand__Sequence *
swarm_msgs__msg__FormationCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__msg__FormationCommand__Sequence * array = (swarm_msgs__msg__FormationCommand__Sequence *)allocator.allocate(sizeof(swarm_msgs__msg__FormationCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__msg__FormationCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__msg__FormationCommand__Sequence__destroy(swarm_msgs__msg__FormationCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__msg__FormationCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__msg__FormationCommand__Sequence__are_equal(const swarm_msgs__msg__FormationCommand__Sequence * lhs, const swarm_msgs__msg__FormationCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__msg__FormationCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__msg__FormationCommand__Sequence__copy(
  const swarm_msgs__msg__FormationCommand__Sequence * input,
  swarm_msgs__msg__FormationCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__msg__FormationCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__msg__FormationCommand * data =
      (swarm_msgs__msg__FormationCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__msg__FormationCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__msg__FormationCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__msg__FormationCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
