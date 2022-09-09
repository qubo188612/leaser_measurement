// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitcloud__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'lasertrackoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint4f__traits.hpp"
// Member 'targetpointoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmitcloud & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: lasertrackoutcloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lasertrackoutcloud.size() == 0) {
      out << "lasertrackoutcloud: []\n";
    } else {
      out << "lasertrackoutcloud:\n";
      for (auto item : msg.lasertrackoutcloud) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: targetpointoutcloud
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.targetpointoutcloud.size() == 0) {
      out << "targetpointoutcloud: []\n";
    } else {
      out << "targetpointoutcloud:\n";
      for (auto item : msg.targetpointoutcloud) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: solderjoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "solderjoints: ";
    value_to_yaml(msg.solderjoints, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmitcloud & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmitcloud>()
{
  return "tutorial_interfaces::msg::IfAlgorhmitcloud";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmitcloud>()
{
  return "tutorial_interfaces/msg/IfAlgorhmitcloud";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitcloud>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitcloud>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmitcloud>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__TRAITS_HPP_
