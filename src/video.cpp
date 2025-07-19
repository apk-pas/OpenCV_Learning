#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    string videoPath = "E:\\VScode_Projects\\OpenCV_Demo\\video\\armor.mp4";

    VideoCapture cap(videoPath); 
    if (!cap.isOpened()) {
        cerr << "无法打开视频文件: " << videoPath << endl;
        return -1;
    }

    double videoFPS = cap.get(CAP_PROP_FPS);
    int delay = static_cast<int>(1000 / videoFPS);
    
    Mat frame;
    high_resolution_clock::time_point lastTime = high_resolution_clock::now();
    int frameCount = 0;
    double currentFPS = 0.0;
    
    namedWindow("Video Player", WINDOW_NORMAL);
    
    while (true) {
        if (getWindowProperty("Video Player", WND_PROP_VISIBLE) < 1) {
            break; 
        }
        
        cap >> frame; 
        if (frame.empty()) break;
        
        frameCount++;
        auto currentTime = high_resolution_clock::now();
        duration<double> elapsed = duration_cast<duration<double>>(currentTime - lastTime);
        
        if (elapsed.count() >= 1.0) {
            currentFPS = frameCount / elapsed.count();
            frameCount = 0;
            lastTime = currentTime;
        }
        
        string fpsText = "FPS: " + to_string(static_cast<int>(currentFPS));
        putText(frame, fpsText, Point(10, 30),
                FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);
        
        imshow("Video Player", frame);
        
        if (waitKey(delay) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
