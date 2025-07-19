#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("E:\\VScode_Projects\\OpenCV_Demo\\photo\\1.jpg", IMREAD_COLOR); 
    if (img.empty()) {
        cerr << "无法读取图片" << endl;
        return -1;
    }

    namedWindow("original image", WINDOW_NORMAL);
    resizeWindow("original image", 640, 480);
    imshow("original image", img);

    cout << "cols: " << img.cols << endl;
    cout << "rows: " << img.rows << endl;
    cout << "size: " << img.size() << endl;
    cout << "total: " << img.total() << endl;
    cout << "channels: " << img.channels() << endl;
    cout << "type: " << img.type() << endl;

    waitKey(0);
    destroyAllWindows();
    return 0;
}