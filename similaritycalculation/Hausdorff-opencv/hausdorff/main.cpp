//
//  main.cpp
//  opencv
//
//  Created by wangruchen on 15/1/31.
//  Copyright (c) 2015年 wangruchen. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/shape/shape_distance.hpp>
#include <opencv2/shape.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

vector<Point> findContour(Mat& image)
{
    vector<vector<Point>> contour;
    vector<Point> contourCoor;
    findContours(image, contour, RETR_LIST, CHAIN_APPROX_NONE);
    for(size_t b=0; b < contour.size(); b++)
    {
        for(size_t a=0; a<contour[b].size(); a++)
        {
            contourCoor.push_back(contour[b][a]);
        }
    }
    return contourCoor;
}

int main(int argc, char* argv[])
{
    Ptr<HausdorffDistanceExtractor> hausdorffDis=createHausdorffDistanceExtractor();
    string path1="/Users/wangruchen/work/program/hausdorff/picture/01.png";
    string path2="/Users/wangruchen/work/program/hausdorff/picture/01-binary-multiple-Canny.tif";
    Mat firstIm=imread(path1,IMREAD_GRAYSCALE);
    Mat conIm=imread(path2,IMREAD_GRAYSCALE);
    vector<Point> firstContours=findContour(firstIm);
    vector<Point> otherContours=findContour(conIm);
    float distance=hausdorffDis -> computeDistance(firstContours,otherContours);
    cout << distance << endl;
    return 0;
}

