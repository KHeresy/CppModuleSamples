# Basic sample of C++20 Module header unit

## Document

see: (Traditional Chinese)

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cl /std:c++20 /EHsc /exportHeader /headerName:angle iostream
cl /std:c++20 /EHsc /exportHeader lib.h
cl /std:c++20 /EHsc /headerUnit lib.h=lib.h.ifc /headerUnit:angle iostream=iostream.ifc main.cpp
```

### g++ (14.2)

```shell
g++ -std=c++20 -fmodules-ts -x c++-system-header iostream
g++ -std=c++20 -fmodules-ts -fmodule-header lib.h
g++ -std=c++20 -fmodules-ts main.cpp
```

### clang++ (18.1)

```shell
clang++ -std=c++20 -fmodule-header=system -xc++-header iostream
clang++ -std=c++20 -fmodule-header lib.h
clang++ -std=c++20 -fmodule-file=iostream.pcm -fmodule-file=lib.pcm main.cpp
```
