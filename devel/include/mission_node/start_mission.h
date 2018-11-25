// Generated by gencpp from file mission_node/start_mission.msg
// DO NOT EDIT!


#ifndef MISSION_NODE_MESSAGE_START_MISSION_H
#define MISSION_NODE_MESSAGE_START_MISSION_H

#include <ros/service_traits.h>


#include <mission_node/start_missionRequest.h>
#include <mission_node/start_missionResponse.h>


namespace mission_node
{

struct start_mission
{

typedef start_missionRequest Request;
typedef start_missionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct start_mission
} // namespace mission_node


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mission_node::start_mission > {
  static const char* value()
  {
    return "fe261445a9489aed43e3808ba8261eed";
  }

  static const char* value(const ::mission_node::start_mission&) { return value(); }
};

template<>
struct DataType< ::mission_node::start_mission > {
  static const char* value()
  {
    return "mission_node/start_mission";
  }

  static const char* value(const ::mission_node::start_mission&) { return value(); }
};


// service_traits::MD5Sum< ::mission_node::start_missionRequest> should match 
// service_traits::MD5Sum< ::mission_node::start_mission > 
template<>
struct MD5Sum< ::mission_node::start_missionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mission_node::start_mission >::value();
  }
  static const char* value(const ::mission_node::start_missionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mission_node::start_missionRequest> should match 
// service_traits::DataType< ::mission_node::start_mission > 
template<>
struct DataType< ::mission_node::start_missionRequest>
{
  static const char* value()
  {
    return DataType< ::mission_node::start_mission >::value();
  }
  static const char* value(const ::mission_node::start_missionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mission_node::start_missionResponse> should match 
// service_traits::MD5Sum< ::mission_node::start_mission > 
template<>
struct MD5Sum< ::mission_node::start_missionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mission_node::start_mission >::value();
  }
  static const char* value(const ::mission_node::start_missionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mission_node::start_missionResponse> should match 
// service_traits::DataType< ::mission_node::start_mission > 
template<>
struct DataType< ::mission_node::start_missionResponse>
{
  static const char* value()
  {
    return DataType< ::mission_node::start_mission >::value();
  }
  static const char* value(const ::mission_node::start_missionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MISSION_NODE_MESSAGE_START_MISSION_H
