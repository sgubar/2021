#ifndef POINT
#define POINT
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tag_point {
    int x;
    int y;
} Point;
Point *createPoint(int x, int y);
Point *createPointByInput(Point *а);
void printPoint(Point *p);
void deletePoint(Point *p);
double lenght_Line(Point *a, Point *b);
int isEqualPoints(Point *a, Point *b);
#endif