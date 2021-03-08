#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <stdio.h>
#include "point.h"
#include "line.h"

typedef struct tag_triangle {
	Point *A;
	Point *B;
	Point *C;
} Triangle;

Triangle *createTriangleByPoints(Point *p1, Point *p2,Point *p3);
float TriangleIsRectangular(Line *l1,Line *l2,Line *l3);
void deleteTriangle(Triangle *tr);
void printTriangle(Triangle *tr);





#endif // TRIANGLE_H_INCLUDED
