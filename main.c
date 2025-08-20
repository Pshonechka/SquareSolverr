#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double a ,b ,c ,d, x1, x2;
    printf("Введите коэффициенты а, b и c квадратного уравнения");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a==0.0){
        printf("Это не квадратное уравнение");
    }
    else
    {
        d=b*b-4*a*c;
        if (d<0.0){
            printf("Уравнение не имеет действительных корней");
        }
        else if
        (d==0.0){
            printf("Уравнение имеет единственный корень %lf",x1);
        }
        else{
            x1=(-b+sqrt(d))/(2*a);
            x2=(-b-sqrt(d))/(2*a);
            printf("Уравнение имеет два корня %lf, %lf",x1,x2);
        }
    }
    return 0;
}
