// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swarm_msgs:srv/DisarmLeader.idl
// generated code does not contain a copyright notice
#include "swarm_msgs/srv/detail/disarm_leader__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
swarm_msgs__srv__DisarmLeader_Request__init(swarm_msgs__srv__DisarmLeader_Request * msg)
{
  if (!msg) {
    return false;
  }
  // leader_id
  // return_to_home
  return true;
}

void
swarm_msgs__srv__DisarmLeader_Request__fini(swarm_msgs__srv__DisarmLeader_Request * msg)
{
  if (!msg) {
    return;
  }
  // leader_id
  // return_to_home
}

bool
swarm_msgs__srv__DisarmLeader_Request__are_equal(const swarm_msgs__srv__DisarmLeader_Request * lhs, const swarm_msgs__srv__DisarmLeader_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // leader_id
  if (lhs->leader_id != rhs->leader_id) {
    return false;
  }
  // return_to_home
  if (lhs->return_to_home != rhs->return_to_home) {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Request__copy(
  const swarm_msgs__srv__DisarmLeader_Request * input,
  swarm_msgs__srv__DisarmLeader_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // leader_id
  output->leader_id = input->leader_id;
  // return_to_home
  output->return_to_home = input->return_to_home;
  return true;
}

swarm_msgs__srv__DisarmLeader_Request *
swarm_msgs__srv__DisarmLeader_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Request * msg = (swarm_msgs__srv__DisarmLeader_Request *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__DisarmLeader_Request));
  bool success = swarm_msgs__srv__DisarmLeader_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__DisarmLeader_Request__destroy(swarm_msgs__srv__DisarmLeader_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__DisarmLeader_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__DisarmLeader_Request__Sequence__init(swarm_msgs__srv__DisarmLeader_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Request * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__DisarmLeader_Request *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__DisarmLeader_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__DisarmLeader_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__DisarmLeader_Request__fini(&data[i - 1]);
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
swarm_msgs__srv__DisarmLeader_Request__Sequence__fini(swarm_msgs__srv__DisarmLeader_Request__Sequence * array)
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
      swarm_msgs__srv__DisarmLeader_Request__fini(&array->data[i]);
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

swarm_msgs__srv__DisarmLeader_Request__Sequence *
swarm_msgs__srv__DisarmLeader_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Request__Sequence * array = (swarm_msgs__srv__DisarmLeader_Request__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__DisarmLeader_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__DisarmLeader_Request__Sequence__destroy(swarm_msgs__srv__DisarmLeader_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__DisarmLeader_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__DisarmLeader_Request__Sequence__are_equal(const swarm_msgs__srv__DisarmLeader_Request__Sequence * lhs, const swarm_msgs__srv__DisarmLeader_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Request__Sequence__copy(
  const swarm_msgs__srv__DisarmLeader_Request__Sequence * input,
  swarm_msgs__srv__DisarmLeader_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__DisarmLeader_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__DisarmLeader_Request * data =
      (swarm_msgs__srv__DisarmLeader_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__DisarmLeader_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__DisarmLeader_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
swarm_msgs__srv__DisarmLeader_Response__init(swarm_msgs__srv__DisarmLeader_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // old_leader_id
  // new_leader_id
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    swarm_msgs__srv__DisarmLeader_Response__fini(msg);
    return false;
  }
  return true;
}

void
swarm_msgs__srv__DisarmLeader_Response__fini(swarm_msgs__srv__DisarmLeader_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // old_leader_id
  // new_leader_id
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
swarm_msgs__srv__DisarmLeader_Response__are_equal(const swarm_msgs__srv__DisarmLeader_Response * lhs, const swarm_msgs__srv__DisarmLeader_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // old_leader_id
  if (lhs->old_leader_id != rhs->old_leader_id) {
    return false;
  }
  // new_leader_id
  if (lhs->new_leader_id != rhs->new_leader_id) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Response__copy(
  const swarm_msgs__srv__DisarmLeader_Response * input,
  swarm_msgs__srv__DisarmLeader_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // old_leader_id
  output->old_leader_id = input->old_leader_id;
  // new_leader_id
  output->new_leader_id = input->new_leader_id;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

swarm_msgs__srv__DisarmLeader_Response *
swarm_msgs__srv__DisarmLeader_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Response * msg = (swarm_msgs__srv__DisarmLeader_Response *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__DisarmLeader_Response));
  bool success = swarm_msgs__srv__DisarmLeader_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__DisarmLeader_Response__destroy(swarm_msgs__srv__DisarmLeader_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__DisarmLeader_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__DisarmLeader_Response__Sequence__init(swarm_msgs__srv__DisarmLeader_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Response * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__DisarmLeader_Response *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__DisarmLeader_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__DisarmLeader_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__DisarmLeader_Response__fini(&data[i - 1]);
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
swarm_msgs__srv__DisarmLeader_Response__Sequence__fini(swarm_msgs__srv__DisarmLeader_Response__Sequence * array)
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
      swarm_msgs__srv__DisarmLeader_Response__fini(&array->data[i]);
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

swarm_msgs__srv__DisarmLeader_Response__Sequence *
swarm_msgs__srv__DisarmLeader_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Response__Sequence * array = (swarm_msgs__srv__DisarmLeader_Response__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__DisarmLeader_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__DisarmLeader_Response__Sequence__destroy(swarm_msgs__srv__DisarmLeader_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__DisarmLeader_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__DisarmLeader_Response__Sequence__are_equal(const swarm_msgs__srv__DisarmLeader_Response__Sequence * lhs, const swarm_msgs__srv__DisarmLeader_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Response__Sequence__copy(
  const swarm_msgs__srv__DisarmLeader_Response__Sequence * input,
  swarm_msgs__srv__DisarmLeader_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__DisarmLeader_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__DisarmLeader_Response * data =
      (swarm_msgs__srv__DisarmLeader_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__DisarmLeader_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__DisarmLeader_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Response__copy(
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
// #include "swarm_msgs/srv/detail/disarm_leader__functions.h"

bool
swarm_msgs__srv__DisarmLeader_Event__init(swarm_msgs__srv__DisarmLeader_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    swarm_msgs__srv__DisarmLeader_Event__fini(msg);
    return false;
  }
  // request
  if (!swarm_msgs__srv__DisarmLeader_Request__Sequence__init(&msg->request, 0)) {
    swarm_msgs__srv__DisarmLeader_Event__fini(msg);
    return false;
  }
  // response
  if (!swarm_msgs__srv__DisarmLeader_Response__Sequence__init(&msg->response, 0)) {
    swarm_msgs__srv__DisarmLeader_Event__fini(msg);
    return false;
  }
  return true;
}

void
swarm_msgs__srv__DisarmLeader_Event__fini(swarm_msgs__srv__DisarmLeader_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  swarm_msgs__srv__DisarmLeader_Request__Sequence__fini(&msg->request);
  // response
  swarm_msgs__srv__DisarmLeader_Response__Sequence__fini(&msg->response);
}

bool
swarm_msgs__srv__DisarmLeader_Event__are_equal(const swarm_msgs__srv__DisarmLeader_Event * lhs, const swarm_msgs__srv__DisarmLeader_Event * rhs)
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
  if (!swarm_msgs__srv__DisarmLeader_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!swarm_msgs__srv__DisarmLeader_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Event__copy(
  const swarm_msgs__srv__DisarmLeader_Event * input,
  swarm_msgs__srv__DisarmLeader_Event * output)
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
  if (!swarm_msgs__srv__DisarmLeader_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!swarm_msgs__srv__DisarmLeader_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

swarm_msgs__srv__DisarmLeader_Event *
swarm_msgs__srv__DisarmLeader_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Event * msg = (swarm_msgs__srv__DisarmLeader_Event *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swarm_msgs__srv__DisarmLeader_Event));
  bool success = swarm_msgs__srv__DisarmLeader_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swarm_msgs__srv__DisarmLeader_Event__destroy(swarm_msgs__srv__DisarmLeader_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swarm_msgs__srv__DisarmLeader_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swarm_msgs__srv__DisarmLeader_Event__Sequence__init(swarm_msgs__srv__DisarmLeader_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Event * data = NULL;

  if (size) {
    data = (swarm_msgs__srv__DisarmLeader_Event *)allocator.zero_allocate(size, sizeof(swarm_msgs__srv__DisarmLeader_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swarm_msgs__srv__DisarmLeader_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swarm_msgs__srv__DisarmLeader_Event__fini(&data[i - 1]);
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
swarm_msgs__srv__DisarmLeader_Event__Sequence__fini(swarm_msgs__srv__DisarmLeader_Event__Sequence * array)
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
      swarm_msgs__srv__DisarmLeader_Event__fini(&array->data[i]);
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

swarm_msgs__srv__DisarmLeader_Event__Sequence *
swarm_msgs__srv__DisarmLeader_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swarm_msgs__srv__DisarmLeader_Event__Sequence * array = (swarm_msgs__srv__DisarmLeader_Event__Sequence *)allocator.allocate(sizeof(swarm_msgs__srv__DisarmLeader_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swarm_msgs__srv__DisarmLeader_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swarm_msgs__srv__DisarmLeader_Event__Sequence__destroy(swarm_msgs__srv__DisarmLeader_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swarm_msgs__srv__DisarmLeader_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swarm_msgs__srv__DisarmLeader_Event__Sequence__are_equal(const swarm_msgs__srv__DisarmLeader_Event__Sequence * lhs, const swarm_msgs__srv__DisarmLeader_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swarm_msgs__srv__DisarmLeader_Event__Sequence__copy(
  const swarm_msgs__srv__DisarmLeader_Event__Sequence * input,
  swarm_msgs__srv__DisarmLeader_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swarm_msgs__srv__DisarmLeader_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swarm_msgs__srv__DisarmLeader_Event * data =
      (swarm_msgs__srv__DisarmLeader_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swarm_msgs__srv__DisarmLeader_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swarm_msgs__srv__DisarmLeader_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swarm_msgs__srv__DisarmLeader_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
