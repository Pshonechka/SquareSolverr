#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

#include <unistd.h>

void input_double (char symbol, double *ptr_value);
/// @brief input_double - asks to enter coefficient a, b or c of quadratic equation, if user enters into a program something except
//for int and doubles, calls CleanerBuffer and asks user to enter coefficient again
/// @param symbol - letter of coefficient a, b or c
/// @param ptr_value
void GetCoefficients (struct coef *MyCoef);
/// @brief GetCoefficients - runs three input_doubles for coefficients a,b,c
void CleanerBuffer();
/// @brief CleanerBuffer - cleans buffer
#endif
