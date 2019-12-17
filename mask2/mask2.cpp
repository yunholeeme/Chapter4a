// mask2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask_copyTo();

int main()
{
    mask_copyTo();
    return 0;
}

void mask_copyTo()
{
    Mat src = imread("Ih1.bmp", IMREAD_COLOR);
    Mat mask = imread("back2.bmp", IMREAD_GRAYSCALE);
    Mat dst = imread("20190816_161815328.jpg", IMREAD_COLOR);

    if (src.empty() || mask.empty() || dst.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    src.copyTo(dst, mask);

    imshow("dst", dst);
    waitKey(0);
    destroyAllWindows();
}
