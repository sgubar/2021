#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum(double a, double num)
{
    int summ=0;
    for(int i=0; i<a+1; i++)
        summ+=pow(num, i);
    return summ;
}

double formula(double a, double b, double c)
{
    if(pow(c,3)==0)
    {
        printf("ділення на нуль !!!");
        exit(0);
    }
    else if(a<0)
    {
        printf("значення A не може бути менше нуля !!!");
        exit(0);
    }
    return fabs((a*c-b)/pow(c,3))*sum(a, 2);
}

int main()
{
    double a,b,c,rez;
    printf("Введіть A: ");
    scanf("%Якщо", &a);
    printf("Введіть B: ");
    scanf("%Якщо", &b);
    printf("Введіть C: ");
    scanf("%Якщо", &c);
    rez = formula(a,b,c);
    printf("\наш результат буде: %f", rez);
    return 0;
}
