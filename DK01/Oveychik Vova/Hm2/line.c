#include "line.h"
#include <stdlib.h>
#include <math.h>

Line *createLineByPoints(Point *p1, Point *p2) {
	if (NULL == p1 || NULL == p2) {
		return NULL;
	}

	Line *l = (Line *)malloc(sizeof(Line));
	if (NULL != l) {
		l->A = copyPoint(p1);
		l->B = copyPoint(p2);
	}

	return l;
}




void deleteLine(Line *l) {
	if (NULL != l) {
		deletePoint(l->A);
		deletePoint(l->B);
		free(l);
	}
}






double lenghtLine(Line *l) {
	if (NULL == l) {
		return -1;
	}

	long dX = l->A->x - l->B->x;
	long dY = l->A->y - l->B->y;

	return sqrt(dX*dX + dY*dY);
}
