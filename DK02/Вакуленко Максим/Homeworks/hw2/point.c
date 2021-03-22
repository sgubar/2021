#include"point.h"
#include<stdlib.h>
PtCord* createPoint(int x, int y) {
	PtCord* point = (PtCord*)malloc(sizeof(PtCord));
	if (NULL != point) {
		point->x = x;
		point->y = y;
	}
	return point;
}

void deletePoint(PtCord* p) {
	if (NULL != p) {
		free(p);
	}
}

void printPoint(PtCord* p) {
	if (NULL == p) {
		printf("Error invalid point");
		return;
	}

	printf("(%d, %d)", p->x, p->y);
}

PtCord* copyPoint(PtCord* p) {
	if (NULL == p) {
		return NULL;
	}

	return createPoint(p->x, p->y);
}

int isEqualPoints(PtCord* lp, PtCord* rp) {
	if (NULL == lp || NULL == rp) {
		return 0;
	}
	return (lp == rp || (lp->x == rp->x && lp->y == rp->y)) ? 1 : 0;
}