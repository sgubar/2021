#ifndef SQUARE
#define SQUARE
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

void PrintSquareInfo(Square *name);
void deleteSquare(Square *name);
Square *create_Square();
#endif
