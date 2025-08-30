/*!
    \file
*/

#include <stdio.h>//Все функции с телами и объявлениями
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "CompareFunctions.h"

//TODO: enum CompareResult {More, Less, Equal }

int CompareDoubles (double a, double b) {
    if (fabs(a-b) < EPS) {
        return 1;
    }
    else if (a-b > EPS) {
        return 0;
    } else {
        return -1;
    }
}

int CompareWithZero (double a) {
    if (fabs(a) < EPS_ZERO) {
        return 1;
    }
    else if (a > EPS_ZERO) {
        return 0;
    }
    else {
        return -1;
    }
}



int CompareStructures (struct roots AfterSolving, struct roots MyRootsExpected) {
    if (AfterSolving.nRoots == MyRootsExpected.nRoots) {
        if (((CompareDoubles(AfterSolving.x1, MyRootsExpected.x2) == 1) && (CompareDoubles(AfterSolving.x2, MyRootsExpected.x1) == 1)) ||
            ((CompareDoubles(AfterSolving.x1, MyRootsExpected.x1) == 1) && (CompareDoubles(AfterSolving.x2, MyRootsExpected.x2) == 1))) {
            return 1;
        }
    }

    return 0;
}
