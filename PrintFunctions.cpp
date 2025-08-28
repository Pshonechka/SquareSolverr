#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "PrintFunctions.h"

int PrintResults (const struct roots MyRoots) {
    switch (MyRoots.nRoots) {
        case NO_ROOTS:
            ColorOut();
            printf("Quadratic equation has no roots\n");
            break;
        case ONE_ROOT:
            ColorOut();
            printf("Quadratic equation has one root %lf\n", MyRoots.x1);
            break;
        case TWO_ROOTS:
            ColorOut();
            printf("Quadratic equation has two roots %lf, %lf\n", MyRoots.x1, MyRoots.x2);
            break;
        case INF_ROOTS:
         ColorOut();
            printf("Quadratic equation has infinity roots\n");
            break;
        default: break;
    }
    return 0;
}

void ColorOut() {
    HANDLE hConsole;
    int k = (1 + rand()) % 255;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
