#include "rectangle.h"

#define RECTANGLEARRAY_H
#ifdef RECTANGLEARRAY_H

#define maxnumbers 4

typedef struct {
	Rectangle* rectangles[maxnumbers];
} RectangleArray;

RectangleArray* createRectangleArray(void);
int countRectangles(RectangleArray* ris);
void addRectangleToRectangleArray(RectangleArray* ris, Rectangle* rec);
void printRectangleArray(RectangleArray* ris);
double FullPerimeterRectangleArray(RectangleArray* ris);
double FullSquareRectangleArray(RectangleArray* ris);
void deleteRectangleArray(RectangleArray* ris);



#endif
