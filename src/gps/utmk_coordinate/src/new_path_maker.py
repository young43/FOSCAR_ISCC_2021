#!/usr/bin/env python

import rospy
import rospkg
from datetime import datetime
from geometry_msgs.msg import Point
import sys

rospack = rospkg.RosPack()
ROS_HOME = rospack.get_path('pure_pursuit')

coord_data = None
f = None
def callback(coordinate):
    # global f
    global coord_data
    coord_data = coordinate
    #key = sys.stdin.readline()[0].rstrip()
    

if __name__ == '__main__':  
    rospy.init_node("path_maker")

    now = datetime.now()

    f = open(ROS_HOME + "/paths/{}-{}-{}_{}-{}.txt".format(now.year, now.month, now.day, now.hour, now.minute), 'w')
    rospy.Subscriber('utmk_coordinate', Point, callback)

    key = ''
    while not rospy.is_shutdown():
        key = raw_input()
        if key == 'q': 
            f.close()
            break

        if key == 'p':
            print(coord_data)
            f.write(str(coord_data.x) + ' ' + str(coord_data.y) + ' ' + '0' + '\n')
    

    f.close()
