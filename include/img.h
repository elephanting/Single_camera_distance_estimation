#ifndef _IMG_H_
#define _IMG_H_

class Img
{
public:
    Img(char *, float, float, float, float);
    float get_w() {return w;}
    void set_w(float w_) {w = w_;}
    float get_h() {return h;}
    void set_h(float h_) {h = h_;}
    float get_cx() {return c_x;}
    void set_cx(float cx_) {c_x = cx_;}
    float get_cy() {return c_y;}
    void set_cy(float cy_) {c_y = cy_;}
    float get_fovv() {return FOV_v;}
    float get_fovh() {return FOV_h;}
    float get_coe() {return coe;}
    float get_angle() {return angle;}
    float const & camera_h() const {return H;}
    float & camera_h() {return H;}

private:
    float h; // height of img
    float w; // width of img
    float c_x; // x coord of center of img
    float c_y; // y coord of center of img
    float FOV_v;
    float FOV_h;
    float angle;
    float H; // height of camera
    float coe;
};

#endif