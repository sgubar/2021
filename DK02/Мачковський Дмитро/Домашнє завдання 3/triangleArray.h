#ifndef triangleArray
#define triangleArray

#include <stdio.h>
#include <stdio.h>
#include "triangle.h"
#include "line.h"
#include "point.h"

#define TriangleArrayError (-1)

typedef struct tag_triangleArray {
	Triangle** storage;
	int count;

}TriangleArray;

long reallocateInternalStorage(TriangleArray* ts, int requestedCount);
TriangleArray* createTriangleArray(int preservedCount);
Triangle* getTriangleAtIndex(TriangleArray* ts, int index);
int setTriangleAtIndex(TriangleArray* ts, Triangle* value, int index);
int countTriangles(TriangleArray* ts);
void addTriangleToTriangleArray(TriangleArray* ts, Triangle* value);
void printTriangleArray(TriangleArray* ts);
void deleteTriangleArreay(TriangleArray* ts);

#endif
