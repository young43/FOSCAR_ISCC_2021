#include <vector>
#include <pure_pursuit_core.h>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <chrono>
#include <algorithm>

#include <tf/transform_broadcaster.h>

namespace waypoint_follower
{
// Constructor
PurePursuitNode::PurePursuitNode()
  : private_nh_("~")
  , pp_()
  , LOOP_RATE_(30)
  , is_waypoint_set_(false)
  , is_pose_set_(false)
  , const_lookahead_distance_(4.0)
  , const_velocity_(3.0)
  , final_constant(1.5)
{
  initForROS();
}

// Destructor
PurePursuitNode::~PurePursuitNode() {}

// obstacle global variable
float tmp_yaw_rate = 0.0;

bool left_detected = false;
bool left_avoid = false;
bool right_detected = false;
bool right_avoid = false;

float target_dist = 3.0;
float min_dist = 1.0;

int obs_cnt = 0;
std::chrono::system_clock::time_point obs_start;

/* traffic Index manager */
// 1,2,3,4,7 직진
// 5(비보호 좌회전), 6(좌회전)
const int tf_idx_1 = 1177; // 1180
const int tf_idx_2 = 1452; // 1455
const int tf_idx_3 = 2497; // 2500
const int tf_idx_4 = 2987; // 2990
const int tf_idx_5 = 3403; // 3406
const int tf_idx_6 = 5052; // 5055
const int tf_idx_7 = 5285; // 5285

bool tf_flag = false;
const float tf_coord1[2] = {935575.213544702, 1915926.09913091};
const float tf_coord2[2] = {935601.125, 1915974.5};
const float tf_coord3[2] = {935650.3125, 1916100.5};
const float tf_coord4[2] = {935655.875, 1916205.75};
const float tf_coord5[2] = {935648.625, 1916343.25};
const float tf_coord6[2] = {935581.6875, 1916251.625};
const float tf_coord7[2] = {935642.9375, 1916131.125};
/*************************/


/* delivery Index manager */
const int dv_a_idx_1 = 1000;
const int dv_b_idx_1 = 1000;
const int dv_b_idx_2 = 1000;
const int dv_b_idx_3 = 1000;
/*************************/

/* Parking manager */
const float pk_coord1[2] = {935534.247324, 1915849.29071};
const float pk_coord2[2] = {935536.127777, 1915852.74891};
const float pk_coord3[2] = {935537.027791, 1915854.43949};
const float pk_coord4[2] = {935539.530479, 1915859.22427};
const float pk_coord5[2] = {935540.465801, 1915860.89238};
const float pk_coord6[2] = {935541.86021, 1915863.43345};
/*************************/



// float tmp_distance = 100.0;
///////////////////////////////

void PurePursuitNode::initForROS()
{
  // ros parameter settings
  private_nh_.param("const_lookahead_distance", const_lookahead_distance_, 4.0);
  private_nh_.param("const_velocity", const_velocity_, 3.0);
  private_nh_.param("final_constant", final_constant, 1.0);

  nh_.param("vehicle_info/wheel_base", wheel_base_, 1.04);

  ROS_HOME = ros::package::getPath("pure_pursuit");

  // setup subscriber
  pose_sub = nh_.subscribe("current_pose", 1,
    &PurePursuitNode::callbackFromCurrentPose, this);

  // for main control
  obstacle_sub = nh_.subscribe("true_obs", 1,
    &PurePursuitNode::callbackFromObstacle, this);
  obstacle_sub2 = nh_.subscribe("detected_obs", 1,
    &PurePursuitNode::callbackFromObstacle2, this);
  traffic_light_sub = nh_.subscribe("darknet_ros/bounding_boxes",1,
    &PurePursuitNode::callbackFromTrafficLight, this);
  // obstacle_sub = nh_.subscribe("{lane_topic_name}", 1,
  //   &PurePursuitNode::callbackFromLane, this);


  // setup publisher
  drive_msg_pub = nh_.advertise<race::drive_values>("control_value", 1);
  steering_vis_pub = nh_.advertise<geometry_msgs::PoseStamped>("steering_vis", 1);

  // for visualization
  target_point_pub = nh_.advertise<geometry_msgs::PointStamped>("target_point", 1);
  current_point_pub = nh_.advertise<geometry_msgs::PointStamped>("current_point", 1);
}

void PurePursuitNode::run(char** argv) {
  ROS_INFO_STREAM("pure pursuit2 start");

  // temp
  const_lookahead_distance_ = atof(argv[2]);
  const_velocity_ = atof(argv[3]);
  final_constant = atof(argv[4]);
  //////////////////////////

  ros::Rate loop_rate(LOOP_RATE_);
  while (ros::ok()) {
    ros::spinOnce();

    if (!is_waypoint_set_) {
      setPath(argv);
      pp_.setWaypoints(global_path);
    }

    if (!is_pose_set_) {
      loop_rate.sleep();
      continue;
    }

    pp_.setLookaheadDistance(computeLookaheadDistance());

    double kappa = 0;
    bool can_get_curvature = pp_.canGetCurvature(&kappa);

    // target point visualization
    publishTargetPointVisualizationMsg();
    publishCurrentPointVisualizationMsg();


    // geometry_msgs::Point green_point = pp_.waypoints.at(pp_.current_idx).first;
    // geometry_msgs::Point pink_point = pp_.waypoints.at(pp_.next_waypoint_number_).first;
    // double yaw = atan2(2.0 * (pp_.current_pose_.orientation.w * pp_.current_pose_.orientation.z + pp_.current_pose_.orientation.x * pp_.current_pose_.orientation.y), 1.0 - 2.0 * (pp_.current_pose_.orientation.y * pp_.current_pose_.orientation.y + pp_.current_pose_.orientation.z * pp_.current_pose_.orientation.z));
    // double map_yaw = atan2(pink_point.y - green_point.y, pink_point.x - green_point.x);
    // double diff_yaw = fabs(yaw - map_yaw);

    // double map_car_yaw =atan2(pink_point.y - pp_.current_pose_.position.y, pink_point.x - pp_.current_pose_.position.x);
    // double sinTheta =sin(fabs(map_yaw-map_car_yaw));
    // double temp_distance = sqrt(pow(green_point.x - pp_.current_pose_.position.x, 2) + pow(green_point.y - pp_.current_pose_.position.y, 2));
    // double distance_from_car = fabs(sinTheta*temp_distance);


    // 마지막 waypoint 에 다다랐으면 멈추기
    if(pp_.is_finish && pp_.mode == 8){
      pulishControlMsg(0,0);
      ROS_INFO_STREAM("Finish Pure Pursuit");
      continue;
    }


    // ROS_INFO("MODE: %d, MISSION: %d", pp_.mode, pp_.mission_flag);
    // int temp_idx = pp_.getPosIndex(935658.25, 1916136.625);
    // int temp_idx = pp_.getPosIndex(tf_coord1[0], tf_coord1[1]);

    // Traffic Light Index 한번만 초기화
    if(!tf_flag){
      tf_flag = true;
      tf_idx_1 = pp_.getPosIndex(tf_coord1[0], tf_coord1[1]);
      tf_idx_2 = pp_.getPosIndex(tf_coord2[0], tf_coord2[1]);
      tf_idx_3 = pp_.getPosIndex(tf_coord3[0], tf_coord3[1]);
      tf_idx_4 = pp_.getPosIndex(tf_coord4[0], tf_coord4[1], 1); // 혹시나 배달구간 겹칠 수 있기때문에..
      tf_idx_5 = pp_.getPosIndex(tf_coord5[0], tf_coord5[1]);
      tf_idx_6 = pp_.getPosIndex(tf_coord6[0], tf_coord6[1]);
      tf_idx_7 = pp_.getPosIndex(tf_coord7[0], tf_coord7[1]);
    }
    

    // MODE 0 - Normal 직진구간
    if(pp_.mode == 0){
      pp_.mission_flag = 0;
      const_lookahead_distance_ = 6;
      const_velocity_ = 10;
      final_constant = 1.2;
    }

    // MODE 1 - Normal 커브구간
    if (pp_.mode == 1) {
      pp_.mission_flag = 0;
      const_lookahead_distance_ = 4;
      const_velocity_ = 8;
      final_constant = 1.5;
    }


    // MODE 2 - 주차
    // 주차 구간
    if (pp_.mode == 2) {
      pp_.is_finish = false;

      if (pp_.mission_flag == 3 || pp_.mission_flag == 0) {
        const_lookahead_distance_ = 6;
        const_velocity_ = 6;
      }

      // first
      // int start_parking_idx = 260
      // int start_parking_idx = pp_.getPosIndex(pk_coord1[0], pk_coord1[1]);
      // int end_parking_idx = 120;
      // int end_parking_backward_idx = 100;
      // int end_parking_full_steer_backward_idx = 75;

       // second
       // int start_parking_idx = 280;
       int start_parking_idx = pp_.getPosIndex(pk_coord2[0], pk_coord2[1]);
       int end_parking_idx = 87;
       int end_parking_backward_idx = 55;
       int end_parking_full_steer_backward_idx = 25;


       // third
       // int start_parking_idx = 290;
       // int start_parking_idx = pp_.getPosIndex(pk_coord3[0], pk_coord3[1]);
       // int end_parking_idx = 145;
       // int end_parking_backward_idx = 117; // 120
       // int end_parking_full_steer_backward_idx = 90;

      // forth
      // int start_parking_idx = 320;
      // int start_parking_idx = pp_.getPosIndex(pk_coord4[0], pk_coord4[1]);
      // int end_parking_idx = 88;
      // int end_parking_backward_idx = 55;
      // int end_parking_full_steer_backward_idx = 23;

      // fifth
      // int start_parking_idx = 330;
      // int start_parking_idx = pp_.getPosIndex(pk_coord5[0], pk_coord5[1]);
      // int end_parking_idx = 80;
      // int end_parking_backward_idx = 50;
      // int end_parking_full_steer_backward_idx = 23;

      //sixth
      // int start_parking_idx = 345;
      // int start_parking_idx = pp_.getPosIndex(pk_coord6[0], pk_coord6[1]);
      // int end_parking_idx = 75;
      // int end_parking_backward_idx = 55;
      // int end_parking_full_steer_backward_idx = 25;


      // backward_speed : -7
      int backward_speed = -7;

      // //x < start_parking_idx < y
      if (pp_.mission_flag == 0 && pp_.next_waypoint_number_ >= start_parking_idx){
        pp_.setWaypoints(parking_path);
        const_lookahead_distance_ = 3;
        const_velocity_ = 3;  // 3
        pp_.mission_flag = 1;
      }

      // 주차 끝
      if(pp_.mission_flag == 1 && pp_.reachMissionIdx(end_parking_idx)){
        /////////////////////////////////////////////////////////////////////////////////
        // 3초 멈춤
        for (int i = 0; i < 50; i++)
        {
          pulishControlMsg(0, 0);
          // 0.1초
          usleep(100000);
        }

        /////////////////////////////////////////////////////////////////////////////////
        // 특정 지점까지는 그냥 후진
        while (!pp_.reachMissionIdx(end_parking_backward_idx)) {
          pulishControlMsg(backward_speed, 0);
          ros::spinOnce();
        }
        // 그 다음 지점까지는 풀조향 후진
        while (!pp_.reachMissionIdx(end_parking_full_steer_backward_idx)) {
          pulishControlMsg(backward_speed, 30);
          ros::spinOnce();
        }
        pp_.mission_flag = 2;
      }
      // 주차 빠져나오고 다시 global path로
      if (pp_.mission_flag == 2) {
        for (int i = 0; i < 30; i++) {
          pulishControlMsg(0, 0);
          // 0.1초
          usleep(100000);
        }
        ROS_INFO("PATH SWITCHING");
        pp_.setWaypoints(global_path);
        pp_.mission_flag = 3;
      }

      if (pp_.mission_flag == 3)
      {
        const_lookahead_distance_ = 6;
        const_velocity_ = 10;
        final_constant = 1.2;

      }
    }


    // MODE 3 : 신호등 (직진구간)
    if (pp_.mode == 3) {
      pp_.mission_flag = 0; 
      const_lookahead_distance_ = 5;
      const_velocity_ = 8;
      final_constant = 1.2;
     

      // 1,2,3,4,7번 직진신호등 멈춤
      if((pp_.reachMissionIdx(tf_idx_1) || pp_.reachMissionIdx(tf_idx_2) || pp_.reachMissionIdx(tf_idx_3)
          || pp_.reachMissionIdx(tf_idx_4) || pp_.reachMissionIdx(tf_idx_7)) && !pp_.straight_go_flag) {
        pulishControlMsg(0,0);
        continue;
      }



    }

    // MODE 9 : 신호등 (좌회전)
    if (pp_.mode == 9) {
      pp_.mission_flag = 0; 
      const_lookahead_distance_ = 5;
      const_velocity_ = 8;
      final_constant = 1.5;
     

      // 5,6번 좌회전 신호등 멈춤
      if((pp_.reachMissionIdx(tf_idx_5) || pp_.reachMissionIdx(tf_idx_6)) && !pp_.left_go_flag) {
        pulishControlMsg(0,0);
        continue;
      }
    }

    // MODE 4 : 정적 장애물 2 , Path switching  -- version 1
    if (pp_.mode == 4) {
      if (pp_.mission_flag == 0) {
        const_lookahead_distance_ = 6;
        const_velocity_ = 8;
      }
      if (pp_.mission_flag >= 1) {
        std::cout << "************************" << std::endl;
        std::cout << "TIME : " << (std::chrono::duration<double>(std::chrono::system_clock::now() - obs_start)).count() << std::endl;
        std::cout << "mission flag :" << pp_.mission_flag << std::endl;
        std::cout << "obstacles_detected : " << pp_.is_obstacle_detected << std::endl;
      }
      if (pp_.mission_flag == 0 && pp_.is_obstacle_detected) {
        const_lookahead_distance_ = 4;
        const_velocity_ = 3;
        pp_.mission_flag = 1;
        obs_start = std::chrono::system_clock::now();
        pulishControlMsg(3, 24);
        continue;
      }
      else if (pp_.mission_flag == 1 && pp_.is_obstacle_detected) {
        //pp_.mission_flag = 2;
        pulishControlMsg(3, 24);
        continue;
      }
      else if (pp_.mission_flag == 1 && !pp_.is_obstacle_detected) {
        pp_.setWaypoints(avoidance_path);
        pp_.mission_flag = 2;
        //pulishControlMsg(0, 0);
      
        // for test
        // const_lookahead_distance_ = 4;
        // const_velocity_ = 6;
        // final_constant = 2.0;
      
        continue;
      }
      // avoid path original time 4.0
      else if (pp_.mission_flag == 2 && pp_.is_obstacle_detected && (std::chrono::duration<double>(std::chrono::system_clock::now() - obs_start)).count() > 4.0) {
        pp_.mission_flag = 3;
        pulishControlMsg(3, -28);
        continue;
      }
      else if(pp_.mission_flag == 3 && pp_.is_obstacle_detected)
      {
        pulishControlMsg(3, -28);
        continue;
      }
      //  && (std::chrono::duration<double>(std::chrono::system_clock::now() - obs_start)).count() > 10.0
      else if (pp_.mission_flag == 3 && !pp_.is_obstacle_detected) {
        // if (double((clock() - obs_time) /CLOCKS_PER_SEC) < 3) {
        //   continue;
        // }
        pp_.setWaypoints(global_path);
        pp_.mission_flag = 4;
        const_lookahead_distance_ = 4;
        const_velocity_ = 6;
        final_constant = 1.5;
      }

      // If failed the mission
      //pp_.mission_flag = 4;
      //const_lookahead_distance_ = 4;
      //const_velocity_ = 6;
      //final_constant = 1.5;

      // 세번째 신호등 인덱스 : tf_idx_3, temp comment
      if(pp_.mission_flag == 0 && pp_.reachMissionIdx(tf_idx_3) && !pp_.straight_go_flag) {
        pulishControlMsg(0,0);
        continue;
      }
    }

    // MODE 5 : 배달 PICK A 
    if (pp_.mode == 5) {
      const_lookahead_distance_ = 6;
      const_velocity_ = 8;
      final_constant = 1.2;

      if(pp_.mission_flag==0 && pp_.reachMissionIdx(dv_a_idx_1)) {
        for (int i = 0; i < 50; i++)
        {
          pulishControlMsg(0, 0);
          // 0.1초
          usleep(100000);
        }
        pp_.mission_flag = 1;
        const_velocity_ = 10;
        continue;
      }
    }
    
    /*
    // MODE 6 : 배달 PICK B 
    if (pp_.mode == 6) {
      const_lookahead_distance_ = 6;
      const_velocity_ = 8;
      final_constant = 1.2;

      if((pp_.mission_flag==0 && (pp_.a1_flag && pp_.b1_flag) && pp_.reachMissionIdx(dv_b_idx_1)) 
        || (pp_.mission_flag==0 && (pp_.a2_flag && pp_.b2_flag) && pp_.reachMissionIdx(dv_b_idx_2))
        || (pp_.mission_flag==0 && (pp_.a3_flag && pp_.b3_flag) && pp_.reachMissionIdx(dv_b_idx_3))) {
        
        for (int i = 0; i < 50; i++)
        {
          pulishControlMsg(0, 0);
          // 0.1초
          usleep(100000);
        }
        pp_.mission_flag = 1;
        continue;
      }
    }
    */

    // MODE 7 - 차선 변경
    if (pp_.mode == 7) {
      pp_.mission_flag = 0;
      const_lookahead_distance_ = 4;
      const_velocity_ = 8;
      final_constant = 1.5;
    }

    // MODE 8 - 직선 구간 (부스터)
    if(pp_.mode == 8){
      pp_.mission_flag = 0;
      const_lookahead_distance_ = 6;
      const_velocity_ = 15;
      final_constant = 1.2;      
    }


    publishPurePursuitDriveMsg(can_get_curvature, kappa);

    is_pose_set_ = false;
    loop_rate.sleep();
  }
}

void PurePursuitNode::publishPurePursuitDriveMsg(const bool& can_get_curvature, const double& kappa) const {
  double throttle_ = can_get_curvature ? const_velocity_ : 0;

  double steering_radian = convertCurvatureToSteeringAngle(wheel_base_, kappa);
  double steering_ = can_get_curvature ? (steering_radian * 180.0 / M_PI) * -1 * final_constant: 0;

  // 더하기
  steering_ += 0;


  // std::cout << "steering : " << steering_ << "\tkappa : " << kappa <<std::endl;
  pulishControlMsg(throttle_, steering_);

  // for steering visualization
  publishSteeringVisualizationMsg(steering_radian);
}

double PurePursuitNode::computeLookaheadDistance() const {
  if (true) {
    return const_lookahead_distance_;
  }
}

void PurePursuitNode::pulishControlMsg(double throttle, double steering) const
{
  race::drive_values drive_msg;
  drive_msg.throttle = throttle;
  drive_msg.steering = steering;
  drive_msg_pub.publish(drive_msg);
}


void PurePursuitNode::callbackFromCurrentPose(const geometry_msgs::PoseStampedConstPtr& msg) {
  pp_.setCurrentPose(msg);
  is_pose_set_ = true;
}

void PurePursuitNode::setPath(char** argv) {
  std::vector<std::string> paths;
  path_split(argv[1], paths, ",");
  std::ifstream global_path_file(ROS_HOME + "/paths/" + paths[0] + ".txt");
  //std::cout << ROS_HOME + "/paths/" + argv[1] << std::endl;

  // path.txt
  // <x, y, mode>
  geometry_msgs::Point p;
  double x, y;
  int mode;

  while(global_path_file >> x >> y >> mode) {
    p.x = x;
    p.y = y;
    //pp_.mode = mode;

    global_path.push_back(std::make_pair(p, mode));
    //std::cout << "global_path : " << global_path.back().x << ", " << global_path.back().y << std::endl;
  }
  if (paths.size() == 3) {
    std::ifstream parking_path_file(ROS_HOME + "/paths/" + paths[1] + ".txt");
    while(parking_path_file >> x >> y >> mode) {
      p.x = x;
      p.y = y;
      parking_path.push_back(std::make_pair(p, mode));
      //std::cout << "parking_path : " << parking_path.back().x << ", " << parking_path.back().y << std::endl;
    }

    std::ifstream avoidance_path_file(ROS_HOME + "/paths/" + paths[2] + ".txt");
    while(avoidance_path_file >> x >> y >> mode) {
      p.x = x;
      p.y = y;
      avoidance_path.push_back(std::make_pair(p, mode));
      // std::cout << "avoidance_path : " << avoidance_path.back().x << ", " << parking_path.back().y << std::endl;
    }
  }
  else if (paths.size() == 2) {
    std::ifstream parking_path_file(ROS_HOME + "/paths/" + paths[1] + ".txt");
    while(parking_path_file >> x >> y >> mode) {
      p.x = x;
      p.y = y;
      parking_path.push_back(std::make_pair(p, mode));
      // std::cout << "parking_path : " << parking_path.back().x << ", " << parking_path.back().y << std::endl;
    }
  }

  is_waypoint_set_ = true;
}

void PurePursuitNode::publishTargetPointVisualizationMsg () {
  geometry_msgs::PointStamped target_point_msg;
  target_point_msg.header.frame_id = "/base_link";
  target_point_msg.header.stamp = ros::Time::now();
  target_point_msg.point = pp_.getPoseOfNextTarget();
  target_point_pub.publish(target_point_msg);
}

void PurePursuitNode::publishCurrentPointVisualizationMsg () {
  geometry_msgs::PointStamped current_point_msg;
  current_point_msg.header.frame_id = "/base_link";
  current_point_msg.header.stamp = ros::Time::now();
  current_point_msg.point = pp_.getCurrentPose();
  current_point_pub.publish(current_point_msg);
}

void PurePursuitNode::publishSteeringVisualizationMsg (const double& steering_radian) const {
  double yaw = atan2(2.0 * (pp_.current_pose_.orientation.w * pp_.current_pose_.orientation.z + pp_.current_pose_.orientation.x * pp_.current_pose_.orientation.y), 1.0 - 2.0 * (pp_.current_pose_.orientation.y * pp_.current_pose_.orientation.y + pp_.current_pose_.orientation.z * pp_.current_pose_.orientation.z));

  double steering_vis = yaw + steering_radian;
  geometry_msgs::Quaternion _quat = tf::createQuaternionMsgFromYaw(steering_vis);
  geometry_msgs::PoseStamped pose;
  pose.header.stamp = ros::Time::now();
  pose.header.frame_id = "/base_link";
  pose.pose.position = pp_.current_pose_.position;
  pose.pose.orientation = _quat;
  steering_vis_pub.publish(pose);
}

// for main control
void PurePursuitNode::callbackFromObstacle(const avoid_obstacle::TrueObstacles& msg) {
  pp_.is_obstacle_detected = msg.detected;
  //std::cout << "msg.detected : " << msg.detected << std::endl;
}

// 왼오
void PurePursuitNode::callbackFromObstacle2(const avoid_obstacle::DetectedObstacles& msg) {
  // 전역 변수 tmp_yaw_rate
  tmp_yaw_rate = 0.0;

  left_detected = false;
  right_detected = false;
  pp_.obstacles.clear();

  // 모든 장애물 데이터 벡터에 저장
  for(unsigned int i = 0; i < msg.obstacles.size(); i++) {
      Obstacle obs = Obstacle(msg.obstacles[i].x, msg.obstacles[i].y, msg.obstacles[i].radius, msg.obstacles[i].true_radius);
      pp_.obstacles.push_back(obs);
  }

  // left avoid flag가 true 이면 인식 범위를 5로 늘림.
  if(left_avoid){
    target_dist = 5.0;
  }

  for(unsigned int i = 0; i < pp_.obstacles.size(); i++)
  {
      // 전방 0도 ~ 50도 확인
      if(pp_.obstacles[i].yaw_rate > 0 && pp_.obstacles[i].yaw_rate < 50.0)
      {
          // 전방 1m ~ target_distance 확인
          if (pp_.obstacles[i].dist < target_dist && pp_.obstacles[i].dist > min_dist){
              // ROS_INFO("Point [X,Y] : [%f, %f]", obstacles[i].x, obstacles[i].y);
              // ROS_INFO("Distance : [%f]     Yaw_Rate : [%f]", obstacles[i].dist, obstacles[i].yaw_rate);
              left_detected = true;
              tmp_yaw_rate = pp_.obstacles[i].yaw_rate;
              //tmp_distance = pp_.obstacles[i].dist;
          }
      }

      // 첫 장애물 통과후, 오른쪽 장애물 인식  => 전방 -60~0도 확인
      if(left_avoid && pp_.obstacles[i].yaw_rate > -60.0 && pp_.obstacles[i].yaw_rate <= 0)
      {
          if(pp_.obstacles[i].dist < target_dist)
          {
              // ROS_INFO("Point [X,Y] : [%f, %f]", obstacles[i].x, obstacles[i].y);
              // ROS_INFO("Distance : [%f]     Yaw_Rate : [%f]", obstacles[i].dist, obstacles[i].yaw_rate);
              right_detected = true;
              tmp_yaw_rate = pp_.obstacles[i].yaw_rate;
          }
      }

      // if(pp_.mission_flag == 4 && !right_detected) {
      //   right_avoid = true;
      // }
  }
}


/*************************************************************************************************************/
void PurePursuitNode::callbackFromTrafficLight(const darknet_ros_msgs::BoundingBoxes& msg) {
  // std::vector<darknet_ros_msgs::BoundingBox> traffic_lights = msg.bounding_boxes;
  // std::sort(traffic_lights.begin(), traffic_lights.end(), compare);

  std::vector<darknet_ros_msgs::BoundingBox> yoloObjects = msg.bounding_boxes;

  // 신호등 객체만 따로 검출함 (원근법 알고리즘 적용위함)
  std::vector<darknet_ros_msgs::BoundingBox> traffic_lights;
  for(int i=0; i<yoloObjects.size(); i++){
    if(yoloObjects[i].Class == "3 red" || yoloObjects[i].Class == "3 yellow" || yoloObjects[i].Class == "3 green" || yoloObjects[i].Class == "3 left"
      || yoloObjects[i].Class == "4 red" || yoloObjects[i].Class == "4 yellow" || yoloObjects[i].Class == "4 green" 
      || yoloObjects[i].Class == "4 red left" || yoloObjects[i].Class == "4 left go"  || yoloObjects[i].Class == "4 red yellow"){

        traffic_lights.push_back(yoloObjects[i]);

      }
    
    // 배달미션을 위한 표지판 인식
    
    if(yoloObjects[i].Class == "A1") pp_.a1_flag = true;
    if(yoloObjects[i].Class == "A2") pp_.a2_flag = true;
    if(yoloObjects[i].Class == "A3") pp_.a3_flag = true;
    if(yoloObjects[i].Class == "B1") pp_.b1_flag = true;
    if(yoloObjects[i].Class == "B2") pp_.b2_flag = true;
    if(yoloObjects[i].Class == "B3") pp_.b3_flag = true;

  }
  std::sort(traffic_lights.begin(), traffic_lights.end(), compare);


 int index = 0;

  // check mode 9 (신호등 좌회전 구간)
  if (pp_.mode == 9) {
    if(traffic_lights.size() > 1)
    {
      int first_traffic = (traffic_lights[0].xmax - traffic_lights[0].xmin) * (traffic_lights[0].ymax - traffic_lights[0].ymin);
      int second_traffic = (traffic_lights[1].xmax - traffic_lights[1].xmin) * (traffic_lights[1].ymax - traffic_lights[1].ymin);

      if(first_traffic * 0.6 < second_traffic) {
        if (traffic_lights[0].Class == "3 left" || traffic_lights[0].Class == "4 red left" || traffic_lights[0].Class == "4 left go" ||
          traffic_lights[1].Class == "3 left" || traffic_lights[1].Class == "4 red left" || traffic_lights[1].Class == "4 left go") {
            pp_.left_go_flag = true;
        }
        else {
          pp_.left_go_flag = false;
        }

        if (pp_.left_go_flag) {
          std::cout << "mode 9 left go" << std::endl;
        }
        return;
      }
    } 
 }

  if (traffic_lights[index].Class == "3 red" || traffic_lights[index].Class == "3 yellow" || traffic_lights[index].Class == "4 red" ||
      traffic_lights[index].Class == "4 yellow" || traffic_lights[index].Class == "4 red yellow")
  {
    pp_.straight_go_flag = false;
    pp_.left_go_flag = false;
  }
  else if (traffic_lights[index].Class == "3 green" || traffic_lights[index].Class == "4 green")
  {
    pp_.straight_go_flag = true;
    pp_.left_go_flag = false;
  }
  else if (traffic_lights[index].Class == "3 left" || traffic_lights[index].Class == "4 red left")
  {
    pp_.straight_go_flag = false;
    pp_.left_go_flag = true;
  }
  else if (traffic_lights[index].Class == "4 left go")
  {
    pp_.straight_go_flag = true;
    pp_.left_go_flag = true;
  }

  //traffic test
  // std::cout << "*******************" << std::endl << std::endl;
  // if (pp_.straight_go_flag){
  //   std::cout << "straight go" << std::endl;
  // }
  // if (pp_.left_go_flag) {
  //   std::cout << "left go" << std::endl;
  // }

}


double convertCurvatureToSteeringAngle(const double& wheel_base, const double& kappa) {
  return atan(wheel_base * kappa);
}

void path_split(const std::string& str, std::vector<std::string>& cont,
		const std::string& delim)
{
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) cont.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
}

bool compare(darknet_ros_msgs::BoundingBox a, darknet_ros_msgs::BoundingBox b) {
  int a_area = (a.ymax - a.ymin) * (a.xmax - a.xmin);
  int b_area = (b.ymax - b.ymin) * (b.xmax - b.xmin);

  return a_area > b_area ? true : false;
}

}  // namespace waypoint_follower
