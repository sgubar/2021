#include "rectangle.h"

Rectangle* createRectangleByCoords(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Rectangle* rec = (Rectangle*)malloc(sizeof(Rectangle));
	if (NULL != rec) {
		rec->A = createPoint(x1, y1);
		rec->B = createPoint(x2, y2);
		rec->C = createPoint(x3, y3);
		rec->D = createPoint(x4, y4);
	}
	return rec;
}

void deleteRectangle(Rectangle* rec)
{
	if (NULL != rec) {
		deletePoint(rec->A);
		deletePoint(rec->B);
		deletePoint(rec->C);
		deletePoint(rec->D);
		free(rec);
	}
}

void printRectangle(Rectangle* rec) 
{
	if (NULL != rec) {
		printPoint(rec->A);
		printf(",");
		printPoint(rec->B);
		printf(",");
		printPoint(rec->C);
		printf(",");
		printPoint(rec->D);
		printf("\n");
	}
}

int isEqualRectangle(Rectangle* ll, Rectangle* rl)
{
	if (NULL == ll || NULL == rl)
	{
		return 0;
	}
	return (isEqualPoints(ll->A, rl->A) && isEqualPoints(ll->B, rl->B) && isEqualPoints(ll->C, rl->C) && isEqualPoints(ll->D, rl->D)) ? 1 : 0;
}


double perimeterRectangle(Rectangle* rec)
{
	if (NULL == rec) {
		return -1;
	}

	long dX0 = rec->A->x - rec->B->x;
	long dY0 = rec->A->y - rec->B->y;
	long dX1 = rec->B->x - rec->C->x;
	long dY1 = rec->B->y - rec->C->y;
	long dX2 = rec->B->x - rec->C->x;
	long dY2 = rec->B->y - rec->C->y;
	long dX3 = rec->B->x - rec->C->x;
	long dY3 = rec->B->y - rec->C->y;

	return (sqrt(dX0 * dX0 + dY0 * dY0) + sqrt(dX1 * dX1 + dY1 * dY1) + sqrt(dX2 * dX2 + dY2 * dY2) + sqrt(dX3 * dX3 + dY3 * dY3));
}

double squareRectangle(Rectangle* rec)
{
	if (NULL == rec) {
		return -1;
	}

	long dX0 = rec->A->x - rec->B->x;
	long dY0 = rec->A->y - rec->B->y;
	long dX1 = rec->B->x - rec->C->x;
	long dY1 = rec->B->y - rec->C->y;

	return (sqrt(dX0 * dX0 + dY0 * dY0) * sqrt(dX1 * dX1 + dY1 * dY1));
}