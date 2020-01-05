#include <iostream>
#include <memory>
#include <cmath>
#include "../include/object.h"

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
    image im;
    
    test_detector(data, cfg, weight, argv[1], 0.25, 0.5, 0, 0, 0, 0, 0, 0, result, &num_of_obj, &im);

    std::unique_ptr<Object[]> object(new Object[num_of_obj]);
    for (int i = 0; i < num_of_obj; ++i)
    {
        object[i].set_attr(&result[i], &img);
    }
    img.set_w(img.get_w() / img.get_coe());
    std::cout << "w :" << img.get_w() << std::endl;
    img.set_h(img.get_h() / img.get_coe());
    std::cout << "h :" << img.get_h() << std::endl;
    for (int i = 0; i < num_of_obj; ++i)
    {
        object[i].estimate_dist();
        result[i].dist = object[i].dist();
        std::cout << "center_x: " << object[i].center_x() << "  center_y: " << object[i].center_y() << "  distance: " << object[i].dist() << std::endl;
    }
    draw_detector(data, im, 0.25, 0, result, &num_of_obj);
    std::cout << "done" << std::endl;
    //std::cout << num_of_obj << std::endl;
    delete[] result;
    return 0;
}