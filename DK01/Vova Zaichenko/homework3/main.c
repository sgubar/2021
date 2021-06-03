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


struct Array
{
	struct Shape* m_pArr;
	int m_iSize;
};

struct Array* Array_Init_foo(const int N)
{
	if (N > 0)
	{
		struct Array* newArray = (struct Array*)malloc(sizeof(struct Array));
		newArray->m_iSize = N;
		newArray->m_pArr = (struct Shape*)malloc(newArray->m_iSize * sizeof(struct Shape));
		for (int i = 0; i < newArray->m_iSize; i++)
		{
			newArray->m_pArr[i].Coodrinats = (struct Point*)malloc(Q_TRAPREZOID_ANGLES * sizeof(struct Point));
		}
		return newArray;
	}
	else
	{
		return NULL;
	}
}

void Array_DeInit_foo(struct Array* otherArr)
{
	if (otherArr != NULL)
	{
		for (int i = 0; i < otherArr->m_iSize; i++)
		{
			free(otherArr->m_pArr[i].Coodrinats);
		}
		free(otherArr->m_pArr);
		free(otherArr);
		otherArr = NULL;
	}
}

int AddToArray(struct Array** otherArr, struct Shape* newShape)
{
	if (newShape != NULL)
	{
		struct Array* newArray = Array_Init_foo((*otherArr)->m_iSize + 1);
		for (int i = 0; i < (*otherArr)->m_iSize; i++)
		{
			for (int j = 0; j < Q_TRAPREZOID_ANGLES; j++)
			{
				newArray->m_pArr[i].Coodrinats[j] = (*otherArr)->m_pArr[i].Coodrinats[j];
			}
		}
		for (int j = 0; j < Q_TRAPREZOID_ANGLES; j++)
		{
			newArray->m_pArr[(*otherArr)->m_iSize].Coodrinats[j] = newShape->Coodrinats[j];
		}
		Array_DeInit_foo(*otherArr);
		(*otherArr) = newArray;
		return (*otherArr)->m_iSize - 1;
	}
	else
	{
		return -1;
	}
}

int ReplacementByIndex(struct Array* otherArr, struct Shape* newShape, const int index)
{
	if (otherArr!= NULL && otherArr->m_pArr != NULL && newShape != NULL && index >= 0 && index < otherArr->m_iSize)
	{
		for (size_t i = 0; i < Q_TRAPREZOID_ANGLES; i++)
		{
			otherArr->m_pArr[index].Coodrinats[i] = newShape->Coodrinats[i];
		}
		return (int)index;
	}
	else
	{
		return -1;
	}
}

void outputArray(struct Array* otherArr)
{
	for (int i = 0; i < otherArr->m_iSize; i++)
	{
		char ch = 'A';
		printf("Shape number %d:\n", i + 1);
		for (size_t j = 0; j < Q_TRAPREZOID_ANGLES; j++, ch++)
		{
			printf("Point %c --> (%f, %f)\n", ch, otherArr->m_pArr[i].Coodrinats[j].X, otherArr->m_pArr[i].Coodrinats[j].Y);
		}
		printf("\n");
	}
}

int main()
{
	system("chcp 1251 && cls");

	struct Array* arr = Array_Init_foo(3);
	for (int i = 0; i < arr->m_iSize; i++)
	{
		ReplacementByIndex(arr, InitTrapezoidShapeByCoordinats(1, 1 + i, 2, 3 + i, 5, 3 + i, 5, 1 + i), i);
	}
	outputArray(arr);

	AddToArray(&arr, InitTrapezoidShapeByCoordinats(1, 4, 2, 6, 5, 6, 5, 4));

	outputArray(arr);
	
	Array_DeInit_foo(arr);
	return 0;
}
