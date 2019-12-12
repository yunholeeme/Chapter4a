// Chapter4a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Chapter4a.h"

using namespace cv;
using namespace std;

void drawPolys();

int main()
{
    drawPolys();

    return 0;
}

void drawPolys()
{
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

    rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
    rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

    circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);

    imshow("img", img);

    while (true) {
        int keycode = waitKey();

        if (keycode == 'i' || keycode == 'I') {
            img = ~img;
            imshow("img", img);
        }
        else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
            break;
        }
    }

    //destroyAllWindows();
}
