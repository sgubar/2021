
#pragma warning(disable : 4996)

#include <stdio.h>
#include "math_lib.h"
#include <math.h>

int main()
{
    float a, b;
    printf("Vvedite celoe chislo a > 0 \n");
    scanf("%f", &a);
    if ((floor(a) != a) || (a < 0)) {
        printf("Error");
        return 1;
    }
    int chiselnik = factorial(a);
    printf("Vvedite chislo b \n");
    scanf("%f", &b);
    float znamennik = modul((2 * a) + b);
    if (znamennik == 0) {
        printf("Znamennik = 0");
        return 1;
    }
    float result = chiselnik / znamennik;
    printf("%f", result);
    return 0;
}

