include ../config.mk

TARGET	= libMyGraph.a

OBJECTS	= \
	MyGraph.o \
	MyGraph_Impl.o \

$(TARGET): $(OBJECTS)
	$(AR) $@ $(OBJECTS)
	cp -f $@ $(PATH_LIB)

MyGraph_Impl.o: MyGraph.o

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f $(GCM_LIST) $(PATH_LIB)/$(TARGET)
