// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitmsg_solderjoints
{
public:
  explicit Init_IfAlgorhmitmsg_solderjoints(::tutorial_interfaces::msg::IfAlgorhmitmsg & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitmsg solderjoints(::tutorial_interfaces::msg::IfAlgorhmitmsg::_solderjoints_type arg)
  {
    msg_.solderjoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitmsg msg_;
};

class Init_IfAlgorhmitmsg_lasertrackout
{
public:
  explicit Init_IfAlgorhmitmsg_lasertrackout(::tutorial_interfaces::msg::IfAlgorhmitmsg & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitmsg_solderjoints lasertrackout(::tutorial_interfaces::msg::IfAlgorhmitmsg::_lasertrackout_type arg)
  {
    msg_.lasertrackout = std::move(arg);
    return Init_IfAlgorhmitmsg_solderjoints(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitmsg msg_;
};

class Init_IfAlgorhmitmsg_targetpointout
{
public:
  explicit Init_IfAlgorhmitmsg_targetpointout(::tutorial_interfaces::msg::IfAlgorhmitmsg & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitmsg_lasertrackout targetpointout(::tutorial_interfaces::msg::IfAlgorhmitmsg::_targetpointout_type arg)
  {
    msg_.targetpointout = std::move(arg);
    return Init_IfAlgorhmitmsg_lasertrackout(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitmsg msg_;
};

class Init_IfAlgorhmitmsg_imageout
{
public:
  explicit Init_IfAlgorhmitmsg_imageout(::tutorial_interfaces::msg::IfAlgorhmitmsg & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitmsg_targetpointout imageout(::tutorial_interfaces::msg::IfAlgorhmitmsg::_imageout_type arg)
  {
    msg_.imageout = std::move(arg);
    return Init_IfAlgorhmitmsg_targetpointout(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitmsg msg_;
};

class Init_IfAlgorhmitmsg_result
{
public:
  Init_IfAlgorhmitmsg_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitmsg_imageout result(::tutorial_interfaces::msg::IfAlgorhmitmsg::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_IfAlgorhmitmsg_imageout(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitmsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitmsg>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitmsg_result();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__BUILDER_HPP_
