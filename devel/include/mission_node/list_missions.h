// Generated by gencpp from file mission_node/list_missions.msg
// DO NOT EDIT!


#ifndef MISSION_NODE_MESSAGE_LIST_MISSIONS_H
#define MISSION_NODE_MESSAGE_LIST_MISSIONS_H

#include <ros/service_traits.h>


#include <mission_node/list_missionsRequest.h>
#include <mission_node/list_missionsResponse.h>


namespace mission_node
{

struct list_missions
{

typedef list_missionsRequest Request;
typedef list_missionsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct list_missions
} // namespace mission_node


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mission_node::list_missions > {
  static const char* value()
  {
    return "3d952d9b438834ab872583b9374911ec";
  }

  static const char* value(const ::mission_node::list_missions&) { return value(); }
};

template<>
struct DataType< ::mission_node::list_missions > {
  static const char* value()
  {
    return "mission_node/list_missions";
  }

  static const char* value(const ::mission_node::list_missions&) { return value(); }
};


// service_traits::MD5Sum< ::mission_node::list_missionsRequest> should match 
// service_traits::MD5Sum< ::mission_node::list_missions > 
template<>
struct MD5Sum< ::mission_node::list_missionsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mission_node::list_missions >::value();
  }
  static const char* value(const ::mission_node::list_missionsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mission_node::list_missionsRequest> should match 
// service_traits::DataType< ::mission_node::list_missions > 
template<>
struct DataType< ::mission_node::list_missionsRequest>
{
  static const char* value()
  {
    return DataType< ::mission_node::list_missions >::value();
  }
  static const char* value(const ::mission_node::list_missionsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mission_node::list_missionsResponse> should match 
// service_traits::MD5Sum< ::mission_node::list_missions > 
template<>
struct MD5Sum< ::mission_node::list_missionsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mission_node::list_missions >::value();
  }
  static const char* value(const ::mission_node::list_missionsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mission_node::list_missionsResponse> should match 
// service_traits::DataType< ::mission_node::list_missions > 
template<>
struct DataType< ::mission_node::list_missionsResponse>
{
  static const char* value()
  {
    return DataType< ::mission_node::list_missions >::value();
  }
  static const char* value(const ::mission_node::list_missionsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MISSION_NODE_MESSAGE_LIST_MISSIONS_H
