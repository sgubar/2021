#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "square.h"

int main(void) {
  Point *a = createPointByInput();
  Point *b = createPointByInput();
  Point *c = createPointByInput();
  Point *d = createPointByInput();
  Square *sq1 = create_Square(a, b, c, d);//створюємо квадрат
  PrintSquareInfo(sq1);//вивід координат, сторони і площі квадрата
  deleteSquare(sq1);//видалення квадрата
}
