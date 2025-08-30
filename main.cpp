/*!
    \file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "structs.h"
#include "TestFunctions.h"
#include "CompareFunctions.h"
#include "InputFunctions.h"
#include "SolverFunctions.h"
#include "PrintFunctions.h"

/*
int main(int argc, char* argv[]) {
    bool array_flags[] = {};
    ParseArg(argc, argv, array_flags);
    ...
    if (flag_test)
        UnitTests();
    Input();
    Solve();
    Output();
}
*/

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("opt test - prints tests \n");
        printf("interactive - offers to enter coefficients and solves equation with them\n");
        printf("poltorashka - prints a cat\n");
        return 0;
    }
    for (int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--test") == 0) {
            UnitTests();
        }
        if (strcmp(argv[i], "--interactive") == 0) {
            struct coef MyCoeff = {.a=NAN, .b=NAN, .c=NAN};
            struct roots MyRoots = {.x1=NAN, .x2=NAN, .nRoots=ERROR_ROOTS};
            do{
            GetCoefficients(&MyCoeff);
            SquareSolver (MyCoeff, &MyRoots);
            PrintResults(MyRoots);
            }while (UserChoice() == 1);
            return 0;
        }
        if (strcmp(argv[i], "--poltorashka") == 0) {
                printf("    /\\_____/\\\n");
                printf("   /  o   o  \\\n");
                printf("  ( ==  ^  == )\n");
                printf("   )         (\n");\
                printf("  (           )\n");
                printf(" ( (  )   (  ) )\n");
                printf("(__(__)___(__)__)\n");

        }
    }
}





