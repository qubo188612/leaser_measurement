// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitpoint4f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITPOINT4F__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITPOINT4F__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitpoint4f__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_IfAlgorhmitpoint4f_v
{
public:
  explicit Init_IfAlgorhmitpoint4f_v(::tutorial_interfaces::msg::IfAlgorhmitpoint4f & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::IfAlgorhmitpoint4f v(::tutorial_interfaces::msg::IfAlgorhmitpoint4f::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitpoint4f msg_;
};

class Init_IfAlgorhmitpoint4f_u
{
public:
  explicit Init_IfAlgorhmitpoint4f_u(::tutorial_interfaces::msg::IfAlgorhmitpoint4f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitpoint4f_v u(::tutorial_interfaces::msg::IfAlgorhmitpoint4f::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_IfAlgorhmitpoint4f_v(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitpoint4f msg_;
};

class Init_IfAlgorhmitpoint4f_y
{
public:
  explicit Init_IfAlgorhmitpoint4f_y(::tutorial_interfaces::msg::IfAlgorhmitpoint4f & msg)
  : msg_(msg)
  {}
  Init_IfAlgorhmitpoint4f_u y(::tutorial_interfaces::msg::IfAlgorhmitpoint4f::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IfAlgorhmitpoint4f_u(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitpoint4f msg_;
};

class Init_IfAlgorhmitpoint4f_x
{
public:
  Init_IfAlgorhmitpoint4f_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IfAlgorhmitpoint4f_y x(::tutorial_interfaces::msg::IfAlgorhmitpoint4f::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IfAlgorhmitpoint4f_y(msg_);
  }

private:
  ::tutorial_interfaces::msg::IfAlgorhmitpoint4f msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::IfAlgorhmitpoint4f>()
{
  return tutorial_interfaces::msg::builder::Init_IfAlgorhmitpoint4f_x();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITPOINT4F__BUILDER_HPP_
