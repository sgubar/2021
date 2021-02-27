#include "dot.h"

#define square_h
#ifdef square_h

typedef struct
{
	Dot* A;
	Dot* B;
	Dot* C;
	Dot* D;
} Square;

Square* make_square(Dot* A, Dot* B, Dot* C, Dot* D);
void print_square(Square* square);
void draw_square(void);
int check_square(Square* square);
float long_line(Dot* A, Dot* B);
void count_square(Square* square);
void delete_square(Square* square);

#endif;
