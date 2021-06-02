#include "triangle.h"

double lenght(point* p1, point* p2) {
	if (NULL == p1 || NULL == p2) {
		return -1;
	}

	long dX = p1->x - p2->x;
	long dY = p1->y - p2->y;

	return sqrt(dX * dX + dY * dY);
}

int IsTriangleRectangular(point* p1, point* p2, point* p3) {
	if (NULL == p1 && NULL == p2 && NULL == p3) {
		return NULL;
	}

	double a = lenght(p1, p2);
	double b = lenght(p2, p3);
	double c = lenght(p3, p1);
	double  gipo = 0;
	double kat1 = 0;
	double kat2 = 0;

	if (a > b) { gipo = a; }
	else { gipo = b; }
	if (gipo < c) { gipo = c; }

	if (a != gipo) {
		kat1 = a;
		if (b != gipo)
		{
			kat2 = b;
		}
		else { kat2 = c; }
	}
	else {
		kat1 = b;
		kat2 = c;
	}

	if (gipo * gipo == (kat1 * kat1) + (kat2 * kat2)) {

		return 1;

	}
	else {
		return 0;
	}



}






triangle* makeTriangleByPoints(point* p1, point* p2, point* p3) {
	if (NULL == p1 || NULL == p2 || NULL == p3) {
		return NULL;
	}


	if (IsTriangleRectangular(p1, p2, p3) == 0) {

		return NULL;
		printf("triangle is not rectangular");
	}


	triangle* tr = (triangle*)malloc(sizeof(triangle));
	if (NULL != tr) {
		tr->A = copyPoint(p1);
		tr->B = copyPoint(p2);
		tr->C = copyPoint(p3);

	}

	return tr;

}




double SquareOfTriangle(triangle* tr) {
	if (NULL == tr) {
		return 0;
	}
	if (IsTriangleRectangular(tr->A, tr->B, tr->C) == 0) {
		return 0;
	}

	double a = lenght(tr->A, tr->B);
	double b = lenght(tr->B, tr->C);
	double c = lenght(tr->C, tr->A);
	double  gipo = 0;
	double kat1 = 0;
	double kat2 = 0;

	if (a > b) { gipo = a; }
	else { gipo = b; }
	if (gipo < c) { gipo = c; }

	if (a != gipo)
	{
		kat1 = a;
		if (b != gipo)
		{
			kat2 = b;
		}
		else { kat2 = c; }
	}
	else {
		kat1 = b;
		kat2 = c;
	}

	double square = (kat1 * kat2) / 2;
	return square;
}


double PerimetrOfTriangle(triangle* tr) {
	if (IsTriangleRectangular(tr->A, tr->B, tr->C) == 0) {
		return 0;
	}
	double a = lenght(tr->A, tr->B);
	double b = lenght(tr->B, tr->C);
	double c = lenght(tr->C, tr->A);
	return a + b + c;
}



void deleteTriangle(triangle* tr)
{
	if (NULL != tr) {
		deletePoint(tr->A);
		deletePoint(tr->B);
		deletePoint(tr->C);

		free(tr);
	}
}

void printTriangle(triangle* tr) {
	if (NULL != tr) {
		printPoint(tr->A);
		printf("-");
		printPoint(tr->B);
		printf("-");
		printPoint(tr->C);
		printf("\n");
	}



}
