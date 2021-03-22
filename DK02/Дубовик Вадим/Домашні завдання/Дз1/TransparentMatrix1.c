#include <stdio.h>
#include "dk_tool.h"

int main()
{
	//Ввод размера матрицы
	printf_s("Enter the size of Matrix[row][collum]:\n ");
	int row, col;
	scanf_s("%d", &row);
	scanf_s("%d", &col);

	//Заполнение матрицы
	printf_s("Enter matrix values: \n");
	int** matrix = make_Matrix(row, col);
	fill_Matrix(matrix, row, col);

	//Вивод введёной матрицы
	printf_s("\n \n Your matrix looks like:\n");
	build_Matrix(matrix, row, col);
	
	//Транспонировка и вывод соответствуещей матрицы
	printf_s("\n \n Transparent matrix looks like:\n");
	int** transpMatrix = tr_Matrix(matrix, row, col);
	build_Matrix(transpMatrix, col, row);
	delete_Matrix(transpMatrix, row);
	delete_Matrix(matrix, row);
}