#include "square.h"
#include "point.h"

void PrintSquareInfo(Square *name) {//вивід координат, сторони і площі квадрата
  printPoint(name->a);
  printPoint(name->b);
  printPoint(name->c);
  printPoint(name->d);
  printf("сторона квадрата %lf\n", (double)lenght_Line(name->a, name->b));
  printf("площа квадрата %lf\n", squareArea(name));
}

double squareArea(Square *name) {//площа квадрата
if(name == NULL) return -1;
  return lenght_Line(name->a, name->b) * lenght_Line(name->a, name->b);
}

int isValidSquare(Point *a, Point *b, Point *c, Point *d) {
  if (lenght_Line(a, b) != lenght_Line(b, c) || lenght_Line(a, c) != lenght_Line(b, d) || isEqualPoints(a, c) != 1 || isEqualPoints(a, b) != 1 || isEqualPoints(b, c) != 1) {
     return 0;
  }
  
  else return 1;
}

Square *create_Square(Point *a, Point *b, Point *c, Point *d) {

if (isValidSquare(a, b, c, d) != 1) {
  deletePoint(a);
  deletePoint(b);
  deletePoint(c);
  deletePoint(d);
  exit(-1);
}

  Square *square = (Square *)malloc(sizeof(Square));
  if (NULL != square) {
    square->a = a;
    square->b = b;
    square->c = c;
    square->d = d;
  }
  return square;
}

void deleteSquare(Square *name) {//видалення квадрата
  if (NULL != name) {
    free(name);
  }
}
