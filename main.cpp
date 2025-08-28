#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "TestFunctions.h"
#include "CompareFunctions.h"
#include "InputFunctions.h"
#include "SolverFunctions.h"
#include "PrintFunctions.h"

int main() {
    struct coef MyCoeff = {.a=NAN, .b=NAN, .c=NAN};
    struct roots MyRoots = {.x1=NAN, .x2=NAN, .nRoots=ERROR_ROOTS};
    UnitTests();
    GetCoefficients(&MyCoeff);
    SquareSolver (MyCoeff, &MyRoots);
    PrintResults(MyRoots);
    return 0;
}



