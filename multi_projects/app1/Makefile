include ../config.mk

TARGET	= app1.out

OBJECTS	= main.o

$(TARGET): $(OBJECTS)
	$(C++) -o $@ main.o -L ../lib -lMyGraph -lMyMath
	cp $@ ../

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f ../$(TARGET)
