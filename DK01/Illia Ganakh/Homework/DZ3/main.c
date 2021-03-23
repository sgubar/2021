#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "square.h"
#include "arraysquare.h"

int main(void) {

  ArraySquare *a = createArraySquare(5);

  Square *sq1 = createRandNonRotatedSquare();
  setSquareAtIndex(a, sq1, 0);
  printArraySquaresAreas(a);

  Square *sq2 = createRandNonRotatedSquare();
  setSquareAtIndex(a, sq2, 1);
  printArraySquaresAreas(a);
  
  Square *sq3 = createRandNonRotatedSquare();
  setSquareAtIndex(a, sq3, 3);
  printArraySquaresAreas(a);
  
  Square *sq4 = createRandNonRotatedSquare();
  setSquareAtIndex(a, sq4, 3);//заміна елемента
  printArraySquaresAreas(a);
  
  printf("масив має %d елемента/елементів\n", countArraySquare(a));
  deleteArraySquare(a);
}
