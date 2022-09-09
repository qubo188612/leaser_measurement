// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint2f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmittargetpoint2f_name
{
public:
  explicit Init_IfAlgorhmittargetpoint2f_name(::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f name(::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f msg_;
};

class Init_IfAlgorhmittargetpoint2f_y
{
public:
  explicit Init_IfAlgorhmittargetpoint2f_y(::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmittargetpoint2f_name y(::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IfAlgorhmittargetpoint2f_name(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f msg_;
};

class Init_IfAlgorhmittargetpoint2f_x
{
public:
  Init_IfAlgorhmittargetpoint2f_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmittargetpoint2f_y x(::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IfAlgorhmittargetpoint2f_y(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmittargetpoint2f_x();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__BUILDER_HPP_
