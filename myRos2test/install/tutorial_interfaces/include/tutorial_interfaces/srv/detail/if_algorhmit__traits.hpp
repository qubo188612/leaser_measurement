// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__TRAITS_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__TRAITS_HPP_

#include "tutorial_interfaces/srv/detail/if_algorhmit__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::srv::IfAlgorhmit_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: imagein
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imagein:\n";
    to_yaml(msg.imagein, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::srv::IfAlgorhmit_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::srv::IfAlgorhmit_Request>()
{
  return "tutorial_interfaces::srv::IfAlgorhmit_Request";
}

template<>
inline const char * name<tutorial_interfaces::srv::IfAlgorhmit_Request>()
{
  return "tutorial_interfaces/srv/IfAlgorhmit_Request";
}

template<>
struct has_fixed_size<tutorial_interfaces::srv::IfAlgorhmit_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<tutorial_interfaces::srv::IfAlgorhmit_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<tutorial_interfaces::srv::IfAlgorhmit_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'imageout'
// already included above
// #include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'targetpointout'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__traits.hpp"
// Member 'lasertrackout'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const tutorial_interfaces::srv::IfAlgorhmit_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const tutorial_interfaces::srv::IfAlgorhmit_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<tutorial_interfaces::srv::IfAlgorhmit_Response>()
{
  return "tutorial_interfaces::srv::IfAlgorhmit_Response";
}

template<>
inline const char * name<tutorial_interfaces::srv::IfAlgorhmit_Response>()
{
  return "tutorial_interfaces/srv/IfAlgorhmit_Response";
}

template<>
struct has_fixed_size<tutorial_interfaces::srv::IfAlgorhmit_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::srv::IfAlgorhmit_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::srv::IfAlgorhmit_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tutorial_interfaces::srv::IfAlgorhmit>()
{
  return "tutorial_interfaces::srv::IfAlgorhmit";
}

template<>
inline const char * name<tutorial_interfaces::srv::IfAlgorhmit>()
{
  return "tutorial_interfaces/srv/IfAlgorhmit";
}

template<>
struct has_fixed_size<tutorial_interfaces::srv::IfAlgorhmit>
  : std::integral_constant<
    bool,
    has_fixed_size<tutorial_interfaces::srv::IfAlgorhmit_Request>::value &&
    has_fixed_size<tutorial_interfaces::srv::IfAlgorhmit_Response>::value
  >
{
};

template<>
struct has_bounded_size<tutorial_interfaces::srv::IfAlgorhmit>
  : std::integral_constant<
    bool,
    has_bounded_size<tutorial_interfaces::srv::IfAlgorhmit_Request>::value &&
    has_bounded_size<tutorial_interfaces::srv::IfAlgorhmit_Response>::value
  >
{
};

template<>
struct is_service<tutorial_interfaces::srv::IfAlgorhmit>
  : std::true_type
{
};

template<>
struct is_service_request<tutorial_interfaces::srv::IfAlgorhmit_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tutorial_interfaces::srv::IfAlgorhmit_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__TRAITS_HPP_
