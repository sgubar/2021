#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define POINT_H
#ifdef POINT_H

typedef struct {
	int x;
	int y;
} Point;

Point* createPoint(int x, int y);
void deletePoint(Point* p);
void printPoint(Point* p);
int isEqualPoints(Point* lp, Point* rp);


#endif
