#ifndef POINT1
#define POINT1
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
#endif