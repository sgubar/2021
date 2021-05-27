#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <stdio.h>
#include "points.h"


typedef struct tag_triangle {
	Point *A;
	Point *B;
	Point *C;
} Triangle;

Triangle *createTriangleByPoints(Point *p1, Point *p2,Point *p3);
void deleteTriangle(Triangle *tr);
void printTriangle(Triangle *tr);
int TriangleIsRectangular(Point *p1,Point *p2,Point *p3);
double lenghtLin(Point *p1,Point *p2);
double SquareOfTriangle(Triangle *tr);
double PerimetrOfTriangle(Triangle *tr);




#endif // TRIANGLE_H_INCLUDED
