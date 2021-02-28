#include "line.h"
#include <stdlib.h>
#include <math.h>
Line *createLineByPoints(Point *p1, Point *p2, Point *p3, Point *p4)
{
  if (NULL == p1 || NULL == p2)
    {
		return NULL;
	}

	Line *l = (Line *)malloc(sizeof(Line));
	if (NULL != l) {
		l->A = copyPoint(p1);
		l->B = copyPoint(p2);
		l->C = copyPoint(p3);
		l->D = copyPoint(p4);
	}

	return l;
}

void deleteLine(Line *l)
{
    if (NULL != l)
    {
		deletePoint(l->A);
		deletePoint(l->B);
		free(l);
	}
}

void printLine(Line *l)
{
  if (NULL != l)
    {
		printPoint(l->A);
		printf("-");
		printPoint(l->B);
		printf("-");
		printPoint(l->C);
		printf("-");
		printPoint(l->D);
		printf("\n");
	}
}


double lenghtLine(Line *l)
{
	if (NULL == l)
    {
		return -1;
	}

	long dX = l->A->x - l->B->x;
	long dY = l->A->y - l->B->y;

	return sqrt(dX*dX + dY*dY);
}


