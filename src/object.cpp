#include "../include/object.h"
#include <iostream>

int main(int argc, char **argv)
{
    network* net;
    char *data = (char*)"lib/yolov3/cfg/coco.data";
    char *cfg = (char*)"lib/yolov3/cfg/yolov3-spp.cfg";
    char *weight = (char*)"lib/yolov3/weights/yolov3-spp.weights";
    char *outfile = (char*)"output.jpg";
    detection_with_class* result;
    int num_of_obj;
    test_detector(data, cfg, weight, argv[1], 0.25, 0.5, 0, 0, 0, outfile, 0, 0, result, &num_of_obj);
    //net = load_network_custom(cfg, weight, 0, 1);
    //img = load_image_color(file, 0, 0);
    //res = network_predict_image(net, img);
    //int width = network_width(net);
    double t = get_time_point();
    for (i = 0; i < num_of_obj; ++i)
    {
        printf("\t(left_x: %4.0f   top_y: %4.0f   width: %4.0f   height: %4.0f)\n",
                round((result[i].det.bbox.x - result[i].det.bbox.w / 2)*im.w),
                round((result[i].det.bbox.y - result[i].det.bbox.h / 2)*im.h),
                round(result[i].det.bbox.w*im.w), round(result[i].det.bbox.h*im.h));

    }
    //std::cout << num_of_obj << std::endl;
    return 0;
}