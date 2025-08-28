Build
```shell
g++ -c main.cpp
g++ -c TestFunctions.cpp
g++ -c InputFunctions.cpp
g++ -c PrintFunctions.cpp
g++ -c SolverFunctions.cpp
g++ main.o TestFunctions.o SolverFunctions.o PrintFunctions.o InputFunctions.o TestFunctions.o -o solver
```
main.o и testFunctions.o
Run:
```shell
.\a.exe
.\solver.exe
```

Run script:
```shell
.\build.bat
```
