#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <fstream>

//采集图片单独作为一个线程

class saveImage{
    public:
        saveImage();
        ~saveImage();
        void getImageStart();

        std::deque<cv::Mat> frontImage;
    private:
        int getImage();
};