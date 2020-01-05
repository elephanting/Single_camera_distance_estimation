# Single_camera_distance_estimate
19fall nctu nsd term project

### Introduction

### Requirements
* Linux
* **OpenCV >= 2.4**
* **Yolov3 pretrained weight**: https://pjreddie.com/media/files/yolov3-spp.weights
```
cd lib/yolov3/
mkdir weights
```
Download at `lib/yolov3/weights`
  
### How to Compile(using `make`)
Just do `make` in the main directory.
  
### Run
./estimate image_name field_of_view_vertical_angle field_of_view_horizontal_angle pitch_angle camera_height
angle(Degree), height(Meter)
# Exampe:
```
./estimate test.jpg 37 54 45 1.2 
```
output image name is `predictions.jpg`

### References
[Yolov3](https://github.com/AlexeyAB/darknet)
[Algorithm](http://www.cmlab.csie.ntu.edu.tw/~zenic/Data/Download/ICME2012/Workshops/data/4729a511.pdf)
