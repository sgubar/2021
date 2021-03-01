#include "linesPriam.h"
#include <stdlib.h>
#include <math.h>

Priam* createPriamByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Priam* rect = (Priam*)malloc(sizeof(Priam));
	if (NULL != rect) {
		rect->one = createPoint(x1, y1);
		rect->two = createPoint(x2, y2);
		rect->three = createPoint(x3, y3);
		rect->four = createPoint(x4, y4);
	}
	return rect;
}

void deletePriam(Priam* rect)
{
	if (NULL != rect) {
		deletePoint(rect->one);
		deletePoint(rect->two);
		deletePoint(rect->three);
		deletePoint(rect->four);
		free(rect);
	}
}

void printPriam(Priam* rect)
{
	if (NULL != rect) {
		printPoint(rect->one);
		printf(":---");

		printPoint(rect->two);
		printf("---:");
		printf("\n");

		printPoint(rect->three);
		printf(":___");

		printPoint(rect->four);
		printf("___:");
		printf("\n");
	}
}

double ploshaPriam(Priam* rect)
{
	if (NULL == rect) {
		return -1;
	}

	long dx1 = rect->one->x - rect->two->x;
	long dy1 = rect->one->y - rect->two->y;
	long dx2 =rect->two->x - rect->three->x;
	long dy2 = rect->two->y - rect->three->y;

	return (sqrt(dx1 * dx1 + dy1 * dy1) * sqrt(dx2 * dx2 + dy2 * dy2));
}


int isEqualPriam(Priam* pl, Priam* pr)
{
	if (NULL == pl || NULL == pr)
	{
		return 0;
	}
	return (isEqualPoints(pl->one, pr->one) && isEqualPoints(pl->two, pr->two) && isEqualPoints(pl->three, pr->three) && isEqualPoints(pl->four, pr->four)) ? 1 : 0;
}
