// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/srv/detail/if_algorhmit__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"


// Include directives for member types
// Member `imagein`
#include "sensor_msgs/msg/image.h"
// Member `imagein`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__srv__IfAlgorhmit_Request__init(message_memory);
}

void IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_fini_function(void * message_memory)
{
  tutorial_interfaces__srv__IfAlgorhmit_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_member_array[1] = {
  {
    "imagein",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__srv__IfAlgorhmit_Request, imagein),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_members = {
  "tutorial_interfaces__srv",  // message namespace
  "IfAlgorhmit_Request",  // message name
  1,  // number of fields
  sizeof(tutorial_interfaces__srv__IfAlgorhmit_Request),
  IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_member_array,  // message members
  IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_type_support_handle = {
  0,
  &IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Request)() {
  IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmit_Request__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"


// Include directives for member types
// Member `imageout`
// already included above
// #include "sensor_msgs/msg/image.h"
// Member `imageout`
// already included above
// #include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
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

void IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__srv__IfAlgorhmit_Response__init(message_memory);
}

void IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_fini_function(void * message_memory)
{
  tutorial_interfaces__srv__IfAlgorhmit_Response__fini(message_memory);
}

size_t IfAlgorhmit_Response__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint2f__targetpointout(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint2f__targetpointout(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint2f__targetpointout(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmit_Response__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint2f__targetpointout(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__init(member, size);
}

size_t IfAlgorhmit_Response__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint2f__lasertrackout(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return member->size;
}

const void * IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint2f__lasertrackout(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (const tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

void * IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint2f__lasertrackout(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  return &member->data[index];
}

bool IfAlgorhmit_Response__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint2f__lasertrackout(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence * member =
    (tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence *)(untyped_member);
  tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__fini(member);
  return tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_member_array[4] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__srv__IfAlgorhmit_Response, result),  // bytes offset in struct
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
    offsetof(tutorial_interfaces__srv__IfAlgorhmit_Response, imageout),  // bytes offset in struct
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
    offsetof(tutorial_interfaces__srv__IfAlgorhmit_Response, targetpointout),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__size_function__IfAlgorhmittargetpoint2f__targetpointout,  // size() function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmittargetpoint2f__targetpointout,  // get_const(index) function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_function__IfAlgorhmittargetpoint2f__targetpointout,  // get(index) function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmittargetpoint2f__targetpointout  // resize(index) function pointer
  },
  {
    "lasertrackout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__srv__IfAlgorhmit_Response, lasertrackout),  // bytes offset in struct
    NULL,  // default value
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__size_function__IfAlgorhmitpoint2f__lasertrackout,  // size() function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_const_function__IfAlgorhmitpoint2f__lasertrackout,  // get_const(index) function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__get_function__IfAlgorhmitpoint2f__lasertrackout,  // get(index) function pointer
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__resize_function__IfAlgorhmitpoint2f__lasertrackout  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_members = {
  "tutorial_interfaces__srv",  // message namespace
  "IfAlgorhmit_Response",  // message name
  4,  // number of fields
  sizeof(tutorial_interfaces__srv__IfAlgorhmit_Response),
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_member_array,  // message members
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_type_support_handle = {
  0,
  &IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Response)() {
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f)();
  IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, IfAlgorhmitpoint2f)();
  if (!IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_type_support_handle.typesupport_identifier) {
    IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IfAlgorhmit_Response__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_members = {
  "tutorial_interfaces__srv",  // service namespace
  "IfAlgorhmit",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_Request_message_type_support_handle,
  NULL  // response message
  // tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_Response_message_type_support_handle
};

static rosidl_service_type_support_t tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_type_support_handle = {
  0,
  &tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit)() {
  if (!tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_type_support_handle.typesupport_identifier) {
    tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, srv, IfAlgorhmit_Response)()->data;
  }

  return &tutorial_interfaces__srv__detail__if_algorhmit__rosidl_typesupport_introspection_c__IfAlgorhmit_service_type_support_handle;
}
