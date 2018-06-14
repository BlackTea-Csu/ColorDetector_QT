#include "opencv_process/ColorDetectorController.h"

ColorDetectorController::ColorDetectorController(){
    cdetector = new ColorDetector();
}

ColorDetectorController::~ColorDetectorController(){
    delete cdetector;
}

void ColorDetectorController::setColorDistanceThreshould(int distance){
    cdetector->setColorDistanceThreshould(distance);
}

int ColorDetectorController::getColorDistanceThreshould() const{
    return cdetector->getColorDistanceThreshould();
}

void ColorDetectorController::setTargetColor(unsigned char red, unsigned char green, unsigned char blue){
    cdetector->setTargetColor(red, green, blue);
}

void ColorDetectorController::getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const{
    cv::Vec3b color = cdetector->getTargetColor();
    red = color[2];
    green = color[1];
    blue = color[0];
}

bool ColorDetectorController::setInputImage(std::string filename){
    image = cv::imread(filename);
    if(!image.data){
        return false;
    }
    else
        return true;
}

const cv::Mat ColorDetectorController::getInputImage() const{
    return image;
}

void ColorDetectorController::process(){
    result = cdetector->process(image);
}

const cv::Mat ColorDetectorController::getLastResult() const{
    return result;
}

