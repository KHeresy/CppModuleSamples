# Sample of C++20 sub-modules

## Document

see: (Traditional Chinese)

## Files

- `MyMath.ixx`: main module interface unit
- `MyMath.Types.ixx`: sub-module interface unit for types
- `MyMath.Compute.ixx`: sub-module interface unit for computing
- `MyMath.IO.ixx`: sub-module interface unit for inout/output

## Compile commands

### Visual C++ Command line (2022 17.12)

```shell
cl /std:c++20 /EHsc /c MyMath.Types.ixx
cl /std:c++20 /EHsc /c MyMath.Compute.ixx
cl /std:c++20 /EHsc /c MyMath.ixx
cl /std:c++20 /EHsc /c MyMath.IO.ixx
cl /std:c++20 /EHsc main.cpp MyMath.obj MyMath.Types.obj MyMath.Compute.obj MyMath.IO.obj
```

### g++ (14.2)

```shell
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.Types.ixx
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.Compute.ixx
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.ixx
g++ -std=c++20 -fmodules-ts -c -x c++ MyMath.IO.ixx
g++ -std=c++20 -fmodules-ts main.cpp MyMath.o MyMath.Types.o MyMath.Compute.o MyMath.IO.o
```

### clang++ (18.1)

```shell
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.Types.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.Compute.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.ixx
clang++ -std=c++20 -c -fprebuilt-module-path=. -fmodule-output -x c++-module MyMath.IO.ixx
clang++ -std=c++20 -fprebuilt-module-path=. main.cpp MyMath.o MyMath.Types.o MyMath.Compute.o MyMath.IO.o
```
