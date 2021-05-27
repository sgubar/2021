#include "points.h"
#include <stdlib.h>

Point *createPoint(int x, int y) {
	Point *point = (Point *)malloc(sizeof(Point));
	if (NULL != point) {
		point->x = x;
		point->y = y;
	}

	return point;
}

void deletePoint(Point *p) {
	if (NULL != p) {
		free(p);
	}
}

Point *copyPoint(Point *p) {
	if (NULL == p) {
		return NULL;
	}

	return createPoint(p->x, p->y);
}

void printPoint(Point *p) {
	if (NULL == p) {
		return;
	}

	printf("(%d, %d)", p->x, p->y);
}
