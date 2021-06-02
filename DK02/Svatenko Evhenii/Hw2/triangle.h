#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "points.h"
#include <math.h>

typedef struct tag_triangle {
	point* A;
	point* B;
	point* C;
} triangle;

triangle* makeTriangleByPoints(point* p1, point* p2, point* p3);
void deleteTriangle(triangle* tr);
void printTriangle(triangle* tr);
int IsTriangleRectangular(point* p1, point* p2, point* p3);
double lenght(point* p1, point* p2);
double SquareOfTriangle(triangle* tr);
double PerimetrOfTriangle(triangle* tr);




#endif
