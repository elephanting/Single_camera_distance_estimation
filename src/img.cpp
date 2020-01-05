#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include "../include/img.h"

Img::Img(char *file, float FOVv, float FOVh, float angle, float Height)
{
    cv::Mat mat;
    mat = cv::imread(file);   // Read the file
    this->h = mat.rows;
    this->w = mat.cols;
    this->FOV_v = FOVv;
    this->FOV_h = FOVh;
    this->angle = angle;
    this->H = Height;
    this->c_x = this->w / 2;
    this->c_y = this->h / 2;
    this->coe = 4320.0;

    std::cout << "image" << " is " << this->w << " pixels wide and " << this->h << " pixels high.\n";
}