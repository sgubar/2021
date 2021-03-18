#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define dot_h
#ifdef dot_h

typedef struct 
{
	int x;
	int y;
} Dot;

Dot* make_dot(int x, int y);
Dot* input_dot(void);
void print_dot(Dot* point);
void delete_dot(Dot* point);

#endif