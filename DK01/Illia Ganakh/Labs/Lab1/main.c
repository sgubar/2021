#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

int main(void) {
  int A = get_check_num_type1(A, 0, 100);//ввід чисел з перевіркою
  int B = get_check_num_type2(B, 0, -10000, 10000);
  int C = get_check_num_type1(C, 0, 10000);
  
  if ((B + C) >= 0) { //перевірка підкореневого виразу
        double Q = A * (double) (sqrt(B + C) / B) + (double) Sum_fact(A, C); //виконання обрахунків
        printf("%lf\n", Q);
  } else {
    printf("Під коренем не може бути від'ємне число\n");
    return -1;
  }
}
