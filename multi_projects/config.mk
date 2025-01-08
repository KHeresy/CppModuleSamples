# for g++
C++	= g++
AR	= ar rcs

# Path
PATH_LIB	= ../lib
PATH_BMI	= ../bmi

# C++ Flags
CFLAGS		= --std=c++20 -fmodules-ts
CMI_MAPPER	= '-fmodule-mapper=|@g++-mapper-server -r'$(PATH_BMI)
CMODULE		= -c -x c++
