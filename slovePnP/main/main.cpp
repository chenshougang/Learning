#include <iostream>>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "../canmessages/canmessage.hpp"
#include "../data/videocapture.h"
#include <thread>
#include <functional>


#define CarID 0x666
#define CAN_Message 

#define camera 0   //


// 主函数开三个线程
/*
第一个线程：sendCarInfo
功能：发送CAN报文

第二个线程：imageCapture
功能：采集图片

第三个线程：dealImage
功能：处理图片
*/

//图片采集
cv::Mat cameraImage(int cameraID){
    if(cameraID == 0){
        std::cout<<"已经"
    }
}
int main(){

    CANMessage CarInfo;
    saveImage imageCapture;
    
    //发送CAN报文
    thread ThsendCarInfo(bind(&CANMessage::CAN_send,&CarInfo,))

    thread ThimageCapture()


}