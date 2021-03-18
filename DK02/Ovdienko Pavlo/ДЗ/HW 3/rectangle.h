#include "point.h"

#define RECTANGLE_H
#ifdef RECTANGLE_H


typedef struct {

	Point* A;
	Point* B;
	Point* C;
	Point* D;

} Rectangle;

Rectangle* createRectangleByCoords(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void deleteRectangle(Rectangle* rec);
void printRectangle(Rectangle* rec);
double perimeterRectangle(Rectangle* rec);
double squareRectangle(Rectangle* rec);
int isEqualRectangle(Rectangle* srec, Rectangle* svrec);
int CheckRectangle(Rectangle* rec);

#endif