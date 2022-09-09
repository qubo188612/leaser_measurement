// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_H_
#define TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in srv/IfAlgorhmit in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__IfAlgorhmit_Request
{
  sensor_msgs__msg__Image imagein;
} tutorial_interfaces__srv__IfAlgorhmit_Request;

// Struct for a sequence of tutorial_interfaces__srv__IfAlgorhmit_Request.
typedef struct tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence
{
  tutorial_interfaces__srv__IfAlgorhmit_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__IfAlgorhmit_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'imageout'
// already included above
// #include "sensor_msgs/msg/detail/image__struct.h"
// Member 'targetpointout'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.h"
// Member 'lasertrackout'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__struct.h"

// Struct defined in srv/IfAlgorhmit in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__IfAlgorhmit_Response
{
  bool result;
  sensor_msgs__msg__Image imageout;
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence targetpointout;
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence lasertrackout;
} tutorial_interfaces__srv__IfAlgorhmit_Response;

// Struct for a sequence of tutorial_interfaces__srv__IfAlgorhmit_Response.
typedef struct tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence
{
  tutorial_interfaces__srv__IfAlgorhmit_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__IfAlgorhmit_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_H_
