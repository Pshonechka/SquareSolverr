/*!
    \file
*/

#ifndef SOLVER_FUNCTIONS_H
#define SOLVER_FUNCTIONS_H

/// @brief SquareSolver - function is used to solve quadratic equation and writes roots in structure
/*!
\param MyCoeff - structure with coefficients of quadratic equation
\param MyRoots - structure with roots of quadratic equation
\return int
*/
int SquareSolver (struct coef MyCoef, struct roots *MyRoots);

#endif
