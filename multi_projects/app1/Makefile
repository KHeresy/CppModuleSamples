include ../config.mk

TARGET	= app1

OBJECTS	= main.o

$(TARGET): $(OBJECTS)
	$(C++) -o $@ main.o -L ../lib -lMyGraph -lMyMath

main.o: main.cpp
	$(C++) $(CFLAGS) $(CMI_MAPPER) -c main.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)
