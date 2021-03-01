#pragma once
#include "point.h"

#define linesPriam_H
#ifdef linesPriam_H


typedef struct {

	Point* one;
	Point* two;
	Point* three;
	Point* four;

} Priam;

Priam* createPriamByCoordinates(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void deleteRPriam(Priam* rect);
void printPriam(Priam* rect);
double ploshaPriam(Priam* rect);
int isEqualPriam(Priam* lrect, Priam* rrect);

#endif