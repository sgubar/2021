#include "rectangle.h"

#define RECTANGLEARRAY_H
#ifdef RECTANGLEARRAY_H

#define IndexError (-192);

typedef struct {
	Rectangle** storage;
	int countz;
} RectangleArray;

RectangleArray* createRectangleArray(long countOfArray);
void addRectangleToRectangleArray(RectangleArray* ris, Rectangle* rec);
int setRectangleAtIndex(RectangleArray* array, Rectangle* value, int index);
Rectangle* getRectangleAtIndex(RectangleArray* array, int index);
void printRectangleArray(RectangleArray* array);
void deleteRectangleArray(RectangleArray* array);
long reallocateInternalStorage(RectangleArray* array, int requestedCount);
long countOfRectangles(RectangleArray* array);


#endif
