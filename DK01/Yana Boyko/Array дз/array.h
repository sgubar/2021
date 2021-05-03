#ifndef array_h
#define array_h
#include <stdio.h>
#include "triangle.h"
//Array
typedef struct tagArray
{
    int maxCount;
    Tria **array;
} Array;

Array *createArray(int maxCount);

void deleteArray(Array *array);

void printArray(Array *array);

int append(Array *array, Tria* value);

int appendByIndex(Array *array, Tria* value, int index);


#endif
