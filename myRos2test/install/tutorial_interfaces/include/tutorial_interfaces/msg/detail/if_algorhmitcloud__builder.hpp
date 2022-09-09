// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitcloud_solderjoints
{
public:
  explicit Init_IfAlgorhmitcloud_solderjoints(::tutorial_interfaces::msg::IfAlgorhmitcloud & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitcloud solderjoints(::tutorial_interfaces::msg::IfAlgorhmitcloud::_solderjoints_type arg)
  {
    msg_.solderjoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitcloud msg_;
};

class Init_IfAlgorhmitcloud_targetpointoutcloud
{
public:
  explicit Init_IfAlgorhmitcloud_targetpointoutcloud(::tutorial_interfaces::msg::IfAlgorhmitcloud & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitcloud_solderjoints targetpointoutcloud(::tutorial_interfaces::msg::IfAlgorhmitcloud::_targetpointoutcloud_type arg)
  {
    msg_.targetpointoutcloud = std::move(arg);
    return Init_IfAlgorhmitcloud_solderjoints(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitcloud msg_;
};

class Init_IfAlgorhmitcloud_lasertrackoutcloud
{
public:
  explicit Init_IfAlgorhmitcloud_lasertrackoutcloud(::tutorial_interfaces::msg::IfAlgorhmitcloud & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitcloud_targetpointoutcloud lasertrackoutcloud(::tutorial_interfaces::msg::IfAlgorhmitcloud::_lasertrackoutcloud_type arg)
  {
    msg_.lasertrackoutcloud = std::move(arg);
    return Init_IfAlgorhmitcloud_targetpointoutcloud(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitcloud msg_;
};

class Init_IfAlgorhmitcloud_header
{
public:
  Init_IfAlgorhmitcloud_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitcloud_lasertrackoutcloud header(::tutorial_interfaces::msg::IfAlgorhmitcloud::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IfAlgorhmitcloud_lasertrackoutcloud(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitcloud msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitcloud>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitcloud_header();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__BUILDER_HPP_
