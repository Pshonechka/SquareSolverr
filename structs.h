/*!
\coef - structure with double coefficients of quadratic equation
\roots - structure with roots of quadratic equation
\EPS - constant which shows the accuracy of the equation solution
\ enum cases - all possible quantity of roots of quadratic equation used in switch constructions
*/

#ifndef STRUCTS_FUNCTIONS_H
#define STRUCTS_FUNCTIONS_H

struct coef {
    double a;
    double b;
    double c;
};
struct roots {
    double x1;
    double x2;
    int nRoots;
};
enum cases {
    ERROR_ROOTS = -2,
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

const double EPS = 1e-5;
const double EPS_ZERO = 1e-15;

#endif
