/*!
    \file
*/

#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

int IsDouble (double a);

/// @brief OneTest - check if test works correctly
/*!
\param MyCoeff1 - structure with coefficients for test
\param MyRootsExpected - structure with roots that should be
\return int
*/
int OneTest (struct coef MyCoeff1, struct roots MyRootsExpected);

/// @brief RunTest - prints a result of one test
/*!*
\param MyCoeff1 - structure with coefficients for test
\param MyRootsExpected - structure with roots that should be
\return void
*/
void RunTest (struct coef MyCoeff1, struct roots MyRootsExpected);

/// @brief UnitTests - function is used to unite all tests and read them from file
/*!*
\return int
*/
int UnitTests();

#endif
