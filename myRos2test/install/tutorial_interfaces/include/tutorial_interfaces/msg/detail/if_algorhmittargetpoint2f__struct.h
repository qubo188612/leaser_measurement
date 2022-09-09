// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint2f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/IfAlgorhmittargetpoint2f in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmittargetpoint2f
{
  float x;
  float y;
  rosidl_runtime_c__String name;
} tutorial_interfaces__msg__IfAlgorhmittargetpoint2f;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmittargetpoint2f.
typedef struct tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__STRUCT_H_
