/*!
    \file
*/

#ifndef COMPARE_FUNCTIONS_H
#define COMPARE_FUNCTIONS_H

/// @brief CompareDoubles - compares doubles with operations (>, <, =)
/*!
\param a,b - doubles for comparison
\return int
*/
int CompareDoubles (double a, double b);

/// @brief CompareStructures - compares three elements of structures and checks if they are equal
/*!
\param AfterSolving - structure with roots that we get after program
\param MyRootsExpected - structure with roots that should be
\return int
*/
int CompareStructures (struct roots AfterSolving, struct roots MyRootsExpected);

/// @brief CompareDoubles - compares doubles with zero
/*!
\param a - double which is compared to zero
\return int
*/
int CompareWithZero (double a);

#endif
