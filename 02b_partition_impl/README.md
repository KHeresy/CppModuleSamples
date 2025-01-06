# Sample of C++20 Module Partitions (with implementation unit only)

## Document

see: (Traditional Chinese)

## Files

- `MyMath.ixx`: Primary module interface unit
- `MyMath-Types.ixx`: Module partition interface unit for types
- `MyMath-Compute.ixx`: Module partition interface unit for computing
- `MyMath-Types-Impl.cpp`: Module implementation unit
- `MyMath-Impl.cpp`: Module partition implementation unit (internal partition)

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cl /std:c++20 /EHsc /c MyMath-Types.ixx
cl /std:c++20 /EHsc /c MyMath-Compute.ixx
cl /std:c++20 /EHsc /c /internalPartition MyMath-Impl.cpp
cl /std:c++20 /EHsc /c MyMath.ixx
cl /std:c++20 /EHsc /c MyMath-Types-Impl.cpp
cl /std:c++20 /EHsc main.cpp MyMath.obj MyMath-Types.obj MyMath-Compute.obj MyMath-Types-Impl.obj MyMath-Impl.obj
```

### g++ (14.2)

```shell
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath-Types.ixx
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath-Compute.ixx
g++ -std=c++20 -fmodules-ts -c MyMath-Impl.cpp
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.ixx
g++ -std=c++20 -fmodules-ts -c MyMath-Types-Impl.cpp
g++ -std=c++20 -fmodules-ts main.cpp MyMath.o MyMath-Types.o MyMath-Compute.o MyMath-Types-Impl.o MyMath-Impl.o
```

### clang++ (18.1)

```shell
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath-Types.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath-Compute.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath-Impl.cpp
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. MyMath-Types-Impl.cpp
clang++ -std=c++20 -fprebuilt-module-path=. main.cpp MyMath.o MyMath-Types.o MyMath-Compute.o MyMath-Types-Impl.o MyMath-Impl.o
```
