#include "line.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *bPoint);
Point *creatPointWithCoordinate(int x, int y);

Line *createLine(Point *B, Point *C)
{
	Line *theResult = NULL;
	
	if (NULL != B && NULL != C)
	{
		theResult = (Line *)malloc(sizeof(Line));
		if (NULL != theResult)
		{
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}
	
	return theResult;
}

Line *createLineWithCoordinate(int xB, int yB, int xC, int yC)
{
	Line *theResult = (Line *)malloc(sizeof(Line));
	
	if (NULL != theResult)
	{
		theResult->B = creatPointWithCoordinate(xB, yB);
		theResult->C = creatPointWithCoordinate(xC, yC);
	}
	
	return theResult;
}

void destroyLine(Line *bLine)
{
	if (NULL != bLine)
	{
		free(bLine->B);
		free(bLine->C);
	
		free(bLine);
	}
}

float lenghLine(Line *bLine)
{
	float theResult = 0.0;
	
	if (NULL != bLine)
	{
		float dX = (bLine->B->x - bLine->C->x);
		float dY = (bLine->B->y - bLine->C->y);
		theResult = sqrt(dX*dX + dY*dY);
	}
	
	return theResult;
}

void printLine(Line *bLine)
{
	if (NULL != bLine)
	{
		printf ("[Line]. B(%d,%d) - C(%d,%d)\n",
					bLine->B->x,bLine->B->y,
					bLine->C->x, bLine->C->y);
	}
}

Point *copyPointWithPoint(Point *bPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = bPoint->x;
		theResult->y = bPoint->y;
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
