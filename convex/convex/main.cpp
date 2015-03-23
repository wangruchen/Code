//
//  main.cpp
//  opencv
//
//  Created by wangruchen on 15/1/31.
//  Copyright (c) 2015年 wangruchen. All rights reserved.
//

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    string imPath="/Users/wangruchen/work/program/convex/pic/horse079.jpg";
    Mat image=imread(imPath,1);
    
    cvtColor(image, image, COLOR_RGB2GRAY);

    threshold(image, image, 150, 255, THRESH_BINARY);
    imshow("tmp", image);
    waitKey();
    
    vector<vector<Point>> contour;
    findContours(image, contour, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    vector<vector<Point>> hull(contour.size());
    for (size_t x=0; x< contour.size(); x++) {
        convexHull(Mat(contour[x]), hull[x]);
    }

    Mat black=Mat::zeros(image.size(), CV_8UC3);
    drawContours(black, contour, -1, Scalar(0,0,255));
    drawContours(black, hull, -1, Scalar(255,0,0));
    imshow("convex", black);
    waitKey();
    return 0;
}

