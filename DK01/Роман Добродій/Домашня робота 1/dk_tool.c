#include"dk_tool.h"
int** create_matrix(int row, int col)
{
	int** matrix = (int**)malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc(sizeof(int) * col);
	}

	return matrix;
}

void delete_matrix(int** matrix, int row) {
	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < row; i++) {
		free(*(matrix + i));
	}

	free(matrix);
}

void put_rand_arr(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(matrix + i) + j) = rand() % 10;
		}
	}
}

void out_matr(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}
int** transMatrix(int** matrix, int row, int col) {
	int** transp = create_matrix(col, row);
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			*(*(transp + j) + i) = *(*(matrix + i) + j);
		}
	}
	return transp;


}
