#include "dot.h"

Dot* make_dot(int x, int y)
{
	Dot* Velikolepno = (Dot*)malloc(sizeof(Dot));
	Velikolepno->x = x;
	Velikolepno->y = y;
	return Velikolepno;
}

Dot* make_hollw_arr_dot(int size)
{
	Dot *Velikolepno = (Dot*)malloc(sizeof(Dot) * size);

	for (int i = 0; i < size; i++)
	{
		(Velikolepno + i)->x = 0;
		(Velikolepno + i)->y = 0;
	}
	return Velikolepno;
}

void delete_dot(Dot* point)
{
	if (point != NULL)
		free(point);
}
