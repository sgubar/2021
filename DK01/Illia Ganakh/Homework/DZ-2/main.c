#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operation.h"
#include "point.h"
#include "square.h"

int main(void) {
  Point *a = createPoint();//створюємо точки
  Point *b = createPoint();
  Point *c = createPoint();
  Point *d = createPoint();
  Square *sq1 = create_Square(a, b, c, d);//створюємо квадрат
  PrintSquareInfo(sq1);//вивід координат, сторони і площі квадрата
  deletePoint(a);//чистимо память
  deletePoint(b);
  deletePoint(c);
  deletePoint(d);
  deleteSquare(sq1);
}