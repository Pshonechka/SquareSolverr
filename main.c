#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coef {
    double a;
    double b;
    double c;
};
struct roots {
    double x1;
    double x2;
    int nRoots;
};


const double EPS = 0.0001;

//Enum
const int ERROR_ROOTS = -2;
enum cases {INF_ROOTS, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

/*const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int INF_ROOTS = -1;   */

//foo(<type> <name>)
//foo(<type> *<name>)
//foo(double one1)
//foo(struct coef coefficients, struct coef *coefficients)
int CompareDoubles (double a, double b);
int SquareSolver (struct coef MyCoef, struct roots *MyRoots);
int PrintResults (struct roots MyRoots);
void CleanerBuffer();
void input_double (char symbol, double *ptr_value);
void GetCoefficients (struct coef *MyCoef);
int CompareStructures (struct roots AfterSolving, struct roots MyRootsExpected);
int OneTest (struct coef MyCoeff1, struct roots MyRootsExpected);
int TestSolveSquare();
void RunTest(struct coef MyCoeff1, struct roots MyRootsExpected);
void UnitTests();


// 0.1 + 0.2 != 0.3000000000000000004 0.3
// a 0
// a = 0.000000000000001
// EPSILON = 0.0000000001
// (0-epsilon, 0+Epsilon) epsilon 1e-10  a ->  (0-a, 0+a)
// fabs(0 - a) < EPSILON
// fabs(a - b) < EPSILON
// == -> compare doubles(a,b) -> 1 \ 0

int CompareDoubles (double a, double b) {
    if (fabs(a-b) < EPS) {
        return 1;
    }
    else if (a-b > EPS) {
        return 0;
    }
    else {
        return -1;
    }
}
                //double
int SquareSolver (struct coef MyCoeff, struct roots *MyRoots) {
    double a = MyCoeff.a;
    double b = MyCoeff.b;
    double c = MyCoeff.c;
    //float a = MyRoots.a;
    double *x1 = &(MyRoots->x1);
    double *x2 = &(MyRoots->x2);
    int *nRoots = &(MyRoots->nRoots);
    *nRoots = ERROR_ROOTS;
    if (CompareDoubles(a, 0) == 1) {
        if (CompareDoubles(b, 0) == 1) {
            return (CompareDoubles(c, 0) == 1) ? *nRoots = INF_ROOTS : *nRoots = NO_ROOTS;
        }
        else {
            if (CompareDoubles(c, 0) == 1) {
                *x1 = 0;
                *nRoots = ONE_ROOT;
            } else {
                *x1 = (-b)/c;
                *nRoots = ONE_ROOT;
            }
        }
    } else {
        double d = b*b - 4*a*c;
        printf("d = %lg\n", d);
        if (CompareDoubles(d,0) == -1) {
            *nRoots = NO_ROOTS;
        } else if (CompareDoubles(d,0) == 1) {
            *x1 = -b/(2*a);
            *nRoots = ONE_ROOT;
        } else {
            *x1 = (-b + sqrt(d)) / (2*a);
            *x2 = (-b - sqrt(d)) / (2*a);
            *nRoots = TWO_ROOTS;
        }
    }
    if (CompareDoubles(*x1,0)==1) {
        *x1 = 0;
    }
    if (CompareDoubles(*x2,0)==1) {
        *x2 = 0;
    }
    return 0;

}

int PrintResults (const struct roots MyRoots) {
    switch (MyRoots.nRoots) {
        case NO_ROOTS: printf("Уравнение не имеет корней\n");
            break;
        case ONE_ROOT: printf("Уравнение имеет единственный корень %lf\n", MyRoots.x1);
            break;
        case TWO_ROOTS: printf("Уравнение имеет два корня %lf, %lf\n", MyRoots.x1, MyRoots.x2);
            break;
        case INF_ROOTS: printf("Уравнение имеет бесконечность решений\n");
            break;
        default: break;
    }
    return 0;
}

void CleanerBuffer(){
    int SymbolFromBuffer = 0;
    while((SymbolFromBuffer = getchar()) != '\n'){}
}
// ('a', &a)
void input_double(char symbol, double *ptr_value) {
    int flag = 1;
    while (flag) {
        printf("Введите коэффициент %c\n", symbol);
        if (scanf("%lf", ptr_value) != 1) {
            CleanerBuffer();
        }
        else{
            flag = 0;
        }
    }
}

void GetCoefficients (struct coef *MyCoeff) {
    input_double('a', &(MyCoeff->a));
    input_double('b', &(MyCoeff->b));
    input_double('c', &(MyCoeff->c));
}

int CompareStructures (struct roots AfterSolving, struct roots MyRootsExpected) {
    if (CompareDoubles(AfterSolving.nRoots, MyRootsExpected.nRoots) == 1) {
        if (((CompareDoubles(AfterSolving.x1, MyRootsExpected.x2) == 1) && (CompareDoubles(AfterSolving.x2, MyRootsExpected.x1) == 1)) || ((CompareDoubles(AfterSolving.x1, MyRootsExpected.x1) == 1) && (CompareDoubles(AfterSolving.x2, MyRootsExpected.x2) == 1))) {
            return 1;
        }
    }

    return 0;
}


int OneTest (struct coef MyCoeff1, struct roots MyRootsExpected) {
    struct roots AfterSolving = {NAN, NAN, ERROR_ROOTS};
    SquareSolver(MyCoeff1, &AfterSolving);
    int c=1;
    switch (MyRootsExpected.nRoots) {
        case 1: (AfterSolving.nRoots == 0) ? c = 0 : c = 1;
            break;
        case 2: (AfterSolving.nRoots == 1 && (CompareDoubles(AfterSolving.x1, MyRootsExpected.x1) == 1 || CompareDoubles(AfterSolving.x2, MyRootsExpected.x1) == 1)) ? c = 0 : c = 1;
            break;
        case 3: (AfterSolving.nRoots == 2 && CompareStructures (AfterSolving, MyRootsExpected) == 1) ? c = 0 : c = 1;
            break;
        case 0: (AfterSolving.nRoots == -1) ? c = 0 : c = 1;
            break;
        default: break;
    }
    return c;
}


/*
int RunTest() {
// kolvo uspeshnyx testov
    int passed = 0;
    passed += 1;
    passed += OneTest(1, -5, 6, 2, 3, 2)
    ...
    return passed;  */
// kolvo ploxix
void RunTest(struct coef MyCoeff1, struct roots MyRootsExpected) {
    int failed = 0;
    failed += OneTest(MyCoeff1, MyRootsExpected);
    if (failed == 0){
        printf("ok\n");
    } else {
        printf("ne ok\n");
    }
}
/*
int TestSolveSquare() {
    double x1 = 0, x2 = 0;
    int nRoots = SquareSolver (1, -5, 6, &x1, &x2);  //2, 3
    if (!((nRoots == 2 && CompareDoubles(x2, 2) == 1 && CompareDoubles(x1, 3) == 1) || (nRoots == 2 && CompareDoubles(x2, 3) == 1 && CompareDoubles(x1, 2) == 1))) {
        printf("Ошибка: SquareSolver (1, -5, 6) -> 2, x1 = %lf, x2 = %lf (должно быть x1 = 2, x2 = 3\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    int nRoots1 = SquareSolver (1, 0, 0, &x1, &x2);  //0
    if (!((nRoots1 == 1 && CompareDoubles(x1, 0) == 1))) {
        printf("Ошибка: SquareSolver (1, 0, 0) -> 1, x1 = %lf, x2 = %lf (должно быть x1 = 0)\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    int nRoots2 = SquareSolver (0, 1, 0, &x1, &x2);  //0
    if (!((nRoots2 == 1 && CompareDoubles(x1, 0) == 1))) {
        printf("Ошибка: SquareSolver (0, 1, 0) -> 0, x1 = %lf, x2 = %lf (должно быть x1 = 0)\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    int nRoots3 = SquareSolver (1, 2, 3, &x1, &x2);  //нет корней
    if (!((nRoots3 == 0))) {
        printf("Ошибка: SquareSolver (1, 2, 3) -> 0, x1 = %lf, x2 = %lf (должны отсутствовать корни)\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    int nRoots4 = SquareSolver (0, 0, 0, &x1, &x2);  //бесконечность корней
    if (!((nRoots4 == -1))) {
        printf("Ошибка: SquareSolver (0, 0, 0) -> INF_ROOTS, x1 = %lf, x2 = %lf (должно быть бесконечное множество корней)\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    int nRoots5 = SquareSolver (0, 0, 1, &x1, &x2);  //нет корней
    if (!((nRoots4 == 0))) {
            printf("Ошибка: SquareSolver (0, 0, 1) -> 0, x1 = %lf, x2 = %lf (должны отсутствовать корни)\n", x1, x2);
        printf("nRoots = %d", nRoots);
    }
    return 0;
}
       */
void UnitTests(){
    struct fabc {
        double a;
        double b;
        double c;
    };
   /* struct coef coefff1 = {.a=0, .b=0, .c=0};
    struct coef coefff2 = {.a=0, .b=0, .c=0};
    FILE *fp = fopen("tests.txt","r"); ;
    fscanf(fp, "%lf%lf%lf", &(coefff1.a), &(coefff1.b), &(coefff1.c));
    fscanf(fp, "%lf%lf%lf", &(coefff2.a), &(coefff2.b), &(coefff2.c));
    struct roots fxx1 = {.x1=0, .x2=0, .nRoots=0};
    struct roots fxx2 = {.x1=0, .x2=0, .nRoots=0};
    fscanf(fp, "%lf%lf%d", &(fxx1.x1), &(fxx1.x2), &(fxx1.nRoots));
    fscanf(fp, "%lf%lf%d", &(fxx2.x1), &(fxx2.x2), &(fxx2.nRoots));    */
    struct coef MyCoeff1 = {.a=1, .b=-5, .c=6};
    struct coef MyCoeff2 = {.a=1, .b=0, .c=0};
    struct coef MyCoeff3 = {.a=0, .b=1, .c=0};
    struct coef MyCoeff4 = {.a=1, .b=2, .c=3};
    struct coef MyCoeff5 = {.a=0, .b=0, .c=0};
    struct coef MyCoeff6 = {.a=0, .b=0, .c=1};
    struct roots MyRootsExpected = {.x1=2, .x2=3, .nRoots=3};
    struct roots MyRootsExpected1 = {.x1=0, .x2=NAN, .nRoots=2};
    struct roots MyRootsExpected2 = {.x1=0, .x2=NAN, .nRoots=2};
    struct roots MyRootsExpected3 = {.x1=NAN, .x2=NAN, .nRoots=1};
    struct roots MyRootsExpected4 = {.x1=NAN, .x2=NAN, .nRoots=0};
    struct roots MyRootsExpected5 = {.x1=NAN, .x2=NAN, .nRoots=1};
    RunTest(MyCoeff1,MyRootsExpected);
    RunTest(MyCoeff2,MyRootsExpected1);
    RunTest(MyCoeff3,MyRootsExpected2);
    RunTest(MyCoeff4,MyRootsExpected3);
    RunTest(MyCoeff5,MyRootsExpected4);
    RunTest(MyCoeff6,MyRootsExpected5);
    //RunTest(coefff1, fxx1);
   // RunTest(coefff2, fxx2);
}

int main() {
    struct coef MyCoeff = {.a=NAN, .b=NAN, .c=NAN};
    struct roots MyRoots = {.x1=NAN, .x2=NAN, .nRoots=ERROR_ROOTS};
    UnitTests();
    GetCoefficients(&MyCoeff);
    SquareSolver (MyCoeff, &MyRoots);
    PrintResults(MyRoots);
//  TestSolveSquare();
    return 0;
}



