// Generated by gencpp from file cc_node/get_set_take_off_posRequest.msg
// DO NOT EDIT!


#ifndef CC_NODE_MESSAGE_GET_SET_TAKE_OFF_POSREQUEST_H
#define CC_NODE_MESSAGE_GET_SET_TAKE_OFF_POSREQUEST_H


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
struct get_set_take_off_posRequest_
{
  typedef get_set_take_off_posRequest_<ContainerAllocator> Type;

  get_set_take_off_posRequest_()
    : get_set()  {
    }
  get_set_take_off_posRequest_(const ContainerAllocator& _alloc)
    : get_set(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _get_set_type;
  _get_set_type get_set;





  typedef boost::shared_ptr< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> const> ConstPtr;

}; // struct get_set_take_off_posRequest_

typedef ::cc_node::get_set_take_off_posRequest_<std::allocator<void> > get_set_take_off_posRequest;

typedef boost::shared_ptr< ::cc_node::get_set_take_off_posRequest > get_set_take_off_posRequestPtr;
typedef boost::shared_ptr< ::cc_node::get_set_take_off_posRequest const> get_set_take_off_posRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cc_node

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'cc_node': ['/home/pi/airdrop_ros/src/cc_node/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2cef4ab6248f728f13eff83f95609803";
  }

  static const char* value(const ::cc_node::get_set_take_off_posRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2cef4ab6248f728fULL;
  static const uint64_t static_value2 = 0x13eff83f95609803ULL;
};

template<class ContainerAllocator>
struct DataType< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cc_node/get_set_take_off_posRequest";
  }

  static const char* value(const ::cc_node::get_set_take_off_posRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string get_set\n\
";
  }

  static const char* value(const ::cc_node::get_set_take_off_posRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.get_set);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct get_set_take_off_posRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cc_node::get_set_take_off_posRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cc_node::get_set_take_off_posRequest_<ContainerAllocator>& v)
  {
    s << indent << "get_set: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.get_set);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CC_NODE_MESSAGE_GET_SET_TAKE_OFF_POSREQUEST_H
