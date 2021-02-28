#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


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


#endif // POINT_H_INCLUDED
