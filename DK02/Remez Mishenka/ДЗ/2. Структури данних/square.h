#pragma once
#include "dot.h"

#define square_h
#ifdef square_h

typedef struct
{
	Dot *A;
	Dot *B;
	Dot *C;
	Dot *D;	
} Square;

Square* make_square(Dot* a, Dot* b, Dot* c, Dot* d);
void delete_square(Square* square);
void draw_square(void);

#endif;
