# Multiple projects sample of C++20 Module

## Document

A sample with multiple projects C++20 Modules.

Detail blog in Traditional Chinese:

## Projects:

- Libraries:
  - `libMyMath`: `MyMath` and `MyMath.IO` modules
- Applications:
  - `app1`

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cd libMyMath
cl /std:c++20 /EHsc /c MyMath.ixx
cl /std:c++20 /EHsc /c MyMath.IO.ixx
lib /out:libMyMath.lib MyMath.obj MyMath.IO.obj

cd ../app1
cl /std:c++20 /EHsc /c /ifcSearchDir ../libMyMath main.cpp
link main.obj /LIBPATH:..\libMyMath\ libMyMath.lib
```

### g++ (14.2)

```shell
cd libMyMath
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.ixx
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.IO.ixx
ar rcs libMyMath.a MyMath.o MyMath.IO.o

cd ../app1
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../libMyMath/gcm.cache main.cpp
g++ main.o -L ../libMyMath/ -lMyMath
```

### clang++ (18.1)

```shell
cd libMyMath
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.IO.ixx
ar rcs libMyMath.a MyMath.o MyMath.IO.o

cd ../app1
clang++ -std=c++20 -c -fprebuilt-module-path=../libMyMath main.cpp
clang++ main.o -L ../libMyMath/ -lMyMath
```
