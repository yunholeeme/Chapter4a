// TickMeter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void time_inverse();

int main()
{
    time_inverse();

    return 0;
}

void time_inverse()
{
    Mat src = imread("hodu2.jpg", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst(src.rows, src.cols, src.type());

    TickMeter tm;
    tm.start();

    for (int j = 0; j < src.rows; j++)
    {
        for (int i = 0; i < src.cols; i++)
        {
            dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
        }
    }

    tm.stop();
    cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;

    imshow("dst", dst);
    waitKey(0);
    destroyAllWindows();
}
