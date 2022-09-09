// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__BUILDER_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__BUILDER_HPP_

#include "tutorial_interfaces/srv/detail/if_algorhmit__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_IfAlgorhmit_Request_imagein
{
public:
  Init_IfAlgorhmit_Request_imagein()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::IfAlgorhmit_Request imagein(::tutorial_interfaces::srv::IfAlgorhmit_Request::_imagein_type arg)
  {
    msg_.imagein = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::IfAlgorhmit_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::IfAlgorhmit_Request>()
{
  return tutorial_interfaces::srv::builder::Init_IfAlgorhmit_Request_imagein();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_IfAlgorhmit_Response_lasertrackout
{
public:
  explicit Init_IfAlgorhmit_Response_lasertrackout(::tutorial_interfaces::srv::IfAlgorhmit_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::srv::IfAlgorhmit_Response lasertrackout(::tutorial_interfaces::srv::IfAlgorhmit_Response::_lasertrackout_type arg)
  {
    msg_.lasertrackout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::IfAlgorhmit_Response msg_;
};

class Init_IfAlgorhmit_Response_targetpointout
{
public:
  explicit Init_IfAlgorhmit_Response_targetpointout(::tutorial_interfaces::srv::IfAlgorhmit_Response & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmit_Response_lasertrackout targetpointout(::tutorial_interfaces::srv::IfAlgorhmit_Response::_targetpointout_type arg)
  {
    msg_.targetpointout = std::move(arg);
    return Init_IfAlgorhmit_Response_lasertrackout(msg_);
  }

private:
  ::tutorial_interfaces::srv::IfAlgorhmit_Response msg_;
};

class Init_IfAlgorhmit_Response_imageout
{
public:
  explicit Init_IfAlgorhmit_Response_imageout(::tutorial_interfaces::srv::IfAlgorhmit_Response & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmit_Response_targetpointout imageout(::tutorial_interfaces::srv::IfAlgorhmit_Response::_imageout_type arg)
  {
    msg_.imageout = std::move(arg);
    return Init_IfAlgorhmit_Response_targetpointout(msg_);
  }

private:
  ::tutorial_interfaces::srv::IfAlgorhmit_Response msg_;
};

class Init_IfAlgorhmit_Response_result
{
public:
  Init_IfAlgorhmit_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmit_Response_imageout result(::tutorial_interfaces::srv::IfAlgorhmit_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_IfAlgorhmit_Response_imageout(msg_);
  }

private:
  ::tutorial_interfaces::srv::IfAlgorhmit_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::IfAlgorhmit_Response>()
{
  return tutorial_interfaces::srv::builder::Init_IfAlgorhmit_Response_result();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__BUILDER_HPP_
