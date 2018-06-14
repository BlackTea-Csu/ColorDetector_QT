#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>

namespace selfProcess {

    void salt(cv::Mat& img, int n){
            for(int k=0; k<n; k++){
                int i = rand() % img.cols;
                int j = rand() % img.rows;
                if(img.channels() == 1)
                    img.at<uchar>(j,i) = 255;
                else if(img.channels() == 3){
                    // 相当于img.at<cv::Vec3b>(j,i)成员函数返回了一个vec,然后取该vec的如[0]向量值
                    // 有typedef Vec<uchar, 3>  Vec3b
                    img.at<cv::Vec3b>(j,i) [0] = 255; // p[0] = i;p[1] = j;p[2] = i+j;m.at<Vec3b>(i,j) = p;
                    img.at<cv::Vec3b>(j,i) [1] = 255;
                    img.at<cv::Vec3b>(j,i) [2] = 255;
                }
            }
        }

    void colorReduce(const cv::Mat& img_in, cv::Mat& img_out, int div=64){
        int nl = img_in.rows;
        int nc = img_in.cols * img_in.channels();
        for(int j=0; j<nl; j++){
            // 返回第j行像素首地址
            const uchar* data = img_in.ptr<uchar>(j);
            uchar* data_out = img_out.ptr<uchar>(j);
            for(int i=0; i<nc; i++){
                data_out[i]= data[i]/div*div;
            }
        }
    }

    void sharpen2D(const cv::Mat& img_in, cv::Mat& img_out){
        cv::Mat kernel(3,3,CV_32F, cv::Scalar(0));
        kernel.at<float>(1,1) = 5.0;
        kernel.at<float>(0,1) =-1.0;
        kernel.at<float>(2,1) =-1.0;
        kernel.at<float>(1,0) =-1.0;
        kernel.at<float>(1,2) =-1.0;
        cv::filter2D(img_in, img_out, img_in.depth(), kernel);
        img_in.begin<cv::Vec3b>();
    }

    class ColorDetector{
    private:
        int minDist;  // 最小可接受距离
        cv::Vec3b target;  // 有typedef Vec<uchar, 3>  Vec3b
        cv::Mat result;
    public:
        // 默认构造函数
        ColorDetector():minDist(100){
            target[0]=target[1]=target[2]=0;
        }
        // 设置鉴别目标颜色
        void setTargetColor(unsigned char red, unsigned char green, unsigned char blue){
            target[2] = red;
            target[1] = green;
            target[0] = blue;
        }
        void setTargetColor(cv::Vec3b color){
            target = color;
        }
        // 设置色彩距离阈值
        void setColorDistanceThreshould(int distance){
            if(distance<0)
                distance=0;
            else
                minDist = distance;
        }
        // 获取间隔距离
        int getDistance(const cv::Vec3b& color)const{
            return abs(color[0]-target[0])+abs(color[1]-target[1])+abs(color[2]-target[2]);
        }
        // 处理函数
        cv::Mat process(const cv::Mat& image){
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
    };

}
