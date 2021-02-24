#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operation.h"
#include "point.h"
#include "square.h"

int main(void) {
  Square *sq1 = create_Square();//створюємо квадрат
  PrintSquareInfo(sq1);//вивід координат, сторони і площі квадрата
  deleteSquare(sq1);//видалення квадрата



int n;//приклад використання функції в статичному масиві
  printf("Введіть кількість квадратів від 1 до 4:\n");
      do {
        scanf("%d", &n);
      } while(n < 0 || n > 4);

      Square *square[n];

    for(int i=0; i < n; i++) {
       square[i] = create_Square();
    }
    int i = 0;
    for(int i=0; i < n; i++) {
        PrintSquareInfo(square[i]);
    }
    for(int i=0; i < n; i++) {
        deleteSquare(square[i]);
    }
}
