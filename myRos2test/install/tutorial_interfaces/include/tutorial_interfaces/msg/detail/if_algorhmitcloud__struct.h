// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'lasertrackoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint4f__struct.h"
// Member 'targetpointoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__struct.h"

// Struct defined in msg/IfAlgorhmitcloud in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__IfAlgorhmitcloud
{
  std_msgs__msg__Header header;
  tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence lasertrackoutcloud;
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence targetpointoutcloud;
  bool solderjoints;
} tutorial_interfaces__msg__IfAlgorhmitcloud;

// Struct for a sequence of tutorial_interfaces__msg__IfAlgorhmitcloud.
typedef struct tutorial_interfaces__msg__IfAlgorhmitcloud__Sequence
{
  tutorial_interfaces__msg__IfAlgorhmitcloud * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__IfAlgorhmitcloud__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_H_
