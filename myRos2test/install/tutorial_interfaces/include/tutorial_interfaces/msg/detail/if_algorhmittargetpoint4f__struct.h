// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint4f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT4F__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT4F__STRUCT_H_

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

// Struct defined in msg/IfAlgorhmittargetpoint4f in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmittargetpoint4f
{
  float x;
  float y;
  int32_t u;
  int32_t v;
  rosidl_runtime_c__String name;
} tutorial_interfaces__msg__IfAlgorhmittargetpoint4f;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmittargetpoint4f.
typedef struct tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT4F__STRUCT_H_
