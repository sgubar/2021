#include "square.h"

#define Height 8
#define Weight 8


Square* make_square(Dot* a, Dot* b, Dot* c, Dot* d)
{
	Square* square= (Square*)malloc(sizeof(Square));
	square->A = a;
	square->B = b;
	square->C = c;
	square->D = d;
	return square;
}

void draw_square(void)
{
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

void delete_square(Square* square)
{
	if (square != NULL)
		free(square);
}
