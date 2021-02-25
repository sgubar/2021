#include "Figures.h"

figures* make_many_squares(int p_size)
{
	figures* sq_arr = (figures*)malloc(sizeof(figures));
	if (sq_arr != NULL)
	{
		sq_arr->size = (p_size > 0) ? p_size : 1;
		sq_arr->squares = (Square**)calloc(sq_arr->size ,sizeof(Square*) * sq_arr->size);
	}
	return sq_arr;
}