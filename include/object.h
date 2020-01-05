#include <iostream>
#include "img.h"
#include "darknet.h"


class Object
{
public:
    void set_attr(detection_with_class *, Img *);
    int const & topleftx() const {return t_x;}
    int & topleftx() {return t_x;}
    int const & toplefty() const {return t_y;}
    int & toplefty() {return t_y;}
    int const & width() const {return w;}
    int & width() {return w;}
    int const & height() const {return h;}
    int & height() {return h;}

    void get_img_size();
    void estimate_dist();
    void estimate_h();
private:
    Img *img;
    int t_x;
    int t_y;
    int bottomleft;
    int bottomright;
    int w;
    int h;
    float distance;
};