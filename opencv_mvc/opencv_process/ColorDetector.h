#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>



class ColorDetector{
    private:
        int minDist;  // 最小可接受距离
        cv::Vec3b target;  // 目标颜色, 有typedef Vec<uchar, 3>  Vec3b
        cv::Mat result;  // 结果图像
    public:
        // 默认构造函数
        ColorDetector();

        // 设置需要检测的目标颜色
        void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
        void setTargetColor(cv::Vec3b color);
        // 设置色彩距离阈值
        void setColorDistanceThreshould(int distance);

        // 获取色彩距离阈值
        int getColorDistanceThreshould() const;
        // 获取需要检测的目标颜色
        cv::Vec3b getTargetColor() const;

        // 计算颜色距离
        int getDistance(const cv::Vec3b& color) const;

        // 处理函数
        cv::Mat process(const cv::Mat& image);
};






#endif
