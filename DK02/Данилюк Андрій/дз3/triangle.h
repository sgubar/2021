#ifndef triangle
#define triangle

#include <stdio.h>
#include "line.h"
#include "point.h"
typedef struct tag_triangle{
	Line* AB;
	Line* BC;
	Line* CA;
}Triangle;

Triangle* createTreangleByPoint(Point* p1, Point* p2, Point* p3);
Triangle* createTreangleByLine(Line *l1, Line *l2, Line* l3);
Triangle* copyTriangle(Triangle* t);
int TestTriangle(Line* l1, Line* l2, Line* l3);
double PerimeterOfTriangle(Triangle* t);
int isEqualPointOfTreangle(Point* p1, Point* p2, Point* p3);
double SquareOfTriangle(Triangle* t);
void printTriangle(Triangle* t);
void deleteTriangle(Triangle* t);

#endif
