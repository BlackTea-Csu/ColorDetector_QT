#include "opencv_process/ColorDetector.h"

ColorDetector::ColorDetector():minDist(100){
    target[0]=target[1]=target[2]=0;
}

void ColorDetector::setColorDistanceThreshould(int distance){
    if(distance<0)
        distance=0;
    minDist = distance;
}

void ColorDetector::setTargetColor(cv::Vec3b color){
    target = color;
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue){
    target[2] = red;
    target[1] = green;
    target[0] = blue;
}

// 获取间隔距离
int ColorDetector::getDistance(const cv::Vec3b& color)const{
    return abs(color[0]-target[0])+abs(color[1]-target[1])+abs(color[2]-target[2]);
}

int ColorDetector::getColorDistanceThreshould() const{
    return minDist;
}

cv::Vec3b ColorDetector::getTargetColor() const{
    return target;
}


cv::Mat ColorDetector::process(const cv::Mat &image){
    result.create(image.rows, image.cols, CV_8U);
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
    for(;it!=itend; ++it, ++itout){
        if(getDistance(*it)<minDist)
            *itout = 255;
        else
            *itout = 0;
    }
    return result;
}
