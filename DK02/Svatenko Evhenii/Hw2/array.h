#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include "triangle.h"
#include <string.h>

typedef struct tag_ArrayTriangle {
    triangle** storage;
    long count;
} arrayTriangle;

arrayTriangle* makeArray(long preservedCount);
void deleteArray(arrayTriangle* a);

int putTriangleAtIndex(arrayTriangle* a, triangle* value, int index);

void printArray(arrayTriangle* a);
long countArray(arrayTriangle* a);
int addTriangleToArray(arrayTriangle* a, triangle* value);


#endif
