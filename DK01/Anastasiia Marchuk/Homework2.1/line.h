#ifndef line_h
#define line_h

#include <stdio.h>
#include "point.h"

typedef struct tag_line1 {
	Point *A;
	Point *B;
} Line1;

Line1 *createLine1ByPoints(Point *p1, Point *p2);
Line1 *createLine1ByCoords(int x1, int y1, int x2, int y2);
void deleteLine1(Line1 *l1);

void printLine1(Line1 *l1);
Line1 *copyLine1(Line1 *l1);
int isEqualLine1(Line1 *ll1, Line1 *rl1);

double lenghtLine1(Line1 *l1);
/////////////////////////////////////////////////////////////////////////////
typedef struct tag_line2 {
	Point *B;
	Point *C;
} Line2;

Line2 *createLine2ByPoints(Point *p2, Point *p3);
Line2 *createLine2ByCoords(int x2, int y2, int x3, int y3);
void deleteLine2(Line2 *l2);

void printLine2(Line2 *l2);
Line2 *copyLine2(Line2 *l2);
int isEqualLine2(Line2 *ll2, Line2 *rl2);

double lenghtLine2(Line2 *l2);

///////////////////////////////////////////////////////////////////////////
typedef struct tag_line3 {
	Point *C;
	Point *A;
} Line3;

Line3 *createLine3ByPoints(Point *p3, Point *p1);
Line3 *createLine3ByCoords(int x3, int y3, int x1, int y1);
void deleteLine3(Line3 *l3);

void printLine3(Line3 *l3);
Line3 *copyLine3(Line3 *l3);
int isEqualLine3(Line3 *ll3, Line3 *rl3);

int lenghtLine3(Line3 *l3);

#endif
