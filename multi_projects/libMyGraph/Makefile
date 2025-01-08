include ../config.mk

TARGET	= libMyGraph.a

OBJECTS	= \
	MyGraph.o \
	MyGraph_Impl.o \

$(TARGET): $(OBJECTS)
	$(AR) $@ $(OBJECTS)
	cp -f $@ $(PATH_LIB)

MyGraph.o: MyGraph.ixx
	$(C++) $(CFLAGS) $(CMI_MAPPER) $(CMODULE) MyGraph.ixx

MyGraph_Impl.o: MyGraph_Impl.cpp MyGraph.o
	$(C++) $(CFLAGS) $(CMI_MAPPER) -c MyGraph_Impl.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)
