#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

int main(void) {
  int A = 0;
  int B = 0;
  int C = 0;
  printf("Введіть A більше 0 і менше 100:\n"); //ввід з перевірками
  do {
    scanf("%d", &A);
    if (A <= 0 || A >= 100)
      printf("A повинно бути більше 0 і менше 100\n");
  } while (A <= 0 || A >= 100);

  printf("Введіть ненульове B і менше 10000 :\n");
  do {
    scanf("%d", &B);
    if (B == 0 || B >= 10000 || B <= -10000)
      printf("B повинно бути ненульовим і бути менше 10000\n");
  } while (B == 0 || B >= 10000 || B <= -10000);

  printf("Введіть додатнє C і менше 10000:\n");
  do {
    scanf("%d", &C);
    if (C <= 0 || C >= 10000)
      printf("C повинно бути більше 0 і менше 10000\n");
  } while (C <= 0 || C >= 10000);

  if ((B + C) >= 0) { //перевірка підкореневого виразу
        double Q = A * (double) (sqrt(B + C) / B) + (double) Sum_fact(A, C); //виконання обрахунків
        printf("%lf\n", Q);
  } else {
    printf("Під коренем не може бути від'ємне число\n");
    return -1;
  }

}