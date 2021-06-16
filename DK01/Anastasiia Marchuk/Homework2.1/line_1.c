#include "line.h"
#include <stdlib.h>
#include <math.h>


Line1 *createLine1ByPoints(Point *p1, Point *p2) {
	if (NULL == p1 || NULL == p2 ) {
		return NULL;
	}

	Line1 *l1 = (Line1 *)malloc(sizeof(Line1));
	if (NULL != l1) {
		l1->A = copyPoint(p1);
		l1->B = copyPoint(p2);
	}

	return l1;
}


Line1 *createLine1ByCoord(int x1, int y1, int x2, int y2) {
	Line1 *l1 = (Line1 *)malloc(sizeof(Line1));
	if (NULL != l1) {
		l1->A = createPoint(x1, y1);
		l1->B = createPoint(x2, y2);
	}

	return l1;
}

void deleteLine1(Line1 *l1) {
	if (NULL != l1) {
		deletePoint(l1->A);
		deletePoint(l1->B);
		free(l1);
	}
}

void printLine1(Line1 *l1) {
	if (NULL != l1) {
		printPoint(l1->A);
		printf("-");
		printPoint(l1->B);
		printf("\n");
	}
}

Line1 *copyLine1(Line1 *l1) {
	if (NULL == l1) {
		return NULL;
	}

	return createLine1ByPoints(l1->A, l1->B);
}

int isEqualLine1(Line1 *ll1, Line1 *rl1) {
	if (NULL == ll1 || NULL == rl1) {
		return 0;
	}

	return (isEqualPoints(ll1->A, rl1->A) && isEqualPoints(ll1->B, rl1->B)) ? 1 : 0;
}

double lenghtLine1(Line1 *l1) {
	if (NULL == l1) {
		return -1;
	}

	long dX = l1->A->x - l1->B->x;
	long dY = l1->A->y - l1->B->y;

	return sqrt(dX*dX + dY*dY);
}
