#include "square.h"
#include "operation.h"
#include "point.h"

void PrintSquareInfo(Square *name) {//вивід координат, сторони і площі квадрата
  printPoint(&name->a);
  printPoint(&name->b);
  printPoint(&name->c);
  printPoint(&name->d);
  printf("сторона квадрата %lf\n", lenght_Line(&name->a, &name->b));
  printf("площа квадрата %lf\n", area(&name->a, &name->b));
}


Square *create_Square() {//створення квадрата
  Point *a;
  Point *b;
  Point *c;
  Point *d;
  do {
    printf("\nВведіть координати квадрата\n");
    a = createPoint();
    b = createPoint();
    c = createPoint();
    d = createPoint();

      if (lenght_Line(a, b) != lenght_Line(b, c) || lenght_Line(a, c) != lenght_Line(b, d) || isEqualPoints(a, c) != 1 || isEqualPoints(a, b) != 1 || isEqualPoints(b, c) != 1)
        printf("ви ввели неправильні координати\n");
    } while (lenght_Line(a, b) != lenght_Line(b, c) || lenght_Line(a, c) != lenght_Line(b, d) || isEqualPoints(a, c) != 1 || isEqualPoints(a, b) != 1 || isEqualPoints(b, c) != 1);

  Square *square = (Square *)malloc(sizeof(Square));
  if (NULL != square) {
    square->a = *a;
    square->b = *b;
    square->c = *c;
    square->d = *d;
  }
  return square;
}

void deleteSquare(Square *name) {//видалення квадрата
  if (NULL != name) {
    free(name);
  }
}
