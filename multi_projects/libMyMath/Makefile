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

MyMath.o: MyMath.ixx MyMath.Types.o MyMath.Compute.o
	$(C++) $(CFLAGS) $(CMI_MAPPER) $(CMODULE) MyMath.ixx

MyMath.Types.o: MyMath.Types.ixx
	$(C++) $(CFLAGS) $(CMI_MAPPER) $(CMODULE) MyMath.Types.ixx

MyMath.Compute.o: MyMath.Compute.ixx MyMath.Types.o
	$(C++) $(CFLAGS) $(CMI_MAPPER) $(CMODULE) MyMath.Compute.ixx

MyMath.IO.o: MyMath.IO.ixx MyMath.Types.o
	$(C++) $(CFLAGS) $(CMI_MAPPER) $(CMODULE) MyMath.IO.ixx

clean:
	rm -f *.o
	rm -f $(TARGET)
