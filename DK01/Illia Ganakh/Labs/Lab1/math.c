#include "math.h"

unsigned long int Sum_fact(int A, int C) {
  unsigned long int sum = 0;
  for (int i = 0; i < C; i++)
    sum += factorial(A + i);
  return sum;
}
unsigned long int factorial(int A) {
  unsigned long int res = 0;
  if (A < 0) {
    printf("Факторіал не може бути від'ємним\n");
    exit(-1);
  } else {
    res = (A < 1) ? 1 : A * factorial(A - 1);
    return res;
  }
}

int get_check_num_type1(int a, int border1, int border2) {
printf("Введіть число більше %d і менше %d:\n", border1, border2);
  do {
    scanf("%d", &a);
    if (a <= border1 || a >= border2)
      printf("число повинно бути більше %d і менше %d:\n", border1, border2);
  } while (a <= border1 || a >= border2);
  return a;
}

int get_check_num_type2(int a, int exception, int border1, int border2) {
  printf("Введіть число яке не дорівнює %d, більше %d, і менше %d:\n", exception, border1, border2);
  do {
    scanf("%d", &a);
    if (a == exception || a <= border1 || a >= border2)
      printf("число повинно не дорівнювати %d, бути більше %d і менше %d\n", exception, border1, border2);
  } while (a == exception || a <= border1 || a >= border2);
  return a;
}
