// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitmsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'imageout'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'targetpointout'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__struct.hpp"
// Member 'lasertrackout'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitmsg __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitmsg __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitmsg_
{
  using Type = IfAlgorhmitmsg_<ContainerAllocator>;

  explicit IfAlgorhmitmsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imageout(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->solderjoints = false;
    }
  }

  explicit IfAlgorhmitmsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imageout(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->solderjoints = false;
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
  using _solderjoints_type =
    bool;
  _solderjoints_type solderjoints;

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
  Type & set__solderjoints(
    const bool & _arg)
  {
    this->solderjoints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitmsg
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitmsg
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitmsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitmsg_ & other) const
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
    if (this->solderjoints != other.solderjoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitmsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitmsg_

// alias to use template instance with default allocator
using IfAlgorhmitmsg =
  tutorial_interfaces::msg::IfAlgorhmitmsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITMSG__STRUCT_HPP_
