// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `imagein`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
tutorial_interfaces__srv__IfAlgorhmit_Request__init(tutorial_interfaces__srv__IfAlgorhmit_Request * msg)
{
  if (!msg) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__init(&msg->imagein)) {
    tutorial_interfaces__srv__IfAlgorhmit_Request__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Request__fini(tutorial_interfaces__srv__IfAlgorhmit_Request * msg)
{
  if (!msg) {
    return;
  }
  // imagein
  sensor_msgs__msg__Image__fini(&msg->imagein);
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Request__are_equal(const tutorial_interfaces__srv__IfAlgorhmit_Request * lhs, const tutorial_interfaces__srv__IfAlgorhmit_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->imagein), &(rhs->imagein)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Request__copy(
  const tutorial_interfaces__srv__IfAlgorhmit_Request * input,
  tutorial_interfaces__srv__IfAlgorhmit_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__copy(
      &(input->imagein), &(output->imagein)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__srv__IfAlgorhmit_Request *
tutorial_interfaces__srv__IfAlgorhmit_Request__create()
{
  tutorial_interfaces__srv__IfAlgorhmit_Request * msg = (tutorial_interfaces__srv__IfAlgorhmit_Request *)malloc(sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request));
  bool success = tutorial_interfaces__srv__IfAlgorhmit_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Request__destroy(tutorial_interfaces__srv__IfAlgorhmit_Request * msg)
{
  if (msg) {
    tutorial_interfaces__srv__IfAlgorhmit_Request__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__init(tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__srv__IfAlgorhmit_Request * data = NULL;
  if (size) {
    data = (tutorial_interfaces__srv__IfAlgorhmit_Request *)calloc(size, sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__IfAlgorhmit_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__IfAlgorhmit_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__fini(tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__srv__IfAlgorhmit_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence *
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__create(size_t size)
{
  tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * array = (tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence *)malloc(sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__destroy(tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * array)
{
  if (array) {
    tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__are_equal(const tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * lhs, const tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__IfAlgorhmit_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence__copy(
  const tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * input,
  tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request);
    tutorial_interfaces__srv__IfAlgorhmit_Request * data =
      (tutorial_interfaces__srv__IfAlgorhmit_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__IfAlgorhmit_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__IfAlgorhmit_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__IfAlgorhmit_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `imageout`
// already included above
// #include "sensor_msgs/msg/detail/image__functions.h"
// Member `targetpointout`
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__functions.h"
// Member `lasertrackout`
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__functions.h"

bool
tutorial_interfaces__srv__IfAlgorhmit_Response__init(tutorial_interfaces__srv__IfAlgorhmit_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  // imageout
  if (!sensor_msgs__msg__Image__init(&msg->imageout)) {
    tutorial_interfaces__srv__IfAlgorhmit_Response__fini(msg);
    return false;
  }
  // targetpointout
  if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__init(&msg->targetpointout, 0)) {
    tutorial_interfaces__srv__IfAlgorhmit_Response__fini(msg);
    return false;
  }
  // lasertrackout
  if (!tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__init(&msg->lasertrackout, 0)) {
    tutorial_interfaces__srv__IfAlgorhmit_Response__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Response__fini(tutorial_interfaces__srv__IfAlgorhmit_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  // imageout
  sensor_msgs__msg__Image__fini(&msg->imageout);
  // targetpointout
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__fini(&msg->targetpointout);
  // lasertrackout
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__fini(&msg->lasertrackout);
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Response__are_equal(const tutorial_interfaces__srv__IfAlgorhmit_Response * lhs, const tutorial_interfaces__srv__IfAlgorhmit_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  // imageout
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->imageout), &(rhs->imageout)))
  {
    return false;
  }
  // targetpointout
  if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__are_equal(
      &(lhs->targetpointout), &(rhs->targetpointout)))
  {
    return false;
  }
  // lasertrackout
  if (!tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__are_equal(
      &(lhs->lasertrackout), &(rhs->lasertrackout)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Response__copy(
  const tutorial_interfaces__srv__IfAlgorhmit_Response * input,
  tutorial_interfaces__srv__IfAlgorhmit_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  // imageout
  if (!sensor_msgs__msg__Image__copy(
      &(input->imageout), &(output->imageout)))
  {
    return false;
  }
  // targetpointout
  if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__copy(
      &(input->targetpointout), &(output->targetpointout)))
  {
    return false;
  }
  // lasertrackout
  if (!tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__copy(
      &(input->lasertrackout), &(output->lasertrackout)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__srv__IfAlgorhmit_Response *
tutorial_interfaces__srv__IfAlgorhmit_Response__create()
{
  tutorial_interfaces__srv__IfAlgorhmit_Response * msg = (tutorial_interfaces__srv__IfAlgorhmit_Response *)malloc(sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response));
  bool success = tutorial_interfaces__srv__IfAlgorhmit_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Response__destroy(tutorial_interfaces__srv__IfAlgorhmit_Response * msg)
{
  if (msg) {
    tutorial_interfaces__srv__IfAlgorhmit_Response__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__init(tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__srv__IfAlgorhmit_Response * data = NULL;
  if (size) {
    data = (tutorial_interfaces__srv__IfAlgorhmit_Response *)calloc(size, sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__IfAlgorhmit_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__IfAlgorhmit_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__fini(tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__srv__IfAlgorhmit_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence *
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__create(size_t size)
{
  tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * array = (tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence *)malloc(sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__destroy(tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * array)
{
  if (array) {
    tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__are_equal(const tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * lhs, const tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__IfAlgorhmit_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence__copy(
  const tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * input,
  tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response);
    tutorial_interfaces__srv__IfAlgorhmit_Response * data =
      (tutorial_interfaces__srv__IfAlgorhmit_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__IfAlgorhmit_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__IfAlgorhmit_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__IfAlgorhmit_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
