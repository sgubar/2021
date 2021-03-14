#include "square.h"

#define figures_h
#ifdef figures_h

typedef struct {
	Square** square;
	int size;
} figures;

figures* make_many_squares(int p_size);
int set_square_by_index(figures* arr_s, Square* square, int index);
void reallocate_figures(figures* arr_s, int new_size);
Square* get_square_by_index(figures* arr_s, int index);
float count_s(figures* arr_s);
void print_arr_by_sq(figures* arr_s, int state);
void delete_figures(figures* squares);

#endif