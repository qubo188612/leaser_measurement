// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/IfAlgorhmitcloud.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'lasertrackoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint4f__struct.hpp"
// Member 'targetpointoutcloud'
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint4f__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitcloud __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitcloud __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IfAlgorhmitcloud_
{
  using Type = IfAlgorhmitcloud_<ContainerAllocator>;

  explicit IfAlgorhmitcloud_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->solderjoints = false;
    }
  }

  explicit IfAlgorhmitcloud_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->solderjoints = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _lasertrackoutcloud_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint4f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitpoint4f_<ContainerAllocator>>>;
  _lasertrackoutcloud_type lasertrackoutcloud;
  using _targetpointoutcloud_type =
    std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint4f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetpoint4f_<ContainerAllocator>>>;
  _targetpointoutcloud_type targetpointoutcloud;
  using _solderjoints_type =
    bool;
  _solderjoints_type solderjoints;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__lasertrackoutcloud(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint4f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmitpoint4f_<ContainerAllocator>>> & _arg)
  {
    this->lasertrackoutcloud = _arg;
    return *this;
  }
  Type & set__targetpointoutcloud(
    const std::vector<tutorial_interfaces::msg::IfAlgorhmittargetpoint4f_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tutorial_interfaces::msg::IfAlgorhmittargetpoint4f_<ContainerAllocator>>> & _arg)
  {
    this->targetpointoutcloud = _arg;
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
    tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitcloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__IfAlgorhmitcloud
    std::shared_ptr<tutorial_interfaces::msg::IfAlgorhmitcloud_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IfAlgorhmitcloud_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->lasertrackoutcloud != other.lasertrackoutcloud) {
      return false;
    }
    if (this->targetpointoutcloud != other.targetpointoutcloud) {
      return false;
    }
    if (this->solderjoints != other.solderjoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const IfAlgorhmitcloud_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IfAlgorhmitcloud_

// alias to use template instance with default allocator
using IfAlgorhmitcloud =
  tutorial_interfaces::msg::IfAlgorhmitcloud_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__IF_ALGORHMITCLOUD__STRUCT_HPP_
