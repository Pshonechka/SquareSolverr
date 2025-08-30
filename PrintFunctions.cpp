/*!
    \file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "PrintFunctions.h"

int PrintResults (const struct roots MyRoots) {
    switch (MyRoots.nRoots) {
        case NO_ROOTS:
            printf(RED_COLOR "Quadratic equation has no roots\n" RESET_COLOR);
            break;
        case ONE_ROOT:
            printf(PURPLE_COLOR "Quadratic equation has one root %lf\n" RESET_COLOR, MyRoots.x1);
            break;
        case TWO_ROOTS:
            printf(PURPLE_COLOR "Quadratic equation has two roots %lf, %lf\n" RESET_COLOR, MyRoots.x1, MyRoots.x2);
            break;
        case INF_ROOTS:
            printf(RED_COLOR "Quadratic equation has infinity roots\n" RESET_COLOR);
            break;
        default: break;
    }
    return 0;
}
