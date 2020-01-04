#include <iostream>
#include "img.h"
#include "darknet.h"


class Object
{
public:
    Object();
    void get_img_size(char*);
    void estimate_dis();
    void estimate_h();
    ~Object();
private:
    float topleft;
    float topright;
    float bottomleft;
    float bottomright;
    float width;
    float height;
    float img_h;
    float img_w;
    float distance;
};