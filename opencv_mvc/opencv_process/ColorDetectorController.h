#ifndef COLORDETECTORCONTROLLER_H
#define COLORDETECTORCONTROLLER_H

#include "opencv_process/ColorDetector.h"

class ColorDetectorController{
private:
    // 实体对象类
    ColorDetector *cdetector;
    cv::Mat image;  // 接口,输入图片对象
    cv::Mat result;  //接口,输出结果
public:
    ColorDetectorController();
    ~ColorDetectorController();
    void setColorDistanceThreshould(int distance);
    int getColorDistanceThreshould() const;
    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
    // 注意此处为何要使用引用返回值而不是直接return unsigned char,因为追溯到ColorDetector, target其实是一个cv::Vec3b
    // 若直接返回target[0],其实是返回了一个可以指向target的指针,致使后期通过该指针可以修改私有变量,应弃用
    // 一般,get方法使用引用的参数得到返回值
    void getTargetColor(unsigned char& red, unsigned char& green, unsigned char& blue) const;
    bool setInputImage(std::string filename);
    const cv::Mat getInputImage() const;
    void process();
    const cv::Mat getLastResult() const;

};



#endif

