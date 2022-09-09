// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint4f.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__init(message_memory);
}

void IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint4f__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_member_array[5] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "u",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f, u),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f, v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "IfAlgorhmittargetpoint4f",  // message name
  5,  // number of fields
  sizeof(tutorial_interfaces__msg__IfAlgorhmittargetpoint4f),
  IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_member_array,  // message members
  IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_type_support_handle = {
  0,
  &IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint4f)() {
  if (!IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmittargetpoint4f__rosidl_typesupport_introspection_c__IfAlgorhmittargetpoint4f_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
