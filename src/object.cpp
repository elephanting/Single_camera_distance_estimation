#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include "../include/object.h"
#include "../include/img.h"


void Object::set_attr(detection_with_class *result, Img *img)
{
    this->img = img;
    this->w = round(result->det.bbox.w * img->get_w());
    this->h = round(result->det.bbox.h * img->get_h());
    this->t_x = round((result->det.bbox.x - result->det.bbox.w / 2) * img->get_w());
    this->t_y = round((result->det.bbox.y - result->det.bbox.h / 2) * img->get_h());
}


void Object::estimate_dist()
{
    //float phi = this->angle + ((float)this->h / 2);
}
int main(int argc, char **argv)
{
    network* net;
    char *data = (char*)"lib/yolov3/cfg/coco.data";
    char *cfg = (char*)"lib/yolov3/cfg/yolov3-spp.cfg";
    char *weight = (char*)"lib/yolov3/weights/yolov3-spp.weights";
    char *outfile = (char*)"output.jpg";
    Img img(argv[1], argv[2], argv[3], argv[4]);
    detection_with_class *result = new detection_with_class[50]; // set 50 as limitation of object number
    int num_of_obj;
    test_detector(data, cfg, weight, argv[1], 0.25, 0.5, 0, 0, 0, 0, 0, 0, result, &num_of_obj);
    //net = load_network_custom(cfg, weight, 0, 1);
    //img = load_image_color(file, 0, 0);
    //res = network_predict_image(net, img);
    //int width = network_width(net);
    std::unique_ptr<Object[]> object(new Object[num_of_obj]);
    for (int i = 0; i < num_of_obj; ++i)
    {
        std::cout << "start" << std::endl;
        object[i].set_attr(&result[i], &img);
        std::cout << "\tleft_x: " << object[i].topleftx() << "  left_y: " << object[i].toplefty() << "  width: " << object[i].width() << "  height: " << object[i].height() << std::endl;
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