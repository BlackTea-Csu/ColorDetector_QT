#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>


void salt(cv::Mat& img, int n){
    for(int k=0; k<n; k++){
        int i = rand() % img.cols;
        int j = rand() % img.rows;
        if(img.channels() == 1)
            img.at<uchar>(j,i) = 255;
        else if(img.channels() == 3){
            // 相当于img.at<cv::Vec3b>(j,i)成员函数返回了一个vec,然后取该vec的如[0]向量值
            img.at<cv::Vec3b>(j,i)[0] = 255; // p[0] = i;p[1] = j;p[2] = i+j;m.at<Vec3b>(i,j) = p;
            img.at<cv::Vec3b>(j,i)[1] = 255;
            img.at<cv::Vec3b>(j,i)[2] = 255;
        }
    }
}
