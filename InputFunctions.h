/*!
    \file
*/

#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

int UserChoice();

/// @brief input_double - asks to enter coefficient a, b or c of quadratic equation, if user enters into a program something except for int and doubles, calls CleanerBuffer and asks user to enter coefficient again
/*!
\param symbol - letter of coefficient a, b or c
\param ptr_value - pointer to coefficient a, b or c
\return void
*/
void input_double (char symbol, double *ptr_value);

/// @brief GetCoefficients - runs three input_doubles for coefficients a,b,c
/*!
\param MyCoef - structure with coefficients of quadratic equation
\return void
*/
void GetCoefficients (struct coef *MyCoef);

/// @brief CleanerBuffer - cleans buffer
/*!
\return void
*/
void CleanerBuffer();

#endif
