SUBDIR:=lib/yolov3/
EXEC=gg
CPP:= export LD_LIBRARY_PATH=lib/yolov3; g++

all: $(SUBDIR) $(EXEC)
exe: $(EXEC)

clean:
		cd lib/yolov3; rm -rf obj *.so; cd ../../; rm -rf $(EXEC)

$(SUBDIR):
		make -C $@ all
$(EXEC): include/object.h src/object.cpp include/img.h src/img.cpp lib/yolov3/include/darknet.h
		$(CPP) -std=c++17 `pkg-config --cflags opencv` -Wl,-rpath=lib/yolov3 -Ilib/yolov3/include/ -Llib/yolov3/ src/img.cpp src/object.cpp -o $@ `pkg-config --cflags --libs opencv` -ldarknet `pkg-config --libs opencv`

.PHONY: all $(SUBDIR)