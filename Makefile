OS := $(shell uname)
VPATH=./src/
EXEC=gg
OBJDIR=./obj/

$(EXEC): include/object.h src/object.cpp lib/yolov3/include/darknet.h lib/yolov3/*.so
		g++ -std=c++11 src/object.cpp -o $@
