#include <sstream>
#include <iostream>
#include <vector>
#include <dirent.h>
#include <sys/types.h>
#include <algorithm>
#include <boost/asio.hpp>
#include <fstream>
#include <boost/filesystem.hpp>

#include "ros/ros.h"
#include "std_msgs/String.h"

#include "mission_node/list_missions.h"
#include "mission_node/start_mission.h"

#include "cc_node/a_operation_fly_to_pos.h"
#include "cc_node/a_operation_landing.h"
#include "cc_node/a_operation_liftoff.h"
#include "cc_node/a_operation_stop_action_and_hover.h"
#include "cc_node/a_operation_turn_to_direction.h"
#include "cc_node/manual_action.h"
#include "cc_node/conf_states.h"
#include "cc_node/drone_states.h"

using namespace std;

vector<string> split(string str, char delimiter)
{
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter))
  {
    internal.push_back(tok);
  }

  return internal;
}

bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(),
        s.end(), [](char c) { return !isdigit(c); }) == s.end();
}
bool is_float(string myString) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool fexists(string filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}

/*
  mission loader
  mission path: /etc/airdrop/missions
*/
bool start_mission(mission_node::start_mission::Request  &req,
                  mission_node::start_mission::Response &res)
{
  if(req.mission_name  !="")
  {
    const char *path = "/etc/airdrop/missions";
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
      ROS_INFO("Mission dir not found");
      res.mission_status = 14;
    }
    string file_line = "";
    ifstream file_open;

    ros::NodeHandle n;

    ros::ServiceClient cl_manual_action = n.serviceClient<cc_node::manual_action>("manual_action");
    ros::ServiceClient cl_a_operation_landing = n.serviceClient<cc_node::a_operation_landing>("a_operation_landing");
    ros::ServiceClient cl_a_operation_liftoff = n.serviceClient<cc_node::a_operation_liftoff>("a_operation_liftoff");
    ros::ServiceClient cl_a_operation_fly_to_pos = n.serviceClient<cc_node::a_operation_fly_to_pos>("a_operation_fly_to_pos");
    ros::ServiceClient cl_a_operation_stop_action_and_hover = n.serviceClient<cc_node::a_operation_stop_action_and_hover>("a_operation_stop_action_and_hover");
    ros::ServiceClient cl_a_operation_turn_to_direction = n.serviceClient<cc_node::a_operation_turn_to_direction>("a_operation_turn_to_direction");
    ros::ServiceClient conf_states = n.serviceClient<cc_node::conf_states>("conf_states");

    cc_node::manual_action manual_action;
    cc_node::a_operation_landing a_operation_landing;
    cc_node::a_operation_liftoff a_operation_liftoff;
    cc_node::a_operation_fly_to_pos a_operation_fly_to_pos;
    cc_node::a_operation_stop_action_and_hover a_operation_stop_action_and_hover;
    cc_node::a_operation_turn_to_direction a_operation_turn_to_direction;
    cc_node::conf_states c_conf_states;

    if(fexists(string (path) + "/" + req.mission_name))
    {
    try {
      file_open.open (string (path) + "/" + string(req.mission_name));
      file_line = "";
      cc_node::drone_states latest_states = *ros::topic::waitForMessage<cc_node::drone_states>("/drone_state", ros::Duration(10));
      if(!latest_states.in_mission){
          ROS_INFO("Starting Mission %s",string(req.mission_name).c_str());
          c_conf_states.request.airborne = latest_states.airborne;
          c_conf_states.request.in_mission = true;
          c_conf_states.request.landing_phase = latest_states.landing_phase;
          conf_states.call(c_conf_states);
          while(getline(file_open, file_line))
          {
            vector<string> split_by_space = split(file_line, ' ');
            if(split_by_space[0] == "wait")
            {
              if(split_by_space.size() == 2 && is_number(split_by_space[1]))
              {
                int time = atoi(split_by_space[1].c_str());
                ROS_INFO("Waiting: %d",time);
                sleep(time);
              } else {
                res.mission_status = 19;
                break;
              }
            } else if(split_by_space[0] == "hover"){
              if(split_by_space.size() == 1)
              {
                a_operation_stop_action_and_hover.request.a_operation_pausing_reason="unknown";
                if (cl_a_operation_stop_action_and_hover.call(a_operation_stop_action_and_hover))
                {}
              } else {
                res.mission_status = 19;
                break;
              }
            } else if(split_by_space[0] == "takeoff")
            {
              if(split_by_space.size() == 2 && is_number(split_by_space[1]))
              {
                a_operation_liftoff.request.a_operation_takeoff_height = atoi(split_by_space[1].c_str());
                if (cl_a_operation_liftoff.call(a_operation_liftoff))
                {
                  res.mission_status = 17;
                  res.operation_status = a_operation_liftoff.response.a_operation_status;
                  if (!a_operation_liftoff.response.a_operation_status == 7)
                  {
                    res.mission_status = 16;
                    break;
                  }
                } else {
                  res.mission_status = 20;
                  break;
                }
              } else {
                res.mission_status = 19;
                break;
              }
            } else if(split_by_space[0] == "land"){
              if(split_by_space.size() == 1)
              {
                if (cl_a_operation_landing.call(a_operation_landing))
                {
                  res.mission_status = 17;
                  res.operation_status = a_operation_landing.response.a_operation_status;
                  if (!a_operation_landing.response.a_operation_status == 7)
                  {
                    res.mission_status = 16;
                    break;
                  }
                } else {
                  res.mission_status = 20;
                  break;
                }
              } else {
                res.mission_status = 19;
                break;
              }
            } else if(split_by_space[0] == "flyto"){
              float lat, lon;
              int alt;
              if(split_by_space.size() == 3 && is_float(split_by_space[1]) && is_float(split_by_space[2]) && is_number(split_by_space[3]))
              {
                lat= atof(split_by_space[1].c_str());
                lon= atof(split_by_space[2].c_str());
                alt= atoi(split_by_space[3].c_str());
                a_operation_fly_to_pos.request.pos_lat = lat;
                a_operation_fly_to_pos.request.pos_lon = lon;
                a_operation_fly_to_pos.request.pos_alt = alt;
                if (cl_a_operation_fly_to_pos.call(a_operation_fly_to_pos))
                {
                  res.mission_status = 17;
                  res.operation_status = a_operation_fly_to_pos.response.a_operation_status;
                  if (!a_operation_fly_to_pos.response.a_operation_status == 7)
                  {
                    res.mission_status = 16;
                    break;
                  }
                } else {
                  res.mission_status = 20;
                  break;
                }
              } else {
                res.  = 19;
                break;
              }
            } else if(split_by_space[0] == "turnto"){
              if(split_by_space.size() == 2 && is_number(split_by_space[1]))
              {
                res.mission_status = 17;
                a_operation_turn_to_direction.request.a_operation_dir_in_deg = atoi(split_by_space[1].c_str());
                if (cl_a_operation_turn_to_direction.call(a_operation_turn_to_direction))
                {
                  res.mission_status = 17;
                  res.operation_status = a_operation_turn_to_direction.response.a_operation_status;
                  if (!a_operation_turn_to_direction.response.a_operation_status == 7)
                  {
                    res.mission_status = 16;
                    break;
                  }
                } else {
                  res.mission_status = 20;
                  break;
                }
              } else {
                res.mission_status = 19;
                break;
              }
            } else if(split_by_space[0] == "hover"){
              if(split_by_space.size() == 2 && is_number(split_by_space[1]))
              {
                if (cl_a_operation_stop_action_and_hover.call(a_operation_stop_action_and_hover))
                {
                  res.mission_status = 17;
                  res.operation_status = a_operation_stop_action_and_hover.response.a_operation_status;
                  if (!a_operation_stop_action_and_hover.response.a_operation_status == 7)
                  {
                    res.mission_status = 16;
                    break;
                  }
                } else {
                  res.mission_status = 20;
                  break;
                }
              } else {
                res.mission_status = 19;
                break;
              }
            } else {
              res.mission_status = 19;
              break;
            }

          }
          cc_node::drone_states latest_states = *ros::topic::waitForMessage<cc_node::drone_states>("/drone_state", ros::Duration(10));
          c_conf_states.request.airborne = latest_states.airborne;
          c_conf_states.request.in_mission = false;
          c_conf_states.request.landing_phase = latest_states.landing_phase;
          conf_states.call(c_conf_states);
          ROS_INFO("Ending Mission %s", string(req.mission_name).c_str());
        } else {
          ROS_INFO("Ignoring mission request, already in mission!");
        }
      } catch (const ifstream::failure& e) {
        res.mission_status = 13;
      }
    } else {
      res.mission_status = 13;
    }
  }
  if(res.mission_status == 17) {
    res.mission_status = 18;
  }
  return true;
}


/*
  mission list
  mission path: /etc/airdrop/missions
*/
bool list_missions(mission_node::list_missions::Request  &req,
                  mission_node::list_missions::Response &res)
{
  const char *path = "/etc/airdrop/missions";
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir ("/etc/airdrop/missions")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      //printf ("%s\n", ent->d_name);
      if (ent->d_name != "." || ent->d_name != ".." ){
        res.mission_list.push_back(ent->d_name);
      }
    }
    closedir (dir);
  } else {
    return EXIT_FAILURE;
  }
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Mission engine node");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("start_mission", start_mission);

  ros::ServiceServer service1 = n.advertiseService("list_missions", list_missions);

  ROS_INFO("RC Node Up and Ready all Services are go!");
  ros::spin();

  return 0;
}
