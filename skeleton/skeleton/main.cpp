#include <opencv2/opencv.hpp>
#include <opencv2/shape.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    string imPath="/Users/wangruchen/work/program/skeleton/pic/beetle-18.png";
    Mat srcIm=imread(imPath,IMREAD_COLOR);
    
    imshow("srcIM", srcIm);
    waitKey();
    
    Mat cvtIm;
    cvtColor(srcIm, cvtIm, COLOR_RGB2GRAY);
    imshow("cvtcolor", cvtIm);
    waitKey();
    
    Mat ThrIm;
    threshold(cvtIm, ThrIm, 150, 255, THRESH_BINARY);
    imshow("threshold", ThrIm);
    waitKey();
    
    Mat skel(cvtIm.size(),CV_8U,Scalar(0));
    Mat element=getStructuringElement(MORPH_RECT, Size(3,3));
    
    Mat erodeIm;
    Mat dilateIm;
    bool sizeSkel;
    do
    {
        erode(ThrIm, erodeIm, element);
        dilate(erodeIm, dilateIm, element);
        subtract(ThrIm, dilateIm, dilateIm);
        bitwise_or(skel, dilateIm, skel);
        erodeIm.copyTo(ThrIm);
        sizeSkel=(countNonZero(ThrIm)==0);
    }while(!sizeSkel);
    imshow("skeleton", skel);
    waitKey();
    return 0;
}

