#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double a ,b ,c ,d, x1, x2;
    printf("������� ������������ �, b � c ����������� ���������");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a==0.0){
        printf("��� �� ���������� ���������");
    }
    else
    {
        d=b*b-4*a*c;
        if (d<0.0){
            printf("��������� �� ����� �������������� ������");
        }
        else if
        (d==0.0){
            printf("��������� ����� ������������ ������ %lf",x1);
        }
        else{
            x1=(-b+sqrt(d))/(2*a);
            x2=(-b-sqrt(d))/(2*a);
            printf("��������� ����� ��� ����� %lf, %lf",x1,x2);
        }
    }
    return 0;
}
