#!/usr/bin/env python

import rospy
import numpy as np
from darknet_ros_msgs.msg import BoundingBox, BoundingBoxes
from vision_distance.msg import Delivery, DeliveryArray
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from race.msg import drive_values
import time
bridge = CvBridge()
usleep = lambda x: time.sleep(x/1000000.0)

rospy.init_node("go_straight")
drive_values_pub = rospy.Publisher('control_value', drive_values, queue_size=1)

car_run_speed = 4
max_speed = 5

a_max_index = 2
b_max_index = 0
b_cnt = [0,0,0]
a_flag = [False,False,True]
b_flag = [False,False,False]

def delivery_callback(msg):
	global flag
	global dist_x
	global dist_y
	global b_cnt, b_max_index, b_flag
	deliverySign = msg.visions
	
	for i in range(0,len(deliverySign)):
		print("#############dist##############",deliverySign[i].dist_y)
		if (deliverySign[i].dist_y > 850 and deliverySign[i].dist_y < 1050):
			if (deliverySign[i].flag == 1):
			    b_cnt[0] += 1
			if (deliverySign[i].flag == 2):
			    b_cnt[1] += 1
			if (deliverySign[i].flag == 3):
		  	    b_cnt[2] += 1
		print("total-----------B_CNT???", b_cnt)


	
	b_max_index = np.argmax(b_cnt)

	if (a_max_index == b_max_index):
		b_flag[b_max_index] = True
	else:
		b_cnt = [0,0,0]
	
	print("MAX_INDEX???", b_max_index)
	#print("B_CNT???", b_cnt)
	print("B_FLAG???", b_flag)



def image_callback(img_data):
	global bridge
	global img
	img = bridge.imgmsg_to_cv2(img_data, "bgr8")


def auto_drive():
    global car_run_speed
    global max_speed


    #if car_run_speed < max_speed:
    #    car_run_speed += 0.01

    drive_value = drive_values()

    drive_value.throttle = int(car_run_speed)
    drive_value.steering = 0.0

    if(a_flag[0] and b_flag[0]) or (a_flag[1] and b_flag[1]) or (a_flag[2] and b_flag[2]):
        
	for i in range (0, 50):
          usleep(50000)
	  drive_value.throttle = int(car_run_speed)
    	  drive_value.steering = 0
          drive_values_pub.publish(drive_value)
          usleep(100000)

        drive_value.throttle = 0

    drive_values_pub.publish(drive_value)

    #print("steer : ", drive_value.steering)
    #print("throttle : ", drive_value.throttle)


if __name__ == "__main__":
    image_sub = rospy.Subscriber("/usb_cam/image_raw/", Image, image_callback)
    delivery_sub = rospy.Subscriber("/delivery/", DeliveryArray, delivery_callback) 
    while not rospy.is_shutdown():
        auto_drive()
        rospy.sleep(0.05)

    
