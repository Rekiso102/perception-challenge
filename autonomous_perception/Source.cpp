#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    auto net = cv::dnn::readNet("yolov5s.onnx");

    std::string image_path = samples::findFile("red.png");
    Mat img = imread(image_path);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);

    int k = waitKey(0);
    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}