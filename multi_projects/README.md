# Multiple projects sample of C++20 Module

## Document

A sample with multiple projects C++20 Modules.

Detail blog in Traditional Chinese:

## Projects:

- Libraries:
  - `libStdHeaderUnit`: header unit helper project
  - `libMyMath`: `MyMath` and `MyMath.IO` modules
- Applications:
  - `app1`

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cd libStdHeaderUnit
cl /std:c++20 /EHsc /exportHeader /headerName:angle iostream

cd ../libMyMath
cl /std:c++20 /EHsc /c MyMath.ixx
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libStdHeaderUnit /headerUnit:angle iostream=iostream.ifc MyMath.IO.ixx
lib /out:libMyMath.lib MyMath.obj MyMath.IO.obj

cd ../app1
cl /std:c++20 /EHsc /c /c /ifcSearchDir ..\libMyMath /ifcSearchDir ..\libStdHeaderUnit /headerUnit:angle iostream=iostream.ifc main.cpp
link main.obj /LIBPATH:..\libMyMath\ libMyMath.lib
```

### g++ (14.2)

```shell
cd libStdHeaderUnit
g++ -std=c++20 -fmodules-ts '-fmodule-mapper=|@g++-mapper-server -r'../gcm.cache -x c++-system-header iostream

cd ../libMyMath
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../gcm.cache -x c++ MyMath.ixx
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../gcm.cache -x c++ MyMath.IO.ixx
ar rcs libMyMath.a MyMath.o MyMath.IO.o

cd ../app1
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../gcm.cache main.cpp
g++ main.o -L ../libMyMath/ -lMyMath
```

### clang++ (18.1)

```shell
cd libStdHeaderUnit
clang++ -std=c++20 -fmodule-header=system -xc++-header iostream

cd ../libMyMath
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-file=../libStdHeaderUnit/iostream.pcm -fmodule-output -x c++-module MyMath.IO.ixx
ar rcs libMyMath.a MyMath.o MyMath.IO.o

cd ../app1
clang++ -std=c++20 -c -fprebuilt-module-path=../libMyMath -fmodule-file=../libStdHeaderUnit/iostream.pcm main.cpp
clang++ main.o -L ../libMyMath/ -lMyMath
```
