include ../config.mk

OBJECTS	= \
	cmath.gcm \
	iostream.gcm

all: $(OBJECTS)

clean:

cmath.gcm:
	$(C++) $(CFLAGS) $(CMI_MAPPER) -x c++-system-header cmath

iostream.gcm:
	$(C++) $(CFLAGS) $(CMI_MAPPER) -x c++-system-header iostream
