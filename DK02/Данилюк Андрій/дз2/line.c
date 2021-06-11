#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "line.h"
Line* createLineByPoints(Point* p1, Point* p2) {
	if (NULL == p1 || NULL == p2) {
		return NULL;
	}
	Line* l = (Line*)malloc(sizeof(Line));
	if (NULL != l) {
		l->A = copyPoint(p1);
		l->B = copyPoint(p2);
	}
	return l;
}
void deleteLine(Line* l) {
	if (NULL != l) {
		deletePoint(l->A);
		deletePoint(l->B);
		free(l);
	}
}
void printLine(Line* l) {
	if (NULL != l) {
		printPoint(l->A);
		printf("-");
		printPoint(l->B);
		printf("\n");
	}
}
Line* copyLine(Line* l) {
	if (NULL == l) {
		return 0;
	}
	return createLineByPoints(l->A, l->B);
}
int isEqualLine(Line* ll, Line* rl) {
	if (NULL == ll || NULL == rl) {
		return 0;
	}
	return(isEqualPoints(ll->A, rl->A) && isEqualPoints(ll->B, rl->B)) ? 1 :0;
}
double lenghtLine(Line* l) {
	if (NULL == l) {
		return -1;
	}
	long dx = l->A->x - l->B->x;
	long dy = l->A->y - l->B->y;
	return sqrt((dx*dx) + (dy*dy));
}
