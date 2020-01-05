# Single_camera_distance_estimation
19fall nctu nsd term project

## Introduction
This project provides a simple methodology to estimate depth of objects in an image. The algorithm does not need a dual camera forming 3D coordinate to predict depth. It can do it using a monocular camera. You can find the algorithm in reference.

However, the algorithm can only estimate image took in small pitch angle. Pitch angle plus field of view angle in vertical direction can not be greater than 90 degrees.

In this project, I use third party library Yolov3 to detect the locations of objects and then perform the algorithm to estimate the distance between object and camera.



## Requirements
* **Linux**
* **OpenCV >= 2.4**
* **Yolov3 pretrained weight**: https://pjreddie.com/media/files/yolov3-spp.weights
```
cd lib/yolov3/

mkdir weights
```
Download at `lib/yolov3/weights`
  
## How to Compile ( using `make` )
Just do `make` in the main directory.
  
## Run
```
./estimate image_name FOVv FOVh p_angle height
```

FOVv: field of view in vertical direction

FOVh: field of view in horizontal direction

p_angle: camera pitch angle

height: camera height

angle(Degree), height(Meter)

### Example:
```
./estimate test.jpg 37 54 45 1.2 
```
output image name is `predictions.jpg`

## References
[Yolov3](https://github.com/AlexeyAB/darknet)

[Implementation Algorithm](http://www.cmlab.csie.ntu.edu.tw/~zenic/Data/Download/ICME2012/Workshops/data/4729a511.pdf)
