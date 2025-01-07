# Special error case of C++20 Module header unit

## Document

The function `getVal()` (from `common.h`) has different definitions in different header units.

This make MSVC / g++ / clang work in different way.

see: (Traditional Chinese)

## Compiler

### Visual C++ Command line (2022 17.12)

Command:

```shell
cl /std:c++20 /EHsc /exportHeader lib1.h
cl /std:c++20 /EHsc /exportHeader lib2.h
cl /std:c++20 /EHsc /headerUnit lib1.h=lib1.h.ifc /headerUnit lib2.h=lib2.h.ifc main.cpp
.\main.exe
```

Get `100 100 100`

If mark line 12, will get `10 10` for unknown reason.

### g++ (14.2)

Command:

```shell
g++ -std=c++20 -fmodules-ts -fmodule-header lib1.h
g++ -std=c++20 -fmodules-ts -fmodule-header lib2.h
g++ -std=c++20 -fmodules-ts main.cpp
./a.out
```

Get `100 100 100`

### clang++ (18.1)

```shell
clang++ -std=c++20 -fmodule-header lib1.h
clang++ -std=c++20 -fmodule-header lib2.h
clang++ -std=c++20 -fmodule-file=lib1.pcm -fmodule-file=lib2.pcm main.cpp
```

Compile fail:
```
'getVal' has different definitions in different modules;
```

