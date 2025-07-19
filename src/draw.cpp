#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat blackboard(500, 800, CV_8UC3, Scalar(0, 0, 0)); 

    circle(blackboard, Point(100, 100), 50, Scalar(0, 255, 0), -1); 

    ellipse(blackboard, Point(300, 100), Size(60, 30), 0, 0, 360, Scalar(255, 0, 0), -1); 

    rectangle(blackboard, Rect(450, 50, 100, 80), Scalar(0, 0, 255), -1); 

    line(blackboard, Point(100, 250), Point(700, 250), Scalar(255, 255, 0), 2); 

    namedWindow("blackboard", WINDOW_NORMAL);
    resizeWindow("blackboard", 640, 480);
    imshow("blackboard", blackboard);

    imwrite("E:\\VScode_Projects\\OpenCV_Demo\\result\\draw.jpg", blackboard);

    waitKey(0);
    destroyAllWindows();
    return 0;
}