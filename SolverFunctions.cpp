#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "CompareFunctions.h"
#include "SolverFunctions.h"


int SquareSolver (struct coef MyCoeff, struct roots *MyRoots) {
    double a = MyCoeff.a;
    double b = MyCoeff.b;
    double c = MyCoeff.c;
    double *x1 = &(MyRoots->x1);
    double *x2 = &(MyRoots->x2);
    int *nRoots = &(MyRoots->nRoots);
    *nRoots = ERROR_ROOTS;
    if (CompareWithZero(a) == 1) {
        if (CompareWithZero(b) == 1) {
            return (CompareWithZero(c) == 1) ? *nRoots = INF_ROOTS : *nRoots = NO_ROOTS;
        }
        else {
            if (CompareWithZero(c) == 1) {
                *x1 = 0;
                *nRoots = ONE_ROOT;
            } else {
                *x1 = (-c)/b;
                *nRoots = ONE_ROOT;
            }
        }
    } else {
        double d = b*b - 4*a*c;
        if (CompareWithZero(d) == -1) {
            *nRoots = NO_ROOTS;
        } else if (CompareWithZero(d) == 1) {
            *x1 = -b/(2*a);
            *nRoots = ONE_ROOT;
        } else {
            *x1 = (-b + sqrt(d)) / (2*a);
            *x2 = (-b - sqrt(d)) / (2*a);
            *nRoots = TWO_ROOTS;
        }
    }
    if (CompareWithZero(*x1)==1) {
        *x1 = 0;
    }
    if (CompareWithZero(*x2)==1) {
        *x2 = 0;
    }
    return 0;

}
