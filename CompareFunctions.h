#ifndef COMPARE_FUNCTIONS_H
#define COMPARE_FUNCTIONS_H

int CompareDoubles (double a, double b);
/// @brief CompareDoubles - compares doubles with operations (>, <, =)
/// @param a,b - doubles for comparison
int CompareStructures (struct roots AfterSolving, struct roots MyRootsExpected);
/// @brief CompareStructures - compares three elements of structures and checks if they are equal
int CompareWithZero (double a);
/// @brief CompareDoubles - compares doubles with zero
/// @param a - double which is compared to zero
#endif
