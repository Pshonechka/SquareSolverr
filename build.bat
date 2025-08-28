g++ -c main.cpp
g++ -c TestFunctions.cpp
g++ -c InputFunctions.cpp
g++ -c PrintFunctions.cpp
g++ -c SolverFunctions.cpp
g++ -c CompareFunctions.cpp

g++ main.o TestFunctions.o SolverFunctions.o PrintFunctions.o InputFunctions.o CompareFunctions.o -o solver
