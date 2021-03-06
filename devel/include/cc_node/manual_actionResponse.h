// Generated by gencpp from file cc_node/manual_actionResponse.msg
// DO NOT EDIT!


#ifndef CC_NODE_MESSAGE_MANUAL_ACTIONRESPONSE_H
#define CC_NODE_MESSAGE_MANUAL_ACTIONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cc_node
{
template <class ContainerAllocator>
struct manual_actionResponse_
{
  typedef manual_actionResponse_<ContainerAllocator> Type;

  manual_actionResponse_()
    : m_action_status(0)  {
    }
  manual_actionResponse_(const ContainerAllocator& _alloc)
    : m_action_status(0)  {
  (void)_alloc;
    }



   typedef int64_t _m_action_status_type;
  _m_action_status_type m_action_status;





  typedef boost::shared_ptr< ::cc_node::manual_actionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cc_node::manual_actionResponse_<ContainerAllocator> const> ConstPtr;

}; // struct manual_actionResponse_

typedef ::cc_node::manual_actionResponse_<std::allocator<void> > manual_actionResponse;

typedef boost::shared_ptr< ::cc_node::manual_actionResponse > manual_actionResponsePtr;
typedef boost::shared_ptr< ::cc_node::manual_actionResponse const> manual_actionResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cc_node::manual_actionResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cc_node::manual_actionResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cc_node

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'cc_node': ['/home/pi/airdrop_ros/src/cc_node/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cc_node::manual_actionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cc_node::manual_actionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cc_node::manual_actionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cc_node::manual_actionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cc_node::manual_actionResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cc_node::manual_actionResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cc_node::manual_actionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "39c2bad13e87126a7320b7f46f4184eb";
  }

  static const char* value(const ::cc_node::manual_actionResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x39c2bad13e87126aULL;
  static const uint64_t static_value2 = 0x7320b7f46f4184ebULL;
};

template<class ContainerAllocator>
struct DataType< ::cc_node::manual_actionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cc_node/manual_actionResponse";
  }

  static const char* value(const ::cc_node::manual_actionResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cc_node::manual_actionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 m_action_status\n\
\n\
";
  }

  static const char* value(const ::cc_node::manual_actionResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cc_node::manual_actionResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.m_action_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct manual_actionResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cc_node::manual_actionResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cc_node::manual_actionResponse_<ContainerAllocator>& v)
  {
    s << indent << "m_action_status: ";
    Printer<int64_t>::stream(s, indent + "  ", v.m_action_status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CC_NODE_MESSAGE_MANUAL_ACTIONRESPONSE_H
