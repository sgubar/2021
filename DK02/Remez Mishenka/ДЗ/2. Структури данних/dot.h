#pragma once
#include <stdio.h>

#define dot_h
#ifdef dot_h

typedef struct 
{
	int x;
	int y;
} Dot;

Dot* make_dot(int x, int y);
Dot* make_hollw_arr_dot(int size);
void delete_dot(Dot* point);

#endif