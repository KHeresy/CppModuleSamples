# Basic sample of C++20 Module

## Document

A basic sample of C++20 Modules.

Detail blog in Traditional Chinese: https://kheresy.wordpress.com/2025/01/07/modules-of-cpp-20/

## Files

- `MyModule.ixx`: Module interface unit
- `MyModule_impl.cpp`: Module implementation unit

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cl /std:c++20 /EHsc /c MyModule.ixx
cl /std:c++20 /EHsc /c MyModule_impl.cpp
cl /std:c++20 /EHsc main.cpp MyModule.obj MyModule_impl.obj
```

### g++ (14.2)

```shell
g++ -std=c++20 -fmodules-ts -c -x c++ MyModule.ixx
g++ -std=c++20 -fmodules-ts -c MyModule_impl.cpp
g++ -std=c++20 -fmodules-ts main.cpp MyModule.o MyModule_impl.o
```

### clang++ (18.1)

```shell
clang++ -std=c++20 -c -fmodule-output -x c++-module MyModule.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. MyModule_impl.cpp
clang++ -std=c++20 -fprebuilt-module-path=. main.cpp MyModule_impl.o MyModule.o
```
