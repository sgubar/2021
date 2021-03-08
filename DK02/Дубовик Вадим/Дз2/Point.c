#include "point.h"

PPoint makePoint(int x, int y)
{
	PPoint Point = (PPoint)malloc(sizeof(Point));
	if (NULL != Point)
	{
		Point->x = x;
		Point->y = y;
	}
	return Point;
}

void deletePoint(PPoint p)
{
	if (NULL != p)
	{
		free(p);
	}
}

void printPoint(PPoint p)
{
	if (NULL != p)
	{
		printf("The point is: (%d;%d)", p->x, p->y);
	}
	return;
}

PPoint getPoint(void)
{
	int x=NULL, y=NULL;
	printf("Enter X:");
	scanf_s("%d", &x);
	printf("Enter Y:");
	scanf_s("%d", &y);
	if ((x == NULL) || (y == NULL))
	{
		return 0;
	}
	PPoint result = makePoint(x, y);
	return result;
}