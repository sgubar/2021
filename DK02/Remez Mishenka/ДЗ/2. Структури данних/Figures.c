#include "Figures.h"

figures* make_many_squares(int p_size)
{
	figures* sq_arr = (figures*)malloc(sizeof(figures));
	if (sq_arr != NULL)
	{
		sq_arr->size = (p_size > 0) ? p_size : 1;
		sq_arr->square = (Square**)calloc(sq_arr->size ,sizeof(Square*) * sq_arr->size);
	}
	return sq_arr;
}

void set_square_by_index(figures* arr_s, Square* square, int index)
{
	if (index < 0 || arr_s == NULL || square == NULL)
	{
		printf("\nError\n");
		return;
	}

	if (index >= arr_s->size)
		reallocate_figures(arr_s, index + 1);//перерозпределение
	arr_s->square[index] = square;
	return;
}

void reallocate_figures(figures* arr_s, int new_size)
{
	if (arr_s->size >= new_size)
		return;
	Square** buffer = (Square**)calloc(new_size, sizeof(Square*) * new_size);
	memcpy(buffer, arr_s->square, new_size);
	free(arr_s->square);
	arr_s->square = buffer;
	arr_s->size = new_size;
	return;
}

Square* get_square_dy_index(figures* arr_s, int index)
{
	if (NULL == arr_s || index < 0 || index >= arr_s->size) {
		return NULL;
	}
	return arr_s->square[index];
}

void delete_figures(figures* squares)
{
	if (NULL == squares)
	{
		return;
	}
	if (squares->square != NULL)
	{
		delete_square(squares->square);
	}
	free(squares);
}