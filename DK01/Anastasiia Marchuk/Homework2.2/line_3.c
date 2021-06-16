#include "line.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *cPoint);
Point *creatPointWithCoordinate(int x, int y);

Line *createLine(Point *C, Point *A)
{
	Line *theResult = NULL;
	
	if (NULL != C && NULL != A)
	{
		theResult = (Line *)malloc(sizeof(Line));
		if (NULL != theResult)
		{
			theResult->C = copyPointWithPoint(C);
			theResult->A = copyPointWithPoint(A);
		}
	}
	
	return theResult;
}

Line *createLineWithCoordinate(int xC, int yC, int xA, int yA)
{
	Line *theResult = (Line *)malloc(sizeof(Line));
	
	if (NULL != theResult)
	{
		theResult->C = creatPointWithCoordinate(xC, yC);
		theResult->A = creatPointWithCoordinate(xA, yA);
	}
	
	return theResult;
}

void destroyLine(Line *cLine)
{
	if (NULL != cLine)
	{
		free(cLine->C);
		free(cLine->A);
	
		free(cLine);
	}
}

float lenghLine(Line *cLine)
{
	float theResult = 0.0;
	
	if (NULL != cLine)
	{
		float dX = (cLine->C->x - cLine->C->x);
		float dY = (cLine->C->y - cLine->C->y);
		theResult = sqrt(dX*dX + dY*dY);
	}
	
	return theResult;
}

void printLine(Line *cLine)
{
	if (NULL != cLine)
	{
		printf ("[Line]. C(%d,%d) - A(%d,%d)\n",
					cLine->C->x,cLine->C->y,
					cLine->A->x, cLine->A->y);
	}
}

Point *copyPointWithPoint(Point *cPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = cPoint->x;
		theResult->y = cPoint->y;
	}
	
	return theResult;
}

Point *creatPointWithCoordinate(int x, int y)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}
	
	return theResult;
}
