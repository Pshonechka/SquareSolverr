/*!
    \file
*/

#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#define PURPLE_COLOR "\x1b[35m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\x1b[32m"
#define RESET_COLOR "\033[1;0m"

/// @brief PrintResults - prints quantity of roots and roots x1 and x2 (if they exist)
/*!
\param MyRoots - structure with roots of quadratic equation
\return int
*/
int PrintResults (const struct roots MyRoots);
#endif
