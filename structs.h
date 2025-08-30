/*!
    \file
*/

#ifndef STRUCTS_FUNCTIONS_H
#define STRUCTS_FUNCTIONS_H

struct coef { /// structure with double coefficients of quadratic equation
    double a; /// coefficient of x^2
    double b; /// coefficient of x
    double c; /// constant
};
struct roots { /// structure with roots of quadratic equation
    double x1; ///< first root
    double x2; ///< second root
    int nRoots; ///< number of roots
};
enum cases { /// enum cases - all possible quantity of roots of quadratic equation used in switch construction
    ERROR_ROOTS = -2,
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

const double EPS = 1e-5; /// constant which shows the accuracy of comparisons with doubles
const double EPS_ZERO = 1e-15; /// constant which shows the accuracy of comparisons doubles with zero

#endif
