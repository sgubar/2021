#include "square.h"

#define Height 8
#define Weight 8


Square* make_square(Dot* A, Dot* B, Dot* C, Dot* D)
{
	Square* square = (Square*)malloc(sizeof(Square));
	square->A = A;
	square->B = B;
	square->C = C;
	square->D = D;
	return square;
}

void print_square(Square* square)
{
	printf("\nТочка A(%d; %d)", square->A->x, square->A->y);
	printf("\nТочка B(%d; %d)", square->B->x, square->B->y);
	printf("\nТочка C(%d; %d)", square->C->x, square->C->y);
	printf("\nТочка D(%d; %d)", square->D->x, square->D->y);
	draw_square();
	count_square(square);
}

void draw_square(void)
{
	printf("\n");
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Weight; j++)
		{
			if (i == 0 && j == 0)
			printf(" ");
			else
			if (i == Height - 1 && j == 0)
				printf(" ");
			else
			if (i == 0 || i == Height - 1)
				printf("--");
			else
			if ((j == 0) || (j == Height - 1))
				printf("|  ");
			else
				printf("  ");
		}
		printf("\n");
	}

}

int check_square(Square* square)
{
	if ((long_line(square->A, square->B) == long_line(square->A, square->D))&& (long_line(square->A, square->C) == long_line(square->B, square->D)))
		return 1;
	return 0;
}

float long_line(Dot* A, Dot* B)
{
	float long_line = (float)sqrt((double)(B->x - A->x) * (B->x - A->x) + (B->y - A->y) * (B->y - A->y));
	return long_line;
}

void count_square(Square* square)
{
	float a = long_line(square->A, square->B);
	float d = long_line(square->A, square->C);
	float S = a * a;
	printf("\nСторона: %f", a);
	printf("\nДиагональ: %f", d);
	printf("\nПлощадь: %f\n", S);
	//return S;
}

void delete_square(Square* square)
{
	if (square != NULL)
	{	
		delete_dot(square->A);
		delete_dot(square->B);
		delete_dot(square->C);
		delete_dot(square->D);
		free(square);
	}
}
