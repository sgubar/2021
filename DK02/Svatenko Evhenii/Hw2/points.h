#pragma once
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct tag_point {
	int x;
	int y;
} point;

point* makePoint(int x, int y);
void deletePoint(point* p);
void printPoint(point* p);
point* copyPoint(point* p);


#endif
