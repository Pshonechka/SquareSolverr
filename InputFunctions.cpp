#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "InputFunctions.h"

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
