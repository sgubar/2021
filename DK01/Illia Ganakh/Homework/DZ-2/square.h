#ifndef POINT
#define POINT
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

typedef struct tag_square{
    Point a;
    Point b;
    Point c;
    Point d;
} Square;

Square *create_Square(Point *a, Point *b, Point *c, Point *d);
void PrintSquareInfo(Square *name);
void deleteSquare(Square *name);
#endif
