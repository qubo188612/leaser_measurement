// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__struct.h"


// Include directives for member types
// Member `imageout`
#include "sensor_msgs/msg/image.h"
// Member `imageout`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `targetpointout`
#include "tutorial_interfaces/msg/if_algorhmittargetpoint2f.h"
// Member `targetpointout`
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__rosidl_typesupport_introspection_c.h"
// Member `lasertrackout`
#include "tutorial_interfaces/msg/if_algorhmitpoint2f.h"
// Member `lasertrackout`
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmitmsg__init(message_memory);
}

void IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmitmsg__fini(message_memory);
}

size_t IfAlgorhmitmsg__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint2f__targetpointout(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint2f__targetpointout(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint2f__targetpointout(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmitmsg__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint2f__targetpointout(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__init(member, size);
}

size_t IfAlgorhmitmsg__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint2f__lasertrackout(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint2f__lasertrackout(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint2f__lasertrackout(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmitmsg__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint2f__lasertrackout(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_member_array[5] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitmsg, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imageout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitmsg, imageout),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "targetpointout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitmsg, targetpointout),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint2f__targetpointout,  // size() function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint2f__targetpointout,  // get_const(index) function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint2f__targetpointout,  // get(index) function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint2f__targetpointout  // resize(index) function pointer
  },
  {
    "lasertrackout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitmsg, lasertrackout),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint2f__lasertrackout,  // size() function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint2f__lasertrackout,  // get_const(index) function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint2f__lasertrackout,  // get(index) function pointer
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint2f__lasertrackout  // resize(index) function pointer
  },
  {
    "solderjoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitmsg, solderjoints),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmitmsg",  // message name
  5,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmitmsg),
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_member_array,  // message members
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_type_support_handle = {
  0,
  &IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitmsg)() {
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f)();
  IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitpoint2f)();
  if (!IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmitmsg__rosidl_typesupport_introspection_c__IfAlgorhmitmsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
