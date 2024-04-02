#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

int main()
{
    std::vector<double> _hist;
    _hist.push_back(7.0);
    _hist.push_back(9.0);
    _hist.push_back(1.0);
    _hist.push_back(2.0);
    _hist.push_back(3.0);
    _hist.push_back(2.0);
    _hist.push_back(7.0);
    _hist.push_back(9.0);
    _hist.push_back(1.0);
    _hist.push_back(4.0);
    _hist.push_back(2.0);
    _hist.push_back(5.0);
    _hist.push_back(7.0);
    _hist.push_back(9.0);
    _hist.push_back(1.0);   
    _hist.push_back(1.0);
    _hist.push_back(3.0);
    _hist.push_back(2.0);
    _hist.push_back(3.0);
    _hist.push_back(4.0);
    _hist.push_back(3.0);
    _hist.push_back(1.0);
    _hist.push_back(3.0);
    _hist.push_back(4.0);
    _hist.push_back(3.0);
    _hist.push_back(1.0);

    double perv_slope_first=0.0,perv_slope_second=0.0;
    cv::Mat image(500, 500, CV_8UC3, cv::Scalar(255, 255, 255));
    // cv::Point center(image.cols / 2, image.rows / 2);
    // int radius = 6;
     cv::Scalar color(0, 255, 0);  // Green color
     cv::Scalar color_x(255, 255, 0);  // Green color
     cv::Scalar color_p(25, 55, 10);  // Green color


    // cv::circle(image, center, radius, color, -1);  // -1 to fill the circle

    for(size_t i=0;i<_hist.size();i++) {
        if(i>2 && i<(_hist.size()-1)) {
        cv::Point center(i*15,(image.cols/2)-_hist[i]*15);
        cv::Point center_x(i*15,(image.cols/2));
        cv::circle(image, center_x, 3, color_x, -1);  // -1 to fill the circle
        cv::circle(image, center, 3, color, -1);  // -1 to fill the circle

            auto first=_hist[i-1];
            auto mid=_hist[i];
            auto last=_hist[i+1];
            
            auto slope_first=(mid-first)/-1;
            auto slope_second=(last-mid)/1;
            std::cout<<"first:= "<<first<<" mid:= "<<mid<<" last:= "<<last
                     <<" slope_first: "<<slope_first<<" slope_second:= "<<slope_second
                     <<" perv_slope_first:= "<<perv_slope_first<<" perv_slope_second "<<perv_slope_second<<std::endl;
        
        if(slope_first>=0 &&  perv_slope_first<= 0 && perv_slope_second<=0)
        {
            std::cout<<"peak:= "<<first<<std::endl;
            cv::Point center_p(((i-1)*15),(image.cols/2)-_hist[i-1]*15);
            cv::circle(image, center_p, 3, color_p, -1);  // -1 to fill the circle
        }  
        perv_slope_first=slope_first;
        perv_slope_second=slope_second;
        }
    
    }
    cv::imshow("Image", image);
    cv::waitKey(0);  // Wait for a key press



    return 0;
}