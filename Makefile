SUBDIR:=lib/yolov3/
EXEC=gg

all: $(SUBDIR) $(EXEC)
#all: $(EXEC)

clean:
		cd lib/yolov3; rm -rf obj *.so; cd ../../; rm -rf $(EXEC)

$(SUBDIR):
		make -C $@ all
$(EXEC): include/object.h src/object.cpp lib/yolov3/include/darknet.h
		g++ -std=c++11 -Ilib/yolov3/include/ -Llib/yolov3/ src/object.cpp -o $@ -ldarknet

.PHONY: all $(SUBDIR)