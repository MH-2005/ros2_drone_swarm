// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swarm_msgs:srv/ChangeFormation.idl
// generated code does not contain a copyright notice
#include "swarm_msgs/srv/detail/change_formation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `formation_type`
// Member `orientation`
#include "rosidl_runtime_c/string_functions.h"

bool
swarm_msgs__srv__ChangeFormation_Request__init(swarm_msgs__srv__ChangeFormation_Request * msg)
{
  if (!msg) {
    return false;
  }
  // formation_type
  if (!rosidl_runtime_c__String__init(&msg->formation_type)) {
    swarm_msgs__srv__ChangeFormation_Request__fini(msg);
    return false;
  }
  // orientation
  if (!rosidl_runtime_c__String__init(&msg->orientation)) {
    swarm_msgs__srv__ChangeFormation_Request__fini(msg);
    return false;
  }
  // size
  // altitude
  // move_x
  // move_y
  // move_z
  // rotate_x
  // rotate_y
  // rotate_z
  // execute_simultaneously
  return true;
}

void
swarm_msgs__srv__ChangeFormation_Request__fini(swarm_msgs__srv__ChangeFormation_Request * msg)
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
  // move_x
  // move_y
  // move_z
  // rotate_x
  // rotate_y
  // rotate_z
  // execute_simultaneously
}

bool
swarm_msgs__srv__ChangeFormation_Request__are_equal(const swarm_msgs__srv__ChangeFormation_Request * lhs, const swarm_msgs__srv__ChangeFormation_Request * rhs)
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
  // move_x
  if (lhs->move_x != rhs->move_x) {
    return false;
  }
  // move_y
  if (lhs->move_y != rhs->move_y) {
    return false;
  }
  // move_z
  if (lhs->move_z != rhs->move_z) {
    return false;
  }
  // rotate_x
  if (lhs->rotate_x != rhs->rotate_x) {
    return false;
  }
  // rotate_y
  if (lhs->rotate_y != rhs->rotate_y) {
    return false;
  }
  // rotate_z
  if (lhs->rotate_z != rhs->rotate_z) {
    return false;
  }
  // execute_simultaneously
  if (lhs->execute_simultaneously != rhs->execute_simultaneously) {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Request__copy(
  const swarm_msgs__srv__ChangeFormation_Request * input,
  swarm_msgs__srv__ChangeFormation_Request * output)
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
  // move_x
  output->move_x = input->move_x;
  // move_y
  output->move_y = input->move_y;
  // move_z
  output->move_z = input->move_z;
  // rotate_x
  output->rotate_x = input->rotate_x;
  // rotate_y
  output->rotate_y = input->rotate_y;
  // rotate_z
  output->rotate_z = input->rotate_z;
  // execute_simultaneously
  output->execute_simultaneously = input->execute_simultaneously;
  return true;
}

swarm_msgs__srv__ChangeFormation_Request *
swarm_msgs__srv__ChangeFormation_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Request * msg = (swarm_msgs__srv__ChangeFormation_Request *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__ChangeFormation_Request));
  bool success = swarm_msgs__srv__ChangeFormation_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__ChangeFormation_Request__destroy(swarm_msgs__srv__ChangeFormation_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__ChangeFormation_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__ChangeFormation_Request__Sequence__init(swarm_msgs__srv__ChangeFormation_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Request * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__ChangeFormation_Request *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__ChangeFormation_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__ChangeFormation_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__ChangeFormation_Request__fini(&data[i - 1]);
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
swarm_msgs__srv__ChangeFormation_Request__Sequence__fini(swarm_msgs__srv__ChangeFormation_Request__Sequence * array)
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
      swarm_msgs__srv__ChangeFormation_Request__fini(&array->data[i]);
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

swarm_msgs__srv__ChangeFormation_Request__Sequence *
swarm_msgs__srv__ChangeFormation_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Request__Sequence * array = (swarm_msgs__srv__ChangeFormation_Request__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__ChangeFormation_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__ChangeFormation_Request__Sequence__destroy(swarm_msgs__srv__ChangeFormation_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__ChangeFormation_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__ChangeFormation_Request__Sequence__are_equal(const swarm_msgs__srv__ChangeFormation_Request__Sequence * lhs, const swarm_msgs__srv__ChangeFormation_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Request__Sequence__copy(
  const swarm_msgs__srv__ChangeFormation_Request__Sequence * input,
  swarm_msgs__srv__ChangeFormation_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__ChangeFormation_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__ChangeFormation_Request * data =
      (swarm_msgs__srv__ChangeFormation_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__ChangeFormation_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__ChangeFormation_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
swarm_msgs__srv__ChangeFormation_Response__init(swarm_msgs__srv__ChangeFormation_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    swarm_msgs__srv__ChangeFormation_Response__fini(msg);
    return false;
  }
  // execution_time
  return true;
}

void
swarm_msgs__srv__ChangeFormation_Response__fini(swarm_msgs__srv__ChangeFormation_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // execution_time
}

bool
swarm_msgs__srv__ChangeFormation_Response__are_equal(const swarm_msgs__srv__ChangeFormation_Response * lhs, const swarm_msgs__srv__ChangeFormation_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // execution_time
  if (lhs->execution_time != rhs->execution_time) {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Response__copy(
  const swarm_msgs__srv__ChangeFormation_Response * input,
  swarm_msgs__srv__ChangeFormation_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // execution_time
  output->execution_time = input->execution_time;
  return true;
}

swarm_msgs__srv__ChangeFormation_Response *
swarm_msgs__srv__ChangeFormation_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Response * msg = (swarm_msgs__srv__ChangeFormation_Response *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__ChangeFormation_Response));
  bool success = swarm_msgs__srv__ChangeFormation_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__ChangeFormation_Response__destroy(swarm_msgs__srv__ChangeFormation_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__ChangeFormation_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__ChangeFormation_Response__Sequence__init(swarm_msgs__srv__ChangeFormation_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Response * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__ChangeFormation_Response *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__ChangeFormation_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__ChangeFormation_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__ChangeFormation_Response__fini(&data[i - 1]);
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
swarm_msgs__srv__ChangeFormation_Response__Sequence__fini(swarm_msgs__srv__ChangeFormation_Response__Sequence * array)
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
      swarm_msgs__srv__ChangeFormation_Response__fini(&array->data[i]);
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

swarm_msgs__srv__ChangeFormation_Response__Sequence *
swarm_msgs__srv__ChangeFormation_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Response__Sequence * array = (swarm_msgs__srv__ChangeFormation_Response__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__ChangeFormation_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__ChangeFormation_Response__Sequence__destroy(swarm_msgs__srv__ChangeFormation_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__ChangeFormation_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__ChangeFormation_Response__Sequence__are_equal(const swarm_msgs__srv__ChangeFormation_Response__Sequence * lhs, const swarm_msgs__srv__ChangeFormation_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Response__Sequence__copy(
  const swarm_msgs__srv__ChangeFormation_Response__Sequence * input,
  swarm_msgs__srv__ChangeFormation_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__ChangeFormation_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__ChangeFormation_Response * data =
      (swarm_msgs__srv__ChangeFormation_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__ChangeFormation_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__ChangeFormation_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "swarm_msgs/srv/detail/change_formation__functions.h"

bool
swarm_msgs__srv__ChangeFormation_Event__init(swarm_msgs__srv__ChangeFormation_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    swarm_msgs__srv__ChangeFormation_Event__fini(msg);
    return false;
  }
  // request
  if (!swarm_msgs__srv__ChangeFormation_Request__Sequence__init(&msg->request, 0)) {
    swarm_msgs__srv__ChangeFormation_Event__fini(msg);
    return false;
  }
  // response
  if (!swarm_msgs__srv__ChangeFormation_Response__Sequence__init(&msg->response, 0)) {
    swarm_msgs__srv__ChangeFormation_Event__fini(msg);
    return false;
  }
  return true;
}

void
swarm_msgs__srv__ChangeFormation_Event__fini(swarm_msgs__srv__ChangeFormation_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  swarm_msgs__srv__ChangeFormation_Request__Sequence__fini(&msg->request);
  // response
  swarm_msgs__srv__ChangeFormation_Response__Sequence__fini(&msg->response);
}

bool
swarm_msgs__srv__ChangeFormation_Event__are_equal(const swarm_msgs__srv__ChangeFormation_Event * lhs, const swarm_msgs__srv__ChangeFormation_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!swarm_msgs__srv__ChangeFormation_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!swarm_msgs__srv__ChangeFormation_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Event__copy(
  const swarm_msgs__srv__ChangeFormation_Event * input,
  swarm_msgs__srv__ChangeFormation_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!swarm_msgs__srv__ChangeFormation_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!swarm_msgs__srv__ChangeFormation_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

swarm_msgs__srv__ChangeFormation_Event *
swarm_msgs__srv__ChangeFormation_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Event * msg = (swarm_msgs__srv__ChangeFormation_Event *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__ChangeFormation_Event));
  bool success = swarm_msgs__srv__ChangeFormation_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__ChangeFormation_Event__destroy(swarm_msgs__srv__ChangeFormation_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__ChangeFormation_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__ChangeFormation_Event__Sequence__init(swarm_msgs__srv__ChangeFormation_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Event * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__ChangeFormation_Event *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__ChangeFormation_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__ChangeFormation_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__ChangeFormation_Event__fini(&data[i - 1]);
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
swarm_msgs__srv__ChangeFormation_Event__Sequence__fini(swarm_msgs__srv__ChangeFormation_Event__Sequence * array)
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
      swarm_msgs__srv__ChangeFormation_Event__fini(&array->data[i]);
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

swarm_msgs__srv__ChangeFormation_Event__Sequence *
swarm_msgs__srv__ChangeFormation_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__ChangeFormation_Event__Sequence * array = (swarm_msgs__srv__ChangeFormation_Event__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__ChangeFormation_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__ChangeFormation_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__ChangeFormation_Event__Sequence__destroy(swarm_msgs__srv__ChangeFormation_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__ChangeFormation_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__ChangeFormation_Event__Sequence__are_equal(const swarm_msgs__srv__ChangeFormation_Event__Sequence * lhs, const swarm_msgs__srv__ChangeFormation_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__ChangeFormation_Event__Sequence__copy(
  const swarm_msgs__srv__ChangeFormation_Event__Sequence * input,
  swarm_msgs__srv__ChangeFormation_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__ChangeFormation_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__ChangeFormation_Event * data =
      (swarm_msgs__srv__ChangeFormation_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__ChangeFormation_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__ChangeFormation_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__ChangeFormation_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
