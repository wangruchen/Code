//
//  main.cpp
//  opencv
//
//  Created by wangruchen on 15/1/31.
//  Copyright (c) 2015年 wangruchen. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    string imPath="/Users/wangruchen/work/program/Threshold/pic/aloeL.jpg";
    Mat srcIm=imread(imPath,IMREAD_GRAYSCALE);
    Mat caiIm=imread(imPath);
    Mat thrIm;
    Mat adaIm;
    Mat colIm;
    adaptiveThreshold(srcIm, adaIm, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 5);//自适应阈值
    cvtColor(caiIm, colIm, COLOR_RGB2GRAY);//色彩变换
    threshold(srcIm, thrIm, 200, 255, THRESH_BINARY);//固定阈值二值化
    imshow("adathreshold", adaIm);
    imshow("color", colIm);
    imshow("threshold", thrIm);
    waitKey(0);
    return 0;
}


