#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "SolverFunctions.h"
#include "CompareFunctions.h"
#include "TestFunctions.h"

int OneTest (struct coef MyCoeff1, struct roots MyRootsExpected) {
    struct roots AfterSolving = {NAN, NAN, ERROR_ROOTS};
    SquareSolver(MyCoeff1, &AfterSolving);
    int c=1;
    switch (MyRootsExpected.nRoots) {
        case NO_ROOTS:
            if (AfterSolving.nRoots == NO_ROOTS)
                c = 0;
            break;
        case ONE_ROOT:
            if (AfterSolving.nRoots == ONE_ROOT && ((CompareDoubles(AfterSolving.x1, MyRootsExpected.x1) == 1) ||
                        (CompareDoubles(AfterSolving.x1, MyRootsExpected.x2) == 1)))
                c = 0;
            break;
        case TWO_ROOTS:
            if (AfterSolving.nRoots == TWO_ROOTS && (CompareStructures(AfterSolving, MyRootsExpected) == 1))
                c = 0;
            break;
        case INF_ROOTS:
            if (AfterSolving.nRoots == INF_ROOTS)
                c = 0;
            break;
        default: break;
    }
    return c;
}


void RunTest(struct coef MyCoeff1, struct roots MyRootsExpected) {
    if (OneTest(MyCoeff1, MyRootsExpected) == 0){
        printf("ok\n");
    } else {
        printf("ne ok\n");
    }
}

int UnitTests(){
    struct coef coeff = {.a=NAN, .b=NAN, .c=NAN};
    struct roots fxx = {.x1=NAN, .x2=NAN, .nRoots=ERROR_ROOTS};
    FILE *fp = fopen("test.txt","rb");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp); //размер файла
    fseek(fp, 0L, SEEK_SET); //курсор обратно

    char *ptr = (char*) calloc(n, sizeof(char));//выделяем память

    if ( (char*) calloc(n, sizeof(char)) == NULL) {
        printf("Error in opening file\n");
        return 0;
    }
    size_t read_size =  fread(ptr, sizeof(char), n, fp); // передаем в массив
    if (read_size != (size_t) n) { //fread - размер байтов
        printf("Error in opening file\n");
        return 0;
    }
    printf("Start: %p\n", fp);
    int n_symbols_read = 0;
    while(1) {
        coeff = {.a=NAN, .b=NAN, .c=NAN};
        fxx = {.x1=NAN, .x2=NAN, .nRoots=ERROR_ROOTS};
        // %n
        int current_shift = 0;
        if (sscanf(ptr+n_symbols_read, "%lf %lf %lf %d %n", &(coeff.a), &(coeff.b), &(coeff.c), &(fxx.nRoots), &current_shift) == EOF){
            break;
        }
        n_symbols_read += current_shift;
        if (fxx.nRoots == 2) {
            sscanf(ptr+n_symbols_read, "%lf %lf %n", &(fxx.x1), &(fxx.x2), &current_shift);
            n_symbols_read += current_shift;
        }
        if (fxx.nRoots == 1) {
            sscanf(ptr+n_symbols_read, "%lf %n", &(fxx.x1), &current_shift);
            n_symbols_read += current_shift;
        }
        RunTest(coeff, fxx);
    }
    return 0;
}
