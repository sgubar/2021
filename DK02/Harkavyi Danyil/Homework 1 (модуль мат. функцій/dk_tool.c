#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
int** make_matr(int row, int col) {
	int** matr1 = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		*(matr1 + i) = (int*)malloc(sizeof(int*) * col);
	}
	return matr1;
}
void put_random(int** matr1, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(matr1 + i) + j) = rand() % 10;
		}
	}
}
void vivod_matr(int** matr1, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %d", *(*(matr1 + i) + j));
		}
		printf("\n");
	}
}
 int** mno_matr(int** matr2, int** matr1, int row, int col) {
	 int** mnomatr = make_matr(row, col); 
		 for (int i = 0; i < row; i++) {
			 for (int j = 0; j < col; j++) {
				 *(*(mnomatr + i) + j) = 0;
				 for (int a = 0; a < row; a++) {
					 *(*(mnomatr + i) + j) += *(*(matr1 + i) + a) * *(*(matr2 + a) + j);
				 }
			 }
		 }
	 return mnomatr;
}
 



 void delete_matr(int** matr1, int row) {
	 if (matr1 == NULL) {
		 return 0;
	 }

	 for (int i = 0; i < row; i++) {
		 free(*(matr1 + i));
	 }

	 free(matr1);
 }


