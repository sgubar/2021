#ifndef POINT
#define POINT
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tag_point {
    int x;
    int y;
} Point;

Point *createPoint();
void printPoint(Point *p);
void deletePoint(Point *p);
int isEqualPoints(Point *a, Point *b);
#endif
