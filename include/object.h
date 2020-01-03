#include <iostream>
#include "darknet.h"


class Object
{
public:
    Object(float, float);
    void estimate_dis();
    void estimate_h();
    ~Object();
private:
    float topleft;
    float bottomright;
    float distance;
};