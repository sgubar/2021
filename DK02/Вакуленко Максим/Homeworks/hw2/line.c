#include"line.h"
#include <stdlib.h>
#include <math.h>
Line* createLineByPoints(PtCord* p1, PtCord* p2) {
	if (NULL == p1 || NULL == p2) {
		return NULL;
	}
	Line* l = (Line*)malloc(sizeof(Line));
	if (NULL != l) {
		l->A = p1;
		l->B = p2;
	}
	return l;
}

void deledeLine(Line* l) {
	if (NULL != l) {
		deletePoint(l->A);
		deletePoint(l->B);
	}
//	free(l);
}

void printLine(Line* l) {
	if(NULL != l) {
		printPoint(l->A);
		printf("-");
		printPoint(l->B);
		printf("\n");
	}
}

Line* copyLine(Line* l) {
	if (NULL == l) {
		return NULL;
	}

	return createLineByPoints(l->A, l->B);
}

int isEqualLine(Line* ll, Line* rl) {
	if (NULL == ll || NULL == rl) {
		return 0;
	}
	return (isEqualPoints(ll->A, rl->A) && isEqualPoints(ll->B, rl->B)) ? 1 : 0;
}

double lenghtLine(Line* l) {
	if (NULL == l) {
		return -1;
	}

	long dX = l->A->x - l->B->x;
	long dY = l->A->y - l->B->y;

	return sqrt(dX * dX + dY * dY);
}
