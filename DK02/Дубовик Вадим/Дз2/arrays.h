#include "circle.h"

#define ARRAYS_H
#ifdef ARRAYS_H

typedef struct 
{
	PCircle c;
	int amount;
} Array, * PArray;

PArray makeArray(int amount1);
void setCircleAtIndex(PArray s1, PCircle c1, int index);
PCircle getCircleAtIndex(PArray s1, int index);
void deleteArray(PArray s1);
void printArrayCircles(PArray a);

#endif