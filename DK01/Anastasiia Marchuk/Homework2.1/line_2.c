#include "line.h"
#include <stdlib.h>
#include <math.h>

Line2 *createLineByPoints(Point *p2, Point *p3) {
	if (NULL == p2 || NULL == p3 ) {
		return NULL;
	}

	Line2 *l2 = (Line2 *)malloc(sizeof(Line2));
	if (NULL != l2) {
		l2->B = copyPoint(p2);
		l2->C = copyPoint(p3);
	}

	return l2;
}

Line2 *createLine2ByCoord(int x2, int y2, int x3, int y3) {
	Line2 *l2 = (Line2 *)malloc(sizeof(Line2));
	if (NULL != l2) {
		l2->B = createPoint(x2, y2);
		l2->C = createPoint(x3, y3);
	}

	return l2;
}

void deleteLine2(Line2 *l2) {
	if (NULL != l2) {
		deletePoint(l2->B);
		deletePoint(l2->C);
		free(l2);
	}
}

void printLine2(Line2 *l2) {
	if (NULL != l2) {
		printPoint(l2->B);
		printf("-");
		printPoint(l2->C);
		printf("\n");
	}
}

Line2 *copyLine2(Line2 *l2) {
	if (NULL == l2) {
		return NULL;
	}

	return createLine2ByPoints(l2->B, l2->C);
}

int isEqualLine2(Line2 *ll2, Line2 *rl2) {
	if (NULL == ll2 || NULL == rl2) {
		return 0;
	}

	return (isEqualPoints(ll2->B, rl2->B) && isEqualPoints(ll2->C, rl2->C)) ? 1 : 0;
}

double lenghtLine2(Line2 *l2) {
	if (NULL == l2) {
		return -1;
	}

	long dX = l2->B->x - l2->C->x;
	long dY = l2->B->y - l2->C->y;

	return sqrt(dX*dX + dY*dY);
}
