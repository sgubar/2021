#include "operation.h"
#include "point.h"

double area(Point *a, Point *b) {//площа квадрата
  if (NULL == a || NULL == b) {
		return -1;
	}
  return lenght_Line(a, b) * lenght_Line(a, b);
}

double lenght_Line(Point *a, Point *b) {//довжина лінії
  if (NULL == a || NULL == b) {
		return -1;
	}
  long dX = a->x - b->x;
  long dY = a->y - b->y;

  return sqrt(dX * dX + dY * dY);
}