#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/img.h"

Img::Img(char *file, char *FOVv, char *FOVh, char *angle)
{
    cv::Mat mat;
    mat = cv::imread(file);   // Read the file
    this->h = mat.rows;
    this->w = mat.cols;
    //this->FOV_v = (float *)FOVv;
    //this->FOV_h = (float *)FOVh;
    //this->angle = (float *)angle;

    std::cout << "image" << " is " << this->w << " pixels wide and " << this->h << " pixels high.\n";
}