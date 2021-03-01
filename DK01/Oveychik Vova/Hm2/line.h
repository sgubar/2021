#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <stdio.h>
#include "point.h"

typedef struct tag_line {
	Point *A;
	Point *B;
} Line;

Line *createLineByPoints(Point *p1, Point *p2);
void deleteLine(Line *l);
double lenghtLine(Line *l);


#endif // LINE_H_INCLUDED
