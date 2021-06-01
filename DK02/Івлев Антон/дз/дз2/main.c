#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main() {
    double q = rad(1,2,1,2);
    printf("Радиус: %5f \n", q);
    printf("Площадь: %5f \n", posh(q));
    printf("Длина окружности: %5f \n", o(q));
    return 0;
}
