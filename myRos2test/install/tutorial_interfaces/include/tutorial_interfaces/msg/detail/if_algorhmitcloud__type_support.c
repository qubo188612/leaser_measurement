// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `lasertrackoutcloud`
#include "tutorial_interfaces/msg/if_algorhmitpoint4f.h"
// Member `lasertrackoutcloud`
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint4f__rosidl_typesupport_introspection_c.h"
// Member `targetpointoutcloud`
#include "tutorial_interfaces/msg/if_algorhmittargetpoint4f.h"
// Member `targetpointoutcloud`
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmitcloud__init(message_memory);
}

void IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmitcloud__fini(message_memory);
}

size_t IfAlgorhmitcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint4f__lasertrackoutcloud(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint4f__lasertrackoutcloud(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint4f__lasertrackoutcloud(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmitcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint4f__lasertrackoutcloud(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmitpoint4f__Sequence__init(member, size);
}

size_t IfAlgorhmitcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint4f__targetpointoutcloud(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint4f__targetpointoutcloud(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint4f__targetpointoutcloud(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmitcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint4f__targetpointoutcloud(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitcloud, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lasertrackoutcloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitcloud, lasertrackoutcloud),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint4f__lasertrackoutcloud,  // size() function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint4f__lasertrackoutcloud,  // get_const(index) function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint4f__lasertrackoutcloud,  // get(index) function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint4f__lasertrackoutcloud  // resize(index) function pointer
  },
  {
    "targetpointoutcloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitcloud, targetpointoutcloud),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint4f__targetpointoutcloud,  // size() function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint4f__targetpointoutcloud,  // get_const(index) function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint4f__targetpointoutcloud,  // get(index) function pointer
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint4f__targetpointoutcloud  // resize(index) function pointer
  },
  {
    "solderjoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmitcloud, solderjoints),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmitcloud",  // message name
  4,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmitcloud),
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_member_array,  // message members
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_type_support_handle = {
  0,
  &IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitcloud)() {
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitpoint4f)();
  IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint4f)();
  if (!IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmitcloud__rosidl_typesupport_introspection_c__IfAlgorhmitcloud_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
