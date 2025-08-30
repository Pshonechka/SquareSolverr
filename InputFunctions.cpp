/*!
    \file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "structs.h"
#include "InputFunctions.h"
#include  "PrintFunctions.h"

#define SIZE_OF_ANSWER 4

int UserChoice() {
    int ChoiceReturn = 0;
    printf("Do you want to continue? Enter " GREEN_COLOR "yes " RESET_COLOR "or " RED_COLOR "no\n" RESET_COLOR);
    char str[SIZE_OF_ANSWER] = {};
    scanf("%s", str);
    if (!strcmp(str, "yes")) {
        ChoiceReturn = 1;
    }
    return ChoiceReturn;
}
void input_double(char symbol, double *ptr_value) {
    int flag = 1;
    while (flag) {
        printf("Enter coefficient %c\n", symbol);
        if (scanf("%lf", ptr_value) != 1) {
            CleanerBuffer();
        }
        else {
            flag = 0;
        }
    }
}

void GetCoefficients (struct coef *MyCoeff) {
    input_double('a', &(MyCoeff->a));
    input_double('b', &(MyCoeff->b));
    input_double('c', &(MyCoeff->c));
}

void CleanerBuffer(){
    int SymbolFromBuffer = 0;
    while((SymbolFromBuffer = getchar()) != '\n'){}
}
