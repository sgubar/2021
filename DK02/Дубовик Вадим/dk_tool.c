#include "dk_tool.h"

int fill_Matrix(int** matrix, int row, int col)
{
	int matrVal=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf_s("%d", &matrVal);
			*(*(matrix + i) + j) = matrVal;
		}
	}

}



int** make_Matrix(int row, int col)
{
	int** matrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		*(matrix + i) = (int*)malloc(sizeof(int) * col);
	}
	return matrix;
}

void build_Matrix(int** matrix, int row, int col)
{
	for (int i=0; i < row; i++)
	{
		for (int j=0; j < col; j++)
		{
			printf("%d", *(*(matrix + i) + j));
			printf("\t");
		}
		printf("\n");
	}
}

int** tr_Matrix(int** matrix, int row, int col)
{
	int** transpMatrix = make_Matrix(col, row);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			*(*(transpMatrix + i) + j) = *(*(matrix + j) + i);
		}
	}
	return transpMatrix;
}

void delete_Matrix(int** matrix, int row)
{
	if (matrix == NULL)
	{
		return;
	}
	for (int i = 0; i < row; i++)
	{
		free(*(matrix)+i);
	}
	free(matrix);
}