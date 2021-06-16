#include "line.h"
#include <stdlib.h>
#include <math.h>

Line3 *createLine3ByPoints(Point *p3, Point *p1) {
	if (NULL == p3 || NULL == p1 ) {
		return NULL;
	}

	Line3 *l3 = (Line3 *)malloc(sizeof(Line3));
	if (NULL != l3) {
		l3->C = copyPoint(p3);
		l3->A = copyPoint(p1);
	}

	return l3;
}

Line3 *createLine3ByCoord(int x3, int y3, int x1, int y1) {
	Line3 *l3 = (Line3 *)malloc(sizeof(Line3));
	if (NULL != l3) {
		l3->C = createPoint(x3, y3);
		l3->A = createPoint(x1, y1);
	}

	return l3;
}

void deleteLine3(Line3 *l3) {
	if (NULL != l3) {
		deletePoint(l3->C);
		deletePoint(l3->A);
		free(l3);
	}
}

void printLine3(Line3 *l3) {
	if (NULL != l3) {
		printPoint(l3->C);
		printf("-");
		printPoint(l3->A);
		printf("\n");
	}
}

Line3 *copyLine3(Line3 *l3) {
	if (NULL == l3) {
		return NULL;
	}

	return createLine3ByPoints(l3->C, l3->A);
}

int isEqualLine3(Line3 *ll3, Line3 *rl3) {
	if (NULL == ll3 || NULL == rl3) {
		return 0;
	}

	return (isEqualPoints(ll3->C, rl3->C) && isEqualPoints(ll3->C, rl3->C)) ? 1 : 0;
}

int lenghtLine3(Line3 *l3) {
	if (NULL == l3) {
		return -1;
	}

	long dX = l3->C->x - l3->A->x;
	long dY = l3->C->y - l3->A->y;

	return sqrt(dX*dX + dY*dY);
}
