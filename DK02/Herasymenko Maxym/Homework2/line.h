#ifndef line_H
#define line_H
#include <stdio.h>
#include "point.h"
typedef struct tag_line
{
	Point *A;
	Point *B;
    Point *C;
	Point *D;
} Line;

Line *createLineByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
void deleteLine(Line *l);

void printLine(Line *l);
Line *copyLine(Line *l);
double lenghtLine(Line *l);
double square(Line *l);
double power(int base, int pow);
#endif // line_H
