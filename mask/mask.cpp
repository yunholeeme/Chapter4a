// mask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void mask_setTo()
{
    Mat src = imread("lenna.bmp", IMREAD_COLOR);
    Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

    if (src.empty() || mask.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    src.setTo(Scalar(255, 255, 255), mask);

    imshow("src", src);
    imshow("mask", mask);

    waitKey(0);
    destroyAllWindows();
}

int main()
{
    mask_setTo();
    return 0;
}
