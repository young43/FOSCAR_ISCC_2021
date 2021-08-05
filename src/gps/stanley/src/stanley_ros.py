#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import rospkg
from geometry_msgs.msg import PoseStamped
from tf.transformations import euler_from_quaternion

from race.msg import lane_info, drive_values

import sys
import math
import time
import numpy as np
import matplotlib.pyplot as plt

# paramters
dt = 0.1

# k = 0.75  # control gain
k = 0.4

# GV70 PARAMETERS
L = 1.175  # wheel base(only use in stanley)


# PLOT Data
# LENGTH = 4.715
# WIDTH = 1.910
# BACKTOWHEEL = 1.0
# WHEEL_LEN = 0.3  # [m]
# WHEEL_WIDTH = 0.2  # [m]
# TREAD = 0.8  # [m]

drive_pub = None
pose_data = None


velocity = None
def update_pose(pose):
    global pose_data

    x = pose.pose.position.x
    y = pose.pose.position.y

    orientation_list = [pose.pose.orientation.x, pose.pose.orientation.y, pose.pose.orientation.z,pose.pose.orientation.w]
    roll, pitch, yaw = euler_from_quaternion(orientation_list)

    # yaw = math.atan2(2.0 * (pose.pose.orientation.w * pose.pose.orientation.z + pose.pose.orientation.x * pose.pose.orientation.y),
    #        1.0 - 2.0 * (pose.pose.orientation.y * pose.pose.orientation.y + pose.pose.orientation.z * pose.pose.orientation.z))

    # yaw = math.atan2(2.0 * (pose.pose.orientation.x * pose.pose.orientation.w + pose.pose.orientation.y * pose.pose.orientation.z),
    #                 1.0 - 2.0 * (pose.pose.orientation.z * pose.pose.orientation.z + pose.pose.orientation.w * pose.pose.orientation.w))

    pose_data = (x,y,yaw)


class VehicleModel:
    def __init__(self, x=0.0, y=0.0, yaw=0.0, v=10.0):
        self.x = x
        self.y = y
        self.yaw = yaw
        self.v = v

        self.max_steering = np.radians(40)

        self.prev_x = None
        self.prev_y = None

    def update_manual(self, steer, a=0):
        steer = np.clip(steer, -self.max_steering, self.max_steering)
        self.x += self.v * np.cos(self.yaw) * dt
        self.y += self.v * np.sin(self.yaw) * dt
        self.yaw += self.v / L * np.tan(steer) * dt
        self.yaw = self.yaw % (2.0 * np.pi)
        self.v += a * dt

    def update(self, steer):
        # self.x = pose.pose.position.x
        # self.y = pose.pose.position.y
        #
        # orientation_list = [pose.pose.orientation.x, pose.pose.orientation.y, pose.pose.orientation.z, pose.pose.orientation.w]
        # roll, pitch, yaw = euler_from_quaternion(orientation_list)
        # self.yaw = yaw

        self.yaw += self.v / L * np.tan(steer) * dt
        self.yaw = self.yaw % (2.0 * np.pi)

    def setPose(self, x, y, yaw):
        self.x = x
        self.y = y
        self.yaw = yaw





class Stanley:
    def __init__(self, file_path="global_path.txt"):
        self.setWayPoint(file_path)


    def setWayPoint(self, file_path):
        # UTMK 좌표로 변환된 PATH를 map_data에 저장함.
        # map_yaws는 이전 WayPoint 와 다음 WayPoint 간의 yaw 차를 저장함. (크기가 PATH-1 밖에 안되므로, 마지막 데이터 하나를 추가로 저장함.)
        self.map_xs = []
        self.map_ys = []
        self.map_yaws = []
        with open(file_path) as f:
            idx = 0
            for line in f.readlines():
                x = float(line.strip().split()[0])
                y = float(line.strip().split()[1])

                self.map_xs.append(x)
                self.map_ys.append(y)

                if idx > 0:
                    self.map_yaws.append(math.atan2(self.map_ys[idx] - self.map_ys[idx - 1], self.map_xs[idx] - self.map_xs[idx - 1]))

                idx += 1

            self.map_yaws.append(self.map_yaws[-1])

        self.current_idx = 0
        self.current_idx_flag = False
        self.prev_steer = None


    def getWayPoint(self):
        return self.map_xs, self.map_ys, self.map_yaws

    def getCurrentIndex(self):
        return self.current_idx


    def normalize_angle(self, angle):
        while angle > np.pi:
            angle -= 2.0 * np.pi

        while angle < -np.pi:
            angle += 2.0 * np.pi

        return angle

    # Stanley Method
    # v는 속도
    def control(self, x, y, yaw, v):
        # find nearest point
        min_dist = 1e9
        min_index = 0
        n_points = len(self.map_xs)

        front_x = x + L * np.cos(yaw)
        front_y = y + L * np.sin(yaw)


        # 현재 위치에서 가장 가까운 Waypoint를 Start Point로 설정함. (맨 처음 한번만 실행)
        if not self.current_idx_flag:
            for i in range(n_points):
                dx = front_x - self.map_xs[i]
                dy = front_y - self.map_ys[i]

                dist = np.sqrt(dx * dx + dy * dy)

                if dist < min_dist:
                    min_dist = dist
                    min_index = i

                    self.current_idx_flag = True
                    self.current_idx = min_index


        # 만약 Start Point 없으면 예외처리
        if not self.current_idx_flag:
            return None


        # 이미 지나갔거나, 너무 멀리 떨어진 Way Point는 잡지 않도록 처리함.
        # current_idx 는 현재 위치와 가장 가까운 Way Point 를 의미함.
        for i in range(self.current_idx, n_points):
            dx = front_x - self.map_xs[i]
            dy = front_y - self.map_ys[i]

            dist = np.sqrt(dx * dx + dy * dy)

            if dist < min_dist and abs(self.current_idx - i) <= 100:
                min_dist = dist
                min_index = i

                self.current_idx = min_index



        # compute cte at front axle
        map_x = self.map_xs[min_index]
        map_y = self.map_ys[min_index]
        map_yaw = self.map_yaws[min_index]

        dx = map_x - front_x
        dy = map_y - front_y

        perp_vec = [np.cos(yaw + np.pi/2), np.sin(yaw + np.pi/2)]
        cte = np.dot([dx, dy], perp_vec)

        # control law
        yaw_term = self.normalize_angle(map_yaw - yaw)
        cte_term = np.arctan2(k*cte, v)

        # steering
        steer = yaw_term + cte_term

        print("STEERING: {}".format(np.degrees(cte_term)))

        if abs(np.degrees(cte_term)) > 1:
            if v >= 8:
                v -= 0.2
        else:
            if v <= 14:
                v += 0.2

        # 가끔 튀는 값이 있어서 예외처리 해줌.
        # if self.prev_steer != None and abs(np.degrees(steer) - np.degrees(self.prev_steer)) >= 60:
        #    steer = self.prev_steer
        #
        # self.prev_steer = steer

        return steer, v


class States:
    def __init__(self):
        self.x = []
        self.y = []
        self.yaw = []
        self.v = []
        self.t = []

    def append(self, t, state):
        self.x.append(state.x)
        self.y.append(state.y)
        self.yaw.append(state.yaw)
        self.v.append(state.v)
        self.t.append(t)


class MovingAverage:

    def __init__(self, size=5):
        self.data_list = []
        self.size = size
        self.index = 0

    def update(self, data):
        if len(self.data_list) >= self.size:
            self.data_list.pop(0)
            self.data_list.append(data)

        else:
            self.data_list.append(data)

    def getAvg(self):
        sum_ = 0
        tmp = 0
        for i in range(len(self.data_list)):
            sum_ += self.data_list[i] * (i+1)
            tmp += (i+1)

        return sum_ / tmp




def plot_arrow(x, y, yaw, length=1.0, width=0.5, fc="r", ec="k"):
    if not isinstance(x, float):
        for ix, iy, iyaw in zip(x, y, yaw):
            plot_arrow(ix, iy, iyaw)
    else:
        plt.arrow(x, y, length * math.cos(yaw), length * math.sin(yaw),
                  fc=fc, ec=ec, head_width=width, head_length=width)
        plt.plot(x, y)


def plot_arrow2(x, y, yaw, length=1.0, width=0.5, fc="c", ec="k"):
    if not isinstance(x, float):
        for ix, iy, iyaw in zip(x, y, yaw):
            plot_arrow(ix, iy, iyaw)
    else:
        plt.arrow(x, y, length * math.cos(yaw), length * math.sin(yaw),
                  fc=fc, ec=ec, head_width=width, head_length=width)
        plt.plot(x, y)



def drive(angle, speed):
    drive_value = drive_values()
    drive_value.throttle = speed
    drive_value.steering = angle

    drive_pub.publish(drive_value)


if __name__ == "__main__":
    global velocity

    # ROS INIT
    rospy.init_node('stanley_controller')
    rospack = rospkg.RosPack()
    ROS_HOME = rospack.get_path('pure_pursuit')

    # model = VehicleModel()
    stanley = None
    vel = 2.0
    constant = 4.25

    if len(sys.argv) > 2:
        path = ROS_HOME + "/paths/" + sys.argv[1].strip() + ".txt"
        stanley = Stanley(path)

        vel = float(sys.argv[2].strip())
        constant = float(sys.argv[3].strip())

        velocity = vel


    if stanley == None:
        print("None parameter")
        exit(-1)



    rospy.Subscriber("current_pose", PoseStamped, update_pose)
    drive_pub = rospy.Publisher('control_value', drive_values, queue_size=1)

    mapx, mapy, map_yaw = stanley.getWayPoint()
    steer = 0

    mov_avg = MovingAverage(5)


    # for plot
    # start_point = (955597.3376146702, 1956917.773635644, 1.11653826186953)
    # model = VehicleModel(x=start_point[0], y=start_point[1], yaw=0, v=vel)

    model = VehicleModel(v=vel)
    # model = VehicleModel(x=mapx[0], y=mapy[0], yaw=map_yaw[0], v=vel)


    time_ = 0.0
    states = States()
    # states.append(time_, model)

    rate = rospy.Rate(10)

    start_time = time.time()
    while not rospy.is_shutdown():
        if pose_data == None: continue
        #
        # if time.time() - start_time <= 20:
        #     model.setPose(pose_data[0], pose_data[1], pose_data[2])

        model.setPose(pose_data[0], pose_data[1], pose_data[2])
        # print("model:", model.x, model.y, model.yaw, map_yaw[stanley.current_idx])


        steer, vel = stanley.control(model.x, model.y, model.yaw, vel)

        print(vel)

        if steer == None:
            print('No Neareast Point')
            break

        if stanley.getCurrentIndex() >= len(mapx) - 1:
            print("finish")
            break


        steer = np.clip(steer, -model.max_steering, model.max_steering)
        steer_deg = -np.rad2deg(steer) + constant

        # 처음부터 MAX Angle일경우, Yaw를 잘 못 잡은 것으로 판단.
        if steer >= model.max_steering and time.time()-start_time <= 20:
            continue

        print("%d : %.2f" % (stanley.getCurrentIndex(),steer_deg))


        # for manual test
        # model.update_manual(steer)

        # drive_pup
        mov_avg.update(steer_deg)
        # print(mov_avg.data_list)
        # print(mov_avg.getAvg())

        drive(mov_avg.getAvg(), vel)


        # plot test
        time_ += dt
        states.append(time_, model)
        plt.cla()
        # for stopping simulation with the esc key.
        plt.gcf().canvas.mpl_connect(
            'key_release_event',
            lambda event: [exit(0) if event.key == 'escape' else None])

        plot_arrow(model.x, model.y, model.yaw)

        plt.plot(mapx, mapy, "-r", label="course")
        plt.plot(states.x, states.y, "-b", label="trajectory")
        plt.plot(mapx[stanley.getCurrentIndex()], mapy[stanley.getCurrentIndex()], "xg", label="target")
        plt.axis("equal")
        plt.grid(True)
        plt.title("Speed[m/s]:" + str(model.v)[:4])
        plt.pause(0.001)


        rate.sleep()






    plt.cla()
    plt.plot(mapx, mapy, ".r", label="course")
    plt.plot(states.x, states.y, "-b", label="trajectory")
    plt.legend()
    plt.xlabel("x[m]")
    plt.ylabel("y[m]")
    plt.axis("equal")
    plt.grid(True)
    plt.show()
