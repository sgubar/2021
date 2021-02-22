#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "dk_tool.h"

#define n 4

void array(int N, int array[][N]){
	int i=0;
	while (i<N){
		int j=0;
		while (j<N){
			array[i][j] = rand() % (21) - 10;
			j++;
		}
		i++;
	}
}

void print_array(int N, int array[][N]){
	int i=0;
	while (i<N){
		int j=0;
		while (j<N){
			printf("%5d ", array[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	int A[n][n];
	int B[n][n];
	int RESULT[n][n];
	
	array(n, A);
	array(n, B);
	suma(n, A, B, RESULT);
	
	printf("Матрица А:\n");
	print_array(n, A);
	printf("\nМатрица B:\n");
	print_array(n, B);
	printf("\nСумма:\n");
	print_array(n, RESULT);
	return 0;
}
