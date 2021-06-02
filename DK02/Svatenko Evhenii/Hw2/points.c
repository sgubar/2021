#include "points.h"

point* makePoint(int x, int y) {
	point* p = (point*)malloc(sizeof(point));
	if (NULL != p) {
		p->x = x;
		p->y = y;
	}

	return p;
}

void deletePoint(point* point) {
	if (NULL != point) {
		free(point);
	}
}

point* copyPoint(point* point) {
	if (NULL == point) {
		return NULL;
	}

	return makePoint(point->x, point->y);
}

void printPoint(point* point) {
	if (NULL == point) {
		return;
	}

	printf("(%d, %d)", point->x, point->y);
}
