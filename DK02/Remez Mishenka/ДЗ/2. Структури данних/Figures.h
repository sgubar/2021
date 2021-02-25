#pragma once
#include "square.h"

#define figures_h
#ifdef figures_h

typedef struct {
	Square** squares;
	int size;
} figures;

figures* make_many_squares(int p_size);
void delete_figures(figures* squares);

#endif