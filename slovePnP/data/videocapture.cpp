#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <fstream>
#include "../data/videocapture.h"
#include "../parameters/paras.h"


saveImage::saveImage(){

}

saveImage::~saveImage(){

}

void saveImage::getImageStart(){
    std::cout<< "Get Image Start!"<<std::endl;
}

int saveImage::getImage(){
        cv::VideoCapture loadImage;
        bool camera_flag = loadImage.open(camera_computer);
        if(camera_flag != true){
            std::cout << "相机打开失败" << std::endl;
        }else{
            std::cout << "相机打开成功" << std::endl;
        }
        for(;;){
            cv::Mat frame;
            loadImage >> frame;
            saveImage::frontImage.push_back(frame);
            cv::waitKey(30);
            if(saveImage::frontImage.size() > 10){
                saveImage::frontImage.pop_front();
            }
        }
        return -1;
    }