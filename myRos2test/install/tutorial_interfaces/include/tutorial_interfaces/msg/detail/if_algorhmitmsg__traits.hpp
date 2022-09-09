// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/if_algorhmitmsg__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'imageout'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'targetpointout'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__traits.hpp"
// Member 'lasertrackout'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::msg::IfAlgorhmitmsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: imageout
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imageout:\n";
    to_yaml(msg.imageout, out, indentation + 2);
  }

  // member: targetpointout
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.targetpointout.size() == 0) {
      out << "targetpointout: []\n";
    } else {
      out << "targetpointout:\n";
      for (auto item : msg.targetpointout) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: lasertrackout
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lasertrackout.size() == 0) {
      out << "lasertrackout: []\n";
    } else {
      out << "lasertrackout:\n";
      for (auto item : msg.lasertrackout) {
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

inline std::string to_yaml(const tutorial_interfaces::msg::IfAlgorhmitmsg & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::msg::IfAlgorhmitmsg>()
{
  return "tutorial_interfaces::msg::IfAlgorhmitmsg";
}

template<>
inline const char * name<tutorial_interfaces::msg::IfAlgorhmitmsg>()
{
  return "tutorial_interfaces/msg/IfAlgorhmitmsg";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::IfAlgorhmitmsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::IfAlgorhmitmsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::msg::IfAlgorhmitmsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__TRAITS_HPP_
