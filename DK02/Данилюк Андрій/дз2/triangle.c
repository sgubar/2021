#include <stdio.h>
#include "triangle.h"
#include <stdlib.h>
#include <math.h>

Triangle* createTreangleByPoint(Point* p1, Point* p2, Point* p3) {
	if (isEqualPointOfTreangle(p1, p2, p3) == 0) {
		printf("Error, identical points\n");
		return 0;
	}
	Line* AB = createLineByPoints(p1, p2);
	Line* BC = createLineByPoints(p2, p3);
	Line* CA = createLineByPoints(p3, p1);
	if (TestTriangle(AB, BC, CA) == 0) {

		return 0;
	}
	Triangle* ABC = createTreangleByLine(AB, BC, CA);
	return ABC;
}

Triangle* createTreangleByLine(Line* l1, Line* l2, Line* l3) {
	if (NULL == l1 || NULL == l2 || NULL == l3) {
		return NULL;
	}
	Triangle* t = (Triangle*)malloc(sizeof(Triangle));
	if (NULL != t) {
		t->AB = copyLine(l1);
		t->BC = copyLine(l2);
		t->CA = copyLine(l3);
	}

	return t;
}
Triangle* copyTriangle(Triangle* t) {
	if (NULL == t) {
		return NULL;
	}
	Triangle* copy = createTreangleByLine(copyLine(t->AB), copyLine(t->BC), copyLine(t->CA));
	return copy;
}
int TestTriangle(Line* l1, Line* l2, Line* l3) {
	if (NULL == l1 || NULL == l2 || NULL == l3) {
		printf("ERROR, no values ​​entered\n");
		free(l1);
		free(l2);
		free(l3);
		return 0;
	}
	else if (lenghtLine(l1) + lenghtLine(l2) <= lenghtLine(l3) ||
		lenghtLine(l1) + lenghtLine(l3) <= lenghtLine(l2) ||
		lenghtLine(l3) + lenghtLine(l2) <= lenghtLine(l1)) {
		printf("ERROR, non-existent triangle\n");
		free(l1);
		free(l2);
		free(l3);
		return 0;
	}
	return 1;
}

int isEqualPointOfTreangle(Point* p1, Point* p2, Point* p3) {
	if (isEqualPoints(p1, p2) == 1 || isEqualPoints(p1, p3) == 1 || isEqualPoints(p3, p2)) {
		return 0;
	}
	return 1;
}

double PerimeterOfTriangle(Triangle* t) {
	if (t != NULL) {
		return (lenghtLine(t->AB) + lenghtLine(t->BC) + lenghtLine(t->CA));
	}
	return 0;
}
double SquareOfTriangle(Triangle* t) {
	if (t != NULL) {
		return sqrt((PerimeterOfTriangle(t) / 2) * ((PerimeterOfTriangle(t) / 2) - lenghtLine(t->AB)) *
			((PerimeterOfTriangle(t) / 2) - lenghtLine(t->BC)) *
			((PerimeterOfTriangle(t) / 2) - lenghtLine(t->CA)));
	}
	return 0;
}
void printTriangle(Triangle* t) {
	if (t == NULL) {
		return NULL;
	}
	printf("Line AB: ");
	printLine(t->AB);
	printf("lenght AB: %lf\n", lenghtLine(t->AB));

	printf("Line BC: ");
	printLine(t->BC);
	printf("lenght BC: %lf\n", lenghtLine(t->BC));

	printf("Line CA: ");
	printLine(t->CA);
	printf("lenght CA: %lf\n", lenghtLine(t->CA));

	printf("Perimetr ABC: %lf\n", PerimeterOfTriangle(t));
	printf("Square ABC: %lf\n", SquareOfTriangle(t));
}
void deleteTriangle(Triangle* t) {
	if (t != NULL) {
		deleteLine(t->AB);
		deleteLine(t->BC);
		deleteLine(t->CA);
	}
}
