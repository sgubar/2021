#include "line.h"

PLine makeLine(PPoint p1, PPoint p2)
{
	if (p1 != NULL && p2 != NULL)
	{
		PLine l = (PLine)malloc(sizeof(PLine));
		if (l != NULL)
		{
			l->A = p1;
			l->B = p2;
		}
		return l;
	}
	return NULL;
}
void printLine(PLine l)
{
	if (l == NULL)
	{
		return;
	}
	printf("The line:");
	printPoint(l->A);
	printf("-");
	printPoint(l->B);
	printf("\nIt's length is: %d", lenghtLine(l));

}
double lenghtLine(PLine l)
{
	if (l == NULL)
	{
		return -1;
	}
	
	double dX = l->A->x - l->B->x;
	double dY = l->A->y - l->B->y;

	return sqrt(dX * dX + dY * dY);
}
void deleteLine(PLine l)
{
	if (NULL != l)
	{
		deletePoint(l->A);
		deletePoint(l->B);
		free(l);
	}
}