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
    this->c_x = (this->c_x - img->get_cx()) / 4324.0;
    this->c_y = (img->get_cy() - this->c_y) / 4324.0;
}


void Object::estimate_dist()
{
    //std::cout << "angle :" << this->img->get_angle() << std::endl;
    float phi_v = this->img->get_angle() + (this->img->get_h() / 2 - this->c_y) * (this->img->get_fovv() / this->img->get_h());
    //std::cout << "phi_v :" << phi_v << std::endl;
    float phi_h = (this->c_x - this->img->get_w() / 2) * (this->img->get_fovh() / this->img->get_w());
    //std::cout << "phi_h :" << phi_h << std::endl;
    float y = this->img->camera_h() * tan(phi_v * PI / 180.0);
    //std::cout << "y :" << y << std::endl;
    float x = y * tan(phi_h * PI / 180.0);
    //std::cout << "x :" << x << std::endl;
    this->distance = sqrt(pow(y, 2) + pow(x, 2) + pow(this->img->camera_h(), 2));
    //std::cout << "dist :" << this->distance << std::endl;
}
int main(int argc, char **argv)
{
    char *data = (char*)"lib/yolov3/cfg/coco.data";
    char *cfg = (char*)"lib/yolov3/cfg/yolov3-spp.cfg";
    char *weight = (char*)"lib/yolov3/weights/yolov3-spp.weights";
    char *outfile = (char*)"output.jpg";
    float fovv = atoi(argv[2]);
    float fovh = atoi(argv[3]);
    float ang = atoi(argv[4]);
    float h_ = atoi(argv[5]);
    Img img(argv[1], fovv, fovh, ang, h_);
    
    detection_with_class *result = new detection_with_class[50]; // set 50 as limitation of total object counts
    int num_of_obj;
    
    test_detector(data, cfg, weight, argv[1], 0.25, 0.5, 0, 0, 0, 0, 0, 0, result, &num_of_obj);

    std::unique_ptr<Object[]> object(new Object[num_of_obj]);
    for (int i = 0; i < num_of_obj; ++i)
    {
        object[i].set_attr(&result[i], &img);
    }
    img.set_w(img.get_w() / 4324.0);
    std::cout << "w :" << img.get_w() << std::endl;
    img.set_h(img.get_h() / 4324.0);
    std::cout << "h :" << img.get_h() << std::endl;
    for (int i = 0; i < num_of_obj; ++i)
    {
        std::cout << "start" << std::endl;
        object[i].estimate_dist();
        std::cout << "\tcenter_x: " << object[i].center_x() << "  center_y: " << object[i].center_y() << "  width: " << object[i].width() << "  height: " << object[i].height() << "  distance: " << object[i].dist() << std::endl;
    }
    std::cout << "done" << std::endl;
    //std::cout << num_of_obj << std::endl;
    return 0;
}

  int topleft;
    int topright;
    int bottomleft;
    int bottomright;
    int width;
    int height;