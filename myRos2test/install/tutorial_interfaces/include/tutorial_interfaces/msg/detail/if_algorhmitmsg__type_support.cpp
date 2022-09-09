// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tutorial_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IfAlgorhmitmsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tutorial_interfaces::msg::IfAlgorhmitmsg(_init);
}

void IfAlgorhmitmsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tutorial_interfaces::msg::IfAlgorhmitmsg *>(message_memory);
  typed_message->~IfAlgorhmitmsg();
}

size_t size_function__IfAlgorhmitmsg__targetpointout(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IfAlgorhmitmsg__targetpointout(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f> *>(untyped_member);
  return &member[index];
}

void * get_function__IfAlgorhmitmsg__targetpointout(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f> *>(untyped_member);
  return &member[index];
}

void resize_function__IfAlgorhmitmsg__targetpointout(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f> *>(untyped_member);
  member->resize(size);
}

size_t size_function__IfAlgorhmitmsg__lasertrackout(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IfAlgorhmitmsg__lasertrackout(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f> *>(untyped_member);
  return &member[index];
}

void * get_function__IfAlgorhmitmsg__lasertrackout(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f> *>(untyped_member);
  return &member[index];
}

void resize_function__IfAlgorhmitmsg__lasertrackout(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IfAlgorhmitmsg_message_member_array[5] = {
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitmsg, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imageout",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitmsg, imageout),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "targetpointout",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitmsg, targetpointout),  // bytes offset in struct
    nullptr,  // default value
    size_function__IfAlgorhmitmsg__targetpointout,  // size() function pointer
    get_const_function__IfAlgorhmitmsg__targetpointout,  // get_const(index) function pointer
    get_function__IfAlgorhmitmsg__targetpointout,  // get(index) function pointer
    resize_function__IfAlgorhmitmsg__targetpointout  // resize(index) function pointer
  },
  {
    "lasertrackout",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitpoint2f>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitmsg, lasertrackout),  // bytes offset in struct
    nullptr,  // default value
    size_function__IfAlgorhmitmsg__lasertrackout,  // size() function pointer
    get_const_function__IfAlgorhmitmsg__lasertrackout,  // get_const(index) function pointer
    get_function__IfAlgorhmitmsg__lasertrackout,  // get(index) function pointer
    resize_function__IfAlgorhmitmsg__lasertrackout  // resize(index) function pointer
  },
  {
    "solderjoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmitmsg, solderjoints),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IfAlgorhmitmsg_message_members = {
  "tutorial_interfaces::msg",  // message namespace
  "IfAlgorhmitmsg",  // message name
  5,  // number of fields
  sizeof(tutorial_interfaces::msg::IfAlgorhmitmsg),
  IfAlgorhmitmsg_message_member_array,  // message members
  IfAlgorhmitmsg_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmitmsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IfAlgorhmitmsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IfAlgorhmitmsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tutorial_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmitmsg>()
{
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitmsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tutorial_interfaces, msg, IfAlgorhmitmsg)() {
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmitmsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
