// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmittargetpoint2f.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmittargetpoint2f & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmittargetpoint2f & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>()
{
  return "tutorial_interfaces::msg::IfAlgorhmittargetpoint2f";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>()
{
  return "tutorial_interfaces/msg/IfAlgorhmittargetpoint2f";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITTARGETPOINT2F__TRAITS_HPP_
