
.PHONY: clean run build
#target: dependences
#      command
CC = g++

CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D _DEBUG -D _EJUDGE_CLIENT_SIDE

build: solver

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

InputFunctions.o: InputFunctions.cpp
	$(CC) $(CFLAGS) -c InputFunctions.cpp

CompareFunctions.o: CompareFunctions.cpp
	$(CC) $(CFLAGS) -c CompareFunctions.cpp

PrintFunctions.o: PrintFunctions.cpp
	$(CC) $(CFLAGS) -c PrintFunctions.cpp

TestFunctions.o: TestFunctions.cpp
	$(CC) $(CFLAGS) -c TestFunctions.cpp

SolverFunctions.o: SolverFunctions.cpp
	$(CC) $(CFLAGS) -c SolverFunctions.cpp

main_test.o: main_test.cpp
	$(CC) $(CFLAGS) -c main_test.cpp

solver: TestFunctions.o PrintFunctions.o CompareFunctions.o InputFunctions.o main.o SolverFunctions.o
	$(CC) $(CFLAGS) main.o TestFunctions.o SolverFunctions.o PrintFunctions.o InputFunctions.o CompareFunctions.o -o solver

clean:
	rm *.o

main_test: main_test.o
	$(CC) $(CFLAGS) main_test.o -o main_test

run:
	.\solver.exe
