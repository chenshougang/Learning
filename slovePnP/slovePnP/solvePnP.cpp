
#include <opencv2/calib3d.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <opencv2/tracking.hpp>
#include "../data/videocapture.h"
#include "../parameters/paras.h"

//像素坐标结构体
struct coordinate {
    int x, y;
};

//此为仿函数，用于比较像素坐标的次序
bool cmp(coordinate a, coordinate b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
};

using namespace std;
using namespace cv;

//主函数开始
int main(){

    //调用Windows系统的API计算时间，在Linux系统下，注释即可。
    //long t1 = GetTickCount();

    //相机内参矩阵
    Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
    cameraMatrix.at<double>(0, 0) = cameraMatrix_0_0;
    cameraMatrix.at<double>(0, 1) = cameraMatrix_0_1;
    cameraMatrix.at<double>(0, 2) = cameraMatrix_0_2;
    cameraMatrix.at<double>(1, 0) = cameraMatrix_1_0;
    cameraMatrix.at<double>(1, 1) = cameraMatrix_1_1;
    cameraMatrix.at<double>(1, 2) = cameraMatrix_1_1;
    cameraMatrix.at<double>(2, 0) = cameraMatrix_2_0;
    cameraMatrix.at<double>(2, 1) = cameraMatrix_2_1;
    cameraMatrix.at<double>(2, 2) = cameraMatrix_2_2;

    //相机的畸变系数
    Mat distCoeffs = Mat::zeros(5, 1, CV_64F);
    distCoeffs.at<double>(0, 0) = distCoeffs_0_0;
    distCoeffs.at<double>(1, 0) = distCoeffs_1_0;
    distCoeffs.at<double>(2, 0) = distCoeffs_2_0;
    distCoeffs.at<double>(3, 0) = distCoeffs_3_0;
    distCoeffs.at<double>(4, 0) = distCoeffs_4_0;

    //将控制点在世界坐标系的坐标压入容器
    /*
    vector<Point3f> objP;
    objP.clear();
    objP.push_back(Point3f(0, 0, 0));
    objP.push_back(Point3f(108, 0, 0));
    objP.push_back(Point3f(109, 55, 0));
    objP.push_back(Point3f(0, 55, 0));
    */

    //将控制点在世界坐标系的坐标压入容器，压入顺序为(0，0)，（1，0），（1，1），（0,1）
    vector<Point3f> objP;
    objP.clear();  
    objP.push_back(Point3f(0, 0, 0));
    objP.push_back(Point3f(distance_x, 0, 0));      //这里的值都是三维世界的真实值
    objP.push_back(Point3f(distance_x, distance_y, 0));
    objP.push_back(Point3f(0, distance_y, 0));

    
    //Mat iamge = imread("left1-5m.jpg");
    //Mat iamge = imread("left1-6m.jpg");
    //Mat iamge = imread("left1-7m.jpg");
    ////Mat iamge = imread("/home/chenshougang/Documents/slovePnP/data/test.jpg");   //读取图像，此为读取单张图像，如果需要读取视频流，可以使用videocapture类获取视频流
    //Mat iamge = imread("../data/test.jpg"); 
    saveImage frontCarImage;
    Mat image = frontCarImage.frontImage.front();
    //Mat iamge = imread("left1-9m.jpg");
    //Mat iamge = imread("left1-10m.jpg");
    cv::medianBlur(image, image, medianBlur_size);   //对图像进行中值模糊操作
    Mat image_gary;
    Mat image_binary;
    cv::cvtColor(image, image_gary, COLOR_RGB2GRAY);   //获取灰度图像  ////CV_RGB2GRAY
    //使用canny算子
    //Canny(image_gary, image_gary, 3, 9, 3);
    threshold(image_gary, image_binary, threshold_low, threshold_high, THRESH_BINARY);  //对灰度图像进行二值化，滤掉天空等浅色像素，这里的阈值为固定值。
    //Canny(image_binary, image_binary, 3, 9, 3);

    //cv::imshow("原图", image);
    //cv::imshow("canny", image_gary);
    //cv::imshow("二值化", image_binary);

    //霍夫圆检测
    vector<Vec3f> pcircles;  //存储检测到的圆
    //输入，输出，方法（类型）-HOUGH_GRADIENT，dp(dp=1时表示霍夫空间与输入图像空间的大小一致，dp=2时霍夫空间是输入图像空间的一半，以此类推)，最短距离-可以分辨是两个圆否 则认为是同心圆 ,边缘检测时使用Canny算子的高阈值，中心点累加器阈值—候选圆心（霍夫空间内累加和大于该阈值的点就对应于圆心），检测到圆的最小半径，检测到圆的的最大半径
    HoughCircles(image_binary, pcircles, HOUGH_GRADIENT, 1, circle_circle_distance, 100, circle_size, circle_min_radius, circle_min_radius);   //霍夫圆检测
    //               1          2             3          4   5   6    7   8   9
    //第一个参数是输出被检测图片
    //第二个参数表示存储数组，其中存储被检测的圆的圆心的坐标和圆的半径。
    //第三个参数默认，因为检测圆的方法，OpenCV2.*.*版本之中只有霍夫梯度法。
    //第四个参数可以设置为1就行--默认参数
    //第五个参数是圆心与圆心之间的距离，这是一个经验值。这个大了，那么多个圆就是被认为一个圆。
    //第六个参数 就设为默认值就OK
    //第七个参数是根据你的图像中的圆大小设置，当这张图片中的圆越小，那么此值就设置应该被设置越小。当设置的越小，那么检测出的圆越多，在检测较大的圆时则会产生很多噪声。所以要根据检测圆的大小变化。
    //第八个和第九个参数 是你检测圆 最小半径和最大半径是多少。这个值也是为了进一步筛选检测出的圆。

    coordinate result[4];   //存储三维世界对应圆的像素圆    只存四个圆
    //在原图画出圆心和圆
    for (size_t i = 0; i < pcircles.size(); i++){   ////size_t 无符号整数 unsigned int 

        //提取圆心坐标
        Point center(cvRound(pcircles[i][0]), cvRound(pcircles[i][1])); //cvRound 返回和参数最接近的整数值
        std::cout << pcircles[i][0] << "," << pcircles[i][1] << endl;
        //result[i] = { (pcircles[i][0],pcircles[i][1]) };
        result[i].x = pcircles[i][0];  //压入到result[4]中的x方向坐标
        result[i].y = pcircles[i][1];  //y方向圆心坐标
        //提取半径
        int radius = cvRound(pcircles[i][2]);
        //圆心
        circle(image, center, 3, Scalar(0, 255, 0), -1, 8, 0);   //画出圆心
        //圆
        circle(image, center, radius, Scalar(0, 255, 0), 3, 8, 0);  //画出圆
    }

    sort(result, result + 4, cmp);//对四个坐标进行顺时针排序  

    std::cout << result[0].x << "," << result[0].y << endl;
    std::cout << result[1].x << "," << result[1].y << endl;
    std::cout << result[2].x << "," << result[2].y << endl;
    std::cout << result[3].x << "," << result[3].y << endl;


    cv::imshow("霍夫圆检测", image);
    //cv::imwrite("test.jpg", iamge);
    //waitKey(600000);
    std::vector<Point2f> points;   //将四个圆心存入points中
    points.clear();

    //*********************************************************
    //像素坐标
    //points.push_back(Point2f(191,265));
    //points.push_back(Point2f(380, 266));
    //points.push_back(Point2f(378, 328));
    //points.push_back(Point2f(191, 329));
    //*********************************************************

        //left-20200717-0-20
        points.push_back(Point2f(283, 111));
        points.push_back(Point2f(379, 103));
        points.push_back(Point2f(377, 135));
        points.push_back(Point2f(287, 141));
        //*********************************************************

        //创建旋转矩阵和平移矩阵
        Mat rvecs = Mat::zeros(3, 1, CV_64FC1);  //旋转矩阵
        Mat tvecs = Mat::zeros(3, 1, CV_64FC1);  //平移矩阵

        //求解pnp
        cv::solvePnP(objP, points, cameraMatrix, distCoeffs, rvecs, tvecs);   //单目PnP求解
        Mat rotM = Mat::eye(3, 3, CV_64F);
        Mat rotT = Mat::eye(3, 3, CV_64F);
        cv::Rodrigues(rvecs, rotM);  //将旋转向量变换成旋转矩阵
        cv::Rodrigues(tvecs, rotT);

        //计算相机旋转角
        double theta_x, theta_y, theta_z;
        double PI = 3.14;
        //弧度制
        theta_x = atan2(rotM.at<double>(2, 1), rotM.at<double>(2, 2));
        theta_y = atan2(-rotM.at<double>(2, 0),sqrt(rotM.at<double>(2, 1) * rotM.at<double>(2, 1) + rotM.at<double>(2, 2) * rotM.at<double>(2, 2)));
        theta_z = atan2(rotM.at<double>(1, 0), rotM.at<double>(0, 0));
        //角度制
        theta_x = theta_x * (180 / PI);
        theta_y = theta_y * (180 / PI);
        theta_z = theta_z * (180 / PI);

        //计算深度
        Mat P;
        P = (rotM.t()) * tvecs;

        //输出
        std::cout << "角度" << endl;
        std::cout << theta_x << endl;
        std::cout << theta_y << endl;
        std::cout << theta_z << endl;

        //cout << P << endl;
        //cout << "z=" << P.at<double>(2)<< endl;
        std::cout << "距离=" << sqrt(P.at<double>(0) * P.at<double>(0) + P.at<double>(1) * P.at<double>(1) + P.at<double>(2) * P.at<double>(2)) << endl;
        cout << "姿态角=" << 180*atan(P.at<double>(0) / P.at<double>(2))/3.14 << endl;
        //long t2 = GetTickCount();
        //std::cout << "时间=" << (t2 - t1) << endl;
    return 0;
}

