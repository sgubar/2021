#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define Q_TRAPREZOID_ANGLES 4

struct Point
{
	double X;
	double Y;
};

struct Shape
{
	struct Point* Coodrinats;
};

struct Point difference(const struct Point lh, const struct Point rh)
{
	struct Point difPoint;
	difPoint.X = lh.X - rh.X;
	difPoint.Y = lh.Y - rh.Y;
	return difPoint;
}

double cross(const struct Point lh, const struct Point rh)
{
	return lh.X * rh.Y - lh.Y * rh.X;
}

char isTrapezoid(const struct Point a, const struct Point b, const struct Point c, const struct Point d)
{
	const double s1 = cross(difference(a, b), difference(c, d));
	const double s2 = cross(difference(b, c), difference(a, d));
	
	return (!s1 || !s2);
}



struct Shape* InitTrapezoidShapeByCoordinats(
	double X_1, double Y_1,
	double X_2, double Y_2,
	double X_3, double Y_3,
	double X_4, double Y_4)
{
	struct Point a;
	a.X = X_1;
	a.Y = Y_1;

	struct Point b;
	b.X = X_2;
	b.Y = Y_2;

	struct Point c;
	c.X = X_3;
	c.Y = Y_3;

	struct Point d;
	d.X = X_4;
	d.Y = Y_4;

	if (!isTrapezoid(a, b, c, d))
	{
		return NULL;
	}
	else
	{
		struct Shape* newShape = (struct Shape*)malloc(sizeof(struct Shape));
		newShape->Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
		newShape->Coodrinats[0] = a;
		newShape->Coodrinats[1] = b;
		newShape->Coodrinats[2] = c;
		newShape->Coodrinats[3] = d;
		return newShape;
	}
}

struct Shape* InitTrapezoidShapeByPoints(
	struct Point* a,
	struct Point* b,
	struct Point* c,
	struct Point* d)
{
	if (!isTrapezoid(*a, *b, *c, *d))
	{
		return NULL;
	}
	else
	{
		struct Shape* newShape = (struct Shape*)malloc(sizeof(struct Shape));
		newShape->Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
		newShape->Coodrinats[0] = *a;
		newShape->Coodrinats[1] = *b;
		newShape->Coodrinats[2] = *c;
		newShape->Coodrinats[3] = *d;
		return newShape;
	}
}

struct Shape* InitTrapezoidShapeByPointsArray(struct Point* arr, int size)
{
	if (size != Q_TRAPREZOID_ANGLES)
	{
		return NULL;
	}
	else
	{
		if (!isTrapezoid(arr[0], arr[1], arr[2], arr[3]))
		{
			return NULL;
		}
		else
		{
			struct Shape* newShape = (struct Shape*)malloc(sizeof(struct Shape));
			newShape->Coodrinats = (struct Point*)malloc(size * sizeof(struct Point));
			for (int i = 0; i < size; i++)
			{
				newShape->Coodrinats[i].X = arr[i].X;
				newShape->Coodrinats[i].Y = arr[i].Y;
			}
			return newShape;
		}
	}
}

void DeInitShape(struct Shape* shape)
{
	if (shape != NULL)
	{
		free(shape->Coodrinats);
	}
}


void enterTrapezoidShape(struct Point* arr)
{
	char ch = 'A';
	for (int i = 0; i < Q_TRAPREZOID_ANGLES; i++, ch++)
	{
		struct Point temp;
		printf("Введіть координати точки %c:\n", ch);
		printf("X -> ");
		scanf_s("%lf", &temp.X);
		printf("Y -> ");
		scanf_s("%lf", &temp.Y);
		arr[i] = temp;
	}
}

void outputShapeParametrs(struct Shape* shape, int size)
{
	char ch = 'A';
	for (int i = 0; i < size; i++, ch++)
	{
		printf("Point %c --> (%f, %f)\n", ch, shape->Coodrinats[i].X, shape->Coodrinats[i].Y);
	}
}


void menu()
{
	int size = 0;
	struct Shape* headShapes = (struct Shape*)malloc(size * sizeof(struct Shape));

	while (1)
	{
		printf("Робота з масивом трапецій:\n");
		printf("1 - створити нову фігуру\n");
		printf("2 - видалити фігуру\n");
		printf("3 - переглянути всі фігури\n");
		printf("інше - завершити роботу програми\n");
		printf("Виберіть варіант: ");
		int choose;
		scanf_s("%d", &choose);
		if (choose == 1)
		{
			system("cls");
			printf("Створення нової трапеції: \n");

			struct Point* newPoints = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
			enterTrapezoidShape(newPoints);
			struct Shape* newShape = InitTrapezoidShapeByPointsArray(newPoints, Q_TRAPREZOID_ANGLES);

			if (newShape != NULL)
			{
				struct Shape* newShapes = (struct Shape*)malloc((size + 1) * sizeof(struct Shape));
				newShapes->Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
				for (size_t i = 0; i < size + 1; i++)
				{
					newShapes[i].Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
				}

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < Q_TRAPREZOID_ANGLES; j++)
					{
						newShapes[i].Coodrinats[j] = headShapes[i].Coodrinats[j];
					}
				}
				for (size_t i = 0; i < Q_TRAPREZOID_ANGLES; i++)
				{
					newShapes[size].Coodrinats[i].X = newShape->Coodrinats[i].X;
					newShapes[size].Coodrinats[i].Y = newShape->Coodrinats[i].Y;
				}
				for (size_t i = 0; i < size; i++)
				{
					DeInitShape(&headShapes[i]);
				}
				free(headShapes);
				size++;
				headShapes = newShapes;

				system("cls");
				printf("Фігуру було додано.\n");
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				printf("Фігура з такими координатами не є трапецією.\n");
				system("pause");
				system("cls");
			}
		}
		else if (choose == 2)
		{
			system("cls");
			if (size)
			{
				printf("Видалення трапеції: \n");
				printf("Введіть індекс фігури, що хочете видалити: ");
				int index;
				scanf_s("%d", &index);
				index--;
				if (index >= 0 && index < size)
				{
					struct Shape* newShapes = (struct Shape*)malloc((size - 1) * sizeof(struct Shape));
					for (size_t i = 0; i < size - 1; i++)
					{
						newShapes[i].Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
					}
					int k = 0;
					for (size_t i = 0; i < size; i++)
					{
						if (i != index)
						{
							for (int j = 0; j < Q_TRAPREZOID_ANGLES; j++)
							{
								newShapes[k].Coodrinats[j] = headShapes[i].Coodrinats[j];
							}
							k++;
						}
					}
					for (size_t i = 0; i < size; i++)
					{
						DeInitShape(&headShapes[i]);
					}
					free(headShapes);
					headShapes = newShapes;
					size--;

					system("cls");
					printf("Елемент за індексом %d було видалено\n", index);
				}
				else
				{
					system("cls");
					printf("Індекс не входить в діапазон массиву.\n");
				}
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				printf("Фігур немає.\n");
				system("pause");
				system("cls");
			}
		}
		else if (choose == 3)
		{
			if (size)
			{
				system("cls");
				printf("Усі фігури:\n");
				for (size_t i = 0; i < size; i++)
				{
					printf("Фігура номер %d\n", i + 1);
					outputShapeParametrs(&headShapes[i], Q_TRAPREZOID_ANGLES);
					printf("\n");
				}
				printf("\n");
			}
			else
			{
				system("cls");
				printf("Фігур немає.\n");
			}
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			for (size_t i = 0; i < size; i++)
			{
				DeInitShape(&headShapes[i]);
			}
			free(headShapes);
			printf("Роботу програми завершено.");
			exit(0);
		}
	}
}


int main()
{
	setlocale(0, "");
	menu();



	
	return 0;
}
