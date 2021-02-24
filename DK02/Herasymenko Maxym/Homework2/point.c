#include"point.h"
Point *createPoint(int x, int y)
{
 Point *point = (Point *)malloc(sizeof(Point));
	if (NULL != point)
    {
		point->x = x;
		point->y = y;
	}

	return point;
}

void deletePoint(Point *p)
{
  if (NULL != p)
    {
		free(p);
	}
}

void printPoint(Point *p)
{
    if (NULL == p)
    {
		return;
	}

	printf("(%d, %d)", p->x, p->y);
}

Point *copyPoint(Point *p)
{
  if (NULL == p)
    {
		return NULL;
	}

	return createPoint(p->x, p->y);
}

int isEqualPoints(Point *lp, Point *rp, Point *dp, Point *zp)
{
       if (NULL == lp || NULL == rp || NULL == dp || NULL == zp)
    {
		return 0;
	}

	return (lp == rp || lp == dp || lp == zp || rp == dp || rp == zp || dp == zp ||  (lp->x == rp->x && lp->y == rp->y && lp->x == dp->x && lp->y == dp->y && lp->x == zp->x && lp->y == zp->y && rp->x == dp->x && rp->y == dp->y && rp->x == zp->x && rp->y == zp->y&& dp->x == zp->x && dp->y == zp->y)) ? 1 : 0;
}
