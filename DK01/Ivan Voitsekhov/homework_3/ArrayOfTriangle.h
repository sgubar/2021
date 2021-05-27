#ifndef ARRAYOFTRIANGLE_H_INCLUDED
#define ARRAYOFTRIANGLE_H_INCLUDED
#include <stdio.h>
#include "triangle.h"

#define ArrayLessThanZeroIndexError (-1)
#define ArrayNullPointerException (-2)
typedef struct tag_ArrayTriangle{
   Triangle **storage;
    long count;
} ArrayTriangle;

ArrayTriangle *createArrayTriangle(long preservedCount);
void deleteArrayTriangle(ArrayTriangle *a);

int TriangleAtIndex(ArrayTriangle *a, Triangle *value, int index);
Triangle *getTriangleAtIndexOrNull(ArrayTriangle *a, int index);

void printArrayTriangle(ArrayTriangle *a);
long countArrayTriangle(ArrayTriangle *a);
int addNewTriangleToArray(ArrayTriangle *a, Triangle *value);


#endif // ARRAYOFTRIANGLE_H_INCLUDED
