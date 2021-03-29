#ifndef SQUARE
#define SQUARE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

typedef struct tag_square{
    Point *a;
    Point *b;
    Point *c;
    Point *d;
} Square;

void PrintSquareArea(Square *name);
int isValidSquare(Point *a, Point *b, Point *c, Point *d);
void PrintSquareInfo(Square *name);
void deleteSquare(Square *name);
double squareArea(Square *name);
Square *create_Square(Point *a, Point *b, Point *c, Point *d);
Square *createRandNonRotatedSquare();
#endif