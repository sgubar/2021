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
