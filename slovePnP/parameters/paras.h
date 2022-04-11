#include <iostream>

//选择相机，电脑自带的相机：0； 外接USB相机：1；
#define camera_computer 0  

// 图像中值化参数
#define medianBlur_size 3
// 图像二值化的上下限
#define threshold_low 118
#define threshold_high 255

//霍夫园检测的参数
//第五个参数
#define circle_circle_distance 20
//第七个参数
#define circle_size 10
//第八个参数
#define circle_min_radius 10
//第九个参数
#define circle_max_radius 18


//相机内参
double cameraMatrix_0_0 = 922.277603;
double cameraMatrix_0_1 = 0;
double cameraMatrix_0_2 = 310.482087;
double cameraMatrix_1_0 = 0;
double cameraMatrix_1_1 = 915.795616;
double cameraMatrix_1_2 = 246.154904;
double cameraMatrix_2_0 = 0;
double cameraMatrix_2_1 = 0;
double cameraMatrix_2_2 = 1;

//相机畸变参数
double distCoeffs_0_0 = -0.332832;
double distCoeffs_1_0 = -0.789379;
double distCoeffs_2_0 = 0.000998;
double distCoeffs_3_0 = 0.002290;
double distCoeffs_4_0 = 5.682694;

// LED灯之间的距离  单位：cm
double distance_x = 200;
double distance_y = 68;


