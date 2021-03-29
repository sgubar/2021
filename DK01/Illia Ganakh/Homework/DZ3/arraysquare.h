#ifndef arraysquare
#define arraysquare

#include <stdio.h>
#include "square.h"

#define ArraySquareIndexError (-1)

typedef struct tag_ArraySquare {
	Square **storage;
	int count;
} ArraySquare;

ArraySquare *createArraySquare(long preservedCount);

void deleteArraySquare(ArraySquare *a);
long reallocateInternalStorage(ArraySquare *a, int requestedCount);

int setSquareAtIndex(ArraySquare *a, Square *value, int index);
Square *getSquareAtIndex(ArraySquare *a, int index);

void printArraySquaresAreas(ArraySquare *a);
int countArraySquare(ArraySquare *a);

#endif 