# Multiple projects sample of C++20 Module

## Document

A sample with multiple projects C++20 Modules.

Detail blog in Traditional Chinese:

## Projects:

- Libraries:
  - `libStdHeaderUnit`: header unit helper project
  - `libMyMath`: `MyMath` and `MyMath.IO` modules
  - `libMyGraph`: `MyGrpah` module
- Applications:
  - `app1`

## Makefile

Only work for g++.

Still some issues:
- always rebuild system libraries
- can't clean CMI files for each project

## Compile commands

### Visual C++ Command line (2022 17.12)

#### Put `.ifc` in the project folder

```shell
cd libStdHeaderUnit
cl /std:c++20 /EHsc /exportHeader /headerName:angle cmath
cl /std:c++20 /EHsc /exportHeader /headerName:angle iostream

cd ..\libMyMath
cl /std:c++20 /EHsc /c MyMath.Types.ixx
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libStdHeaderUnit /headerUnit:angle cmath=cmath.ifc MyMath.Compute.ixx
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libStdHeaderUnit /headerUnit:angle iostream=iostream.ifc MyMath.IO.ixx
cl /std:c++20 /EHsc /c MyMath.ixx
lib /out:..\lib\libMyMath.lib MyMath.obj MyMath.Types.obj MyMath.Compute.obj MyMath.IO.obj

cd ..\libMyGraph
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libMyMath MyGraph.ixx
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libMyMath MyGraph_Impl.cpp
lib /out:..\lib\libMyGraph.lib MyGraph.obj MyGraph_Impl.obj

cd ..\app1
cl /std:c++20 /EHsc /c /ifcSearchDir ..\libMyMath /ifcSearchDir ..\libMyGraph /ifcSearchDir ..\libStdHeaderUnit /headerUnit:angle iostream=iostream.ifc main.cpp
link main.obj /LIBPATH:..\lib\ libMyMath.lib libMyGraph.lib
```

#### Put `.ifc` in a shared folder `.\bmi`

```shell
cd libStdHeaderUnit
cl /std:c++20 /EHsc /exportHeader /ifcOutput ..\bmi /headerName:angle cmath
cl /std:c++20 /EHsc /exportHeader /ifcOutput ..\bmi /headerName:angle iostream

cd ..\libMyMath
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi MyMath.Types.ixx
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi /ifcSearchDir ..\bmi /headerUnit:angle cmath=cmath.ifc MyMath.Compute.ixx
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi /ifcSearchDir ..\bmi /headerUnit:angle iostream=iostream.ifc MyMath.IO.ixx
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi /ifcSearchDir ..\bmi MyMath.ixx
lib /out:..\lib\libMyMath.lib MyMath.obj MyMath.Types.obj MyMath.Compute.obj MyMath.IO.obj

cd ..\libMyGraph
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi /ifcSearchDir ..\bmi MyGraph.ixx
cl /std:c++20 /EHsc /c /ifcOutput ..\bmi /ifcSearchDir ..\bmi MyGraph_Impl.cpp
lib /out:..\lib\libMyGraph.lib MyGraph.obj MyGraph_Impl.obj

cd ..\app1
cl /std:c++20 /EHsc /c /ifcSearchDir ..\bmi /headerUnit:angle iostream=iostream.ifc main.cpp
link main.obj /LIBPATH:..\lib\ libMyMath.lib libMyGraph.lib
```


### g++ (14.2)

#### Put `.gcm` files in shared folder `./bmi`

```shell
cd libStdHeaderUnit
g++ -std=c++20 -fmodules-ts '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++-system-header cmath
g++ -std=c++20 -fmodules-ts '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++-system-header iostream

cd ../libMyMath
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyMath.Types.ixx
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyMath.Compute.ixx
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyMath.IO.ixx
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyMath.ixx
ar rcs ../lib/libMyMath.a MyMath.o MyMath.Types.o MyMath.Compute.o MyMath.IO.o

cd ../libMyGraph
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyGraph.ixx
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi -x c++ MyGraph_Impl.cpp
ar rcs ../lib/libMyGraph.a MyGraph.o MyGraph_Impl.o

cd ../app1
g++ -std=c++20 -fmodules-ts -c '-fmodule-mapper=|@g++-mapper-server -r'../bmi main.cpp
g++ main.o -L ../lib -lMyGraph -lMyMath
```

### clang++ (18.1)

#### Put `.pcm` in the project folder

```shell
cd libStdHeaderUnit
clang++ -std=c++20 -fmodule-header=system -Wno-invalid-constexpr -xc++-header cmath
clang++ -std=c++20 -fmodule-header=system -xc++-header iostream

cd ../libMyMath
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.Types.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-file=../libStdHeaderUnit/cmath.pcm -fmodule-output -x c++-module MyMath.Compute.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-file=../libStdHeaderUnit/iostream.pcm -fmodule-output -x c++-module MyMath.IO.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
ar rcs ../lib/libMyMath.a MyMath.o MyMath.Types.o MyMath.Compute.o MyMath.IO.o

cd ../libMyGraph
clang++ -std=c++20 -c -fprebuilt-module-path=../libMyMath -fmodule-output -x c++-module MyGraph.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fprebuilt-module-path=../libMyMath MyGraph_Impl.cpp
ar rcs ../lib/libMyGraph.a MyGraph.o MyGraph_Impl.o

cd ../app1
clang++ -std=c++20 -c -fprebuilt-module-path=../libMyMath -fprebuilt-module-path=../libMyGraph -fmodule-file=../libStdHeaderUnit/iostream.pcm main.cpp
clang++ main.o  -L ../lib/ -lMyGraph -lMyMath
```

#### Put `.pcm` in shared folder `./bmi`

```shell
cd libStdHeaderUnit
clang++ -std=c++20 -fmodule-header=system -Wno-invalid-constexpr -xc++-header cmath
clang++ -std=c++20 -fmodule-header=system -xc++-header iostream
cp *.pcm ../bmi

cd ../libMyMath
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.Types.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-file=../bmi/cmath.pcm -fmodule-output -x c++-module MyMath.Compute.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-file=../bmi/iostream.pcm -fmodule-output -x c++-module MyMath.IO.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
ar rcs ../lib/libMyMath.a MyMath.o MyMath.Types.o MyMath.Compute.o MyMath.IO.o
cp *.pcm ../bmi

cd ../libMyGraph
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-output -x c++-module MyGraph.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. MyGraph_Impl.cpp
ar rcs ../lib/libMyGraph.a MyGraph.o MyGraph_Impl.o
cp *.pcm ../bmi

cd ../app1
clang++ -std=c++20 -c -fprebuilt-module-path=../bmi -fprebuilt-module-path=. -fmodule-file=../bmi/iostream.pcm main.cpp
clang++ main.o  -L ../lib/ -lMyGraph -lMyMath
```
