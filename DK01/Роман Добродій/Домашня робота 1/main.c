#include<stdio.h>
#include"dk_tool.h"
int main() {
	int** matr1 = create_matrix(1, 5);
	put_rand_arr(matr1, 1, 5);
	out_matr(matr1, 1, 5);
	int** matr2 = transpMatrix(matr1, 1, 5);
	printf("\n");
	out_matr(matr2, 5, 1);
}
