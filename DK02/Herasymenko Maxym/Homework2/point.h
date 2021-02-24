#ifndef point_H
#define point_H
#include<stdio.h>
typedef struct tag_point
{
    int x;
    int y;
} Point;

Point *createPoint(int x, int y);
void printPoint(Point *p);
Point *copyPoint(Point *p);
int isEqualPoints(Point *lp, Point *rp, Point *dp, Point *zp);
void deletePoint(Point *p);
#endif // point_H

