// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint4f.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__init(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // u
  // v
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // u
  // v
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__are_equal(const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * lhs, const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // u
  if (lhs->u != rhs->u) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__copy(
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * input,
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // u
  output->u = input->u;
  // v
  output->v = input->v;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__msg__IfAlgorhmittargetpoint4f *
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__create()
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * msg = (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f));
  bool success = tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__destroy(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * msg)
{
  if (msg) {
    tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(msg);
  }
  free(msg);
}


bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__init(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * data = NULL;
  if (size) {
    data = (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f *)calloc(size, sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(&data[i - 1]);
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
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__fini(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(&array->data[i]);
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

tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__create(size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * array = (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *)malloc(sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__destroy(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * array)
{
  if (array) {
    tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__fini(array);
  }
  free(array);
}

bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__are_equal(const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * lhs, const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__copy(
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * input,
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f);
    tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * data =
      (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(&data[i]);
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
    if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
