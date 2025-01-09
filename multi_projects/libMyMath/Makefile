include ../config.mk

TARGET	= libMyMath.a

OBJECTS	= \
	MyMath.o \
	MyMath.Types.o \
	MyMath.Compute.o \
	MyMath.IO.o

$(TARGET): $(OBJECTS)
	$(AR) $@ $(OBJECTS)
	cp -f $@ $(PATH_LIB)

MyMath.o: MyMath.Types.o MyMath.Compute.o
MyMath.Compute.o: MyMath.Types.o
MyMath.IO.o: MyMath.Types.o

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f $(GCM_LIST) $(PATH_LIB)/$(TARGET)
