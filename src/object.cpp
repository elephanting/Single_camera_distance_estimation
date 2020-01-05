#include <iostream>
#include <memory>
#include <cmath>
#include "../include/object.h"
#include "../include/img.h"

#ifndef PI
#define PI 3.14159265
#endif

void Object::set_attr(detection_with_class *result, Img *img)
{
    this->img = img;
    this->w = result->det.bbox.w * img->get_w();
    this->h = result->det.bbox.h * img->get_h();
    this->t_x = (result->det.bbox.x - result->det.bbox.w / 2) * img->get_w();
    this->t_y = (result->det.bbox.y - result->det.bbox.h / 2) * img->get_h();
    this->c_x = this->t_x + this->w / 2;
    this->c_y = this->t_y + this->h / 2;

    /* coordinate transformation */
    this->c_x = (this->c_x - img->get_cx()) / this->img->get_coe();
    this->c_y = (img->get_cy() - this->c_y) / this->img->get_coe();
}


void Object::estimate_dist()
{
    float phi_v = this->img->get_angle() + (this->img->get_h() / 2 - this->c_y) * (this->img->get_fovv() / this->img->get_h());
    float phi_h = (this->c_x - this->img->get_w() / 2) * (this->img->get_fovh() / this->img->get_w());
    float y = this->img->camera_h() * tan(phi_v * PI / 180.0);
    float x = y * tan(phi_h * PI / 180.0);
    this->distance = sqrt(pow(y, 2) + pow(x, 2) + pow(this->img->camera_h(), 2));
}