// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint2f.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.hpp"
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

void IfAlgorhmittargetpoint2f_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tutorial_interfaces::msg::IfAlgorhmittargetpoint2f(_init);
}

void IfAlgorhmittargetpoint2f_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f *>(message_memory);
  typed_message->~IfAlgorhmittargetpoint2f();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IfAlgorhmittargetpoint2f_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmittargetpoint2f, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmittargetpoint2f, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces::msg::IfAlgorhmittargetpoint2f, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IfAlgorhmittargetpoint2f_message_members = {
  "tutorial_interfaces::msg",  // message namespace
  "IfAlgorhmittargetpoint2f",  // message name
  3,  // number of fields
  sizeof(tutorial_interfaces::msg::IfAlgorhmittargetpoint2f),
  IfAlgorhmittargetpoint2f_message_member_array,  // message members
  IfAlgorhmittargetpoint2f_init_function,  // function to initialize message memory (memory has to be allocated)
  IfAlgorhmittargetpoint2f_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IfAlgorhmittargetpoint2f_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IfAlgorhmittargetpoint2f_message_members,
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
get_message_type_support_handle<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>()
{
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmittargetpoint2f_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tutorial_interfaces, msg, IfAlgorhmittargetpoint2f)() {
  return &::tutorial_interfaces::msg::rosidl_typesupport_introspection_cpp::IfAlgorhmittargetpoint2f_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
