#pragma once
#include<stdio.h> 

#define POINT_H
#ifdef POINT_H

// Прототип функции
typedef struct tag_point{
	int x;
	int y;
} PtCord;

PtCord* createPoint(int x, int y);
void deletePoint(PtCord* p);
void printPoint(PtCord* p);
PtCord* copyPoint(PtCord* p);
int isEqualPoints(PtCord* lp, PtCord* rp);

#endif /* point_h */ 