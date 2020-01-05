#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include "img.h"
#include "darknet.h"

class Object
{
public:
    void set_attr(detection_with_class *, Img *);
    float const & topleftx() const {return t_x;}
    float & topleftx() {return t_x;}
    float const & toplefty() const {return t_y;}
    float & toplefty() {return t_y;}
    float const & width() const {return w;}
    float & width() {return w;}
    float const & height() const {return h;}
    float & height() {return h;}
    float const & center_x() const {return b_x;}
    float & center_x() {return b_x;}
    float const & center_y() const {return b_y;}
    float & center_y() {return b_y;}
    float const & dist() const {return distance;}
    float & dist() {return distance;}

    void get_img_size();
    void estimate_dist();
    void estimate_h();
private:
    Img *img;
    float t_x;
    float t_y;
    float b_x; // x coord of bottom center of object
    float b_y; // y coord of bottom center of object
    float w;
    float h;
    float distance;
};

#endif