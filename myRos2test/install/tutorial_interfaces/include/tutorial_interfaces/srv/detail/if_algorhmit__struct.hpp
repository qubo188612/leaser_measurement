// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Request __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Request __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmit_Request_
{
  using Type = IfAlgorhmit_Request_<ContainerAllocator>;

  explicit IfAlgorhmit_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagein(_init)
  {
    (void)_init;
  }

  explicit IfAlgorhmit_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagein(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _imagein_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _imagein_type imagein;

  // setters for named parameter idiom
  Type & set__imagein(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->imagein = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Request
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Request
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmit_Request_ & other) const
  {
    if (this->imagein != other.imagein) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmit_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmit_Request_

// alias to use template instance with default allocator
using IfAlgorhmit_Request =
  tutorial_interfaces::srv::IfAlgorhmit_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tutorial_interfaces


// Include directives for member types
// Member 'imageout'
// already included above
// #include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'targetpointout'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.hpp"
// Member 'lasertrackout'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Response __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Response __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmit_Response_
{
  using Type = IfAlgorhmit_Response_<ContainerAllocator>;

  explicit IfAlgorhmit_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imageout(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit IfAlgorhmit_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imageout(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;
  using _imageout_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _imageout_type imageout;
  using _targetpointout_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f_<ContainerAllocator>>>;
  _targetpointout_type targetpointout;
  using _lasertrackout_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitpoint2f_<ContainerAllocator>>>;
  _lasertrackout_type lasertrackout;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__imageout(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->imageout = _arg;
    return *this;
  }
  Type & set__targetpointout(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetpoint2f_<ContainerAllocator>>> & _arg)
  {
    this->targetpointout = _arg;
    return *this;
  }
  Type & set__lasertrackout(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint2f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitpoint2f_<ContainerAllocator>>> & _arg)
  {
    this->lasertrackout = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Response
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__srv__IfAlgorhmit_Response
    std::shared_ptr<tutorial_interfaces::srv::IfAlgorhmit_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmit_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->imageout != other.imageout) {
      return false;
    }
    if (this->targetpointout != other.targetpointout) {
      return false;
    }
    if (this->lasertrackout != other.lasertrackout) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmit_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmit_Response_

// alias to use template instance with default allocator
using IfAlgorhmit_Response =
  tutorial_interfaces::srv::IfAlgorhmit_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tutorial_interfaces

namespace tutorial_interfaces
{

namespace srv
{

struct IfAlgorhmit
{
  using Request = tutorial_interfaces::srv::IfAlgorhmit_Request;
  using Response = tutorial_interfaces::srv::IfAlgorhmit_Response;
};

}  // namespace srv

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__IF_ALGORHMIT__STRUCT_HPP_
