#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

int OneTest (struct coef MyCoeff1, struct roots MyRootsExpected);
/// @brief OneTest - check if test works correctly
void RunTest (struct coef MyCoeff1, struct roots MyRootsExpected);
/// @brief RunTest - prints a result of one test
int UnitTests();
/// @brief UnitTests - function is used to unite all tests and read them from file
#endif
