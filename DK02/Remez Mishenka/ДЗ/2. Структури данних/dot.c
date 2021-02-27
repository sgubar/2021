#include "dot.h"

Dot* make_dot(int x, int y)
{
	Dot* Velikolepno = (Dot*)malloc(sizeof(Dot));
	Velikolepno->x = x;
	Velikolepno->y = y;
	return Velikolepno;
}

//Dot* make_hollw_arr_dot(int size)
//{
//	Dot *Velikolepno = (Dot*)malloc(sizeof(Dot) * size);
//
//	for (int i = 0; i < size; i++)
//	{
//		(Velikolepno + i)->x = 0;
//		(Velikolepno + i)->y = 0;
//	}
//	return Velikolepno;
//}

Dot* input_dot(void)
{
	int x, y;
	printf("Введите параметры точки\nX:");
		scanf_s("%d", &x);
		printf("Y:");
		scanf_s("%d", &y);
		Dot* ara_ara = make_dot(x, y);
	return ara_ara;
}

void print_dot(Dot* point)
{
	printf("\nТочка (%d;%d)\n", point->x, point->y);
}

void delete_dot(Dot* point)
{
	if (point != NULL)
		free(point);
}
