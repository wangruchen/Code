//
//  main.cpp
//  opencv
//
//  Created by wangruchen on 15/1/31.
//  Copyright (c) 2015年 wangruchen. All rights reserved.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    string path1="/Users/wangruchen/work/program/part-matching/pic/1.jpg";
    string path2="/Users/wangruchen/work/program/part-matching/pic/1-part.png";
    Mat srcIm=imread(path1);
    Mat partIm=imread(path2);
    Mat result;
    
    matchTemplate(srcIm, partIm, result, TM_SQDIFF);
    normalize(result, result, 0, 1, NORM_MINMAX);
    double minVal,maxVal;
    Point minPoi,maxPoi;
    minMaxLoc(result, & minVal, &maxVal, &minPoi, &maxPoi);
    
    rectangle(srcIm, minPoi, Point2f(minPoi.x+partIm.cols,minPoi.y+partIm.rows), Scalar(255,0,0));
    imshow("result", srcIm);
    waitKey(0);
    return 0;
}


