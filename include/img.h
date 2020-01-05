#ifndef _IMG_H_
#define _IMG_H_

class Img
{
public:
    Img(char *, char *, char *, char *);
    int get_w() {return w;}
    int get_h() {return h;}
private:
    int h;
    int w;
    float FOV_v;
    float FOV_h;
    float angle;
};

#endif