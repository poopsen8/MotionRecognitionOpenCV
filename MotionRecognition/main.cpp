#include <Windows.h>
#include <vector>
#include <opencv2\opencv.hpp>
#include "opencv2/video/tracking.hpp"

char c;

int main() {

    cv::Mat —ortexChanged, NormalImages, sukaRabotay;

    cv::namedWindow("WindowNormalImages", cv::WINDOW_NORMAL);
    cv::setWindowProperty("WindowNormalImages", cv::WINDOW_FULLSCREEN, cv::WINDOW_FULLSCREEN);
    
    cv::namedWindow("Window—ortexChanged", cv::WINDOW_NORMAL);
    cv::setWindowProperty("Window—ortexChanged", cv::WINDOW_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    cv::VideoCapture cap(0);  

    if (!cap.isOpened()) 
        std::cout << "cannot open camera";
    
    

    while (c != 27) {

        cv::resizeWindow("Window—ortexChanged", 1280, 720);   
        cv::resizeWindow("WindowNormalImages", 1280, 720);
        cap >> —ortexChanged;


        cap >> NormalImages;
        for (int rows = 0; rows < NormalImages.rows; rows++) {
            for (int cols = 0; cols < NormalImages.cols; cols++)
            {
                if (—ortexChanged.at<cv::Vec3b>(rows, cols)[0] == abs(—ortexChanged.at<cv::Vec3b>(rows, cols)[0] - NormalImages.at<cv::Vec3b>(rows, cols)[0]) && —ortexChanged.at<cv::Vec3b>(rows, cols)[0] > 25)
                {
                    cv::circle(—ortexChanged, cv::Point(cols, rows), 6, cv::Scalar(0 , 255, 0), -1);
                    // cv::rectangle(image, cv::Point(cols - 200 / 2, rows - 200 / 2), cv::Point(cols, rows), CV_RGB(0, 0, 255), 2, (0, 255, 0), 0);
                }
            }
        }

        imshow("Window—ortexChanged", —ortexChanged); // ‚˚‚Ó‰ ÏÓ‰ËÙËˆËÓ‚‡ÌÌÓ„Ó
        imshow("WindowNormalImages", NormalImages);// ‚˚‚Ó‰ ÌÓÏ‡Î¸ÌÓ„Ó ËÁÓ·ÓÊÂÌËˇ
        //imshow("Display window2", sukaRabotay);
        

        c = cv::waitKey(20);
    }


    cv::destroyWindow("Window—ortexChanged");
    cv::destroyWindow("WindowNormalImages");
    return 0;
}
