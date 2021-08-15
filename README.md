## 작년 전체 실행

```
roslaunch pure_pursuit go.launch path:=9-12/global.path,9-12/parking_test1,9-12/avoidance_path ld:=10 vel:=10 final_constant:=10
```



## gps-purepursuit만 실행 

```
roslaunch ublox_gps pure_pursuit.launch path:=9-12/global.path ld:=10 vel:=10 final_constant:=10
```




## GPS -> UTMK 패스 저장 
위치: pure_pursuit/paths

```
roslaunch ublox_gps path_maker.launch path:=final_path1
```




## Path에 Mode 추가 
위치: pure_pursuit/paths

```
waypoint_mode.py -m 0 -p path.txt
```



## usbcam 실행 및 저장 

```
roslaunch usb_cam usb_cam-test.launch
rosbag record -a
rosbag record -O [저장이름] /usb_cam/image_raw
```





## rosbag to video 
https://github.com/mlaiacker/rosbag2video