#include <stdlib.h>
#include <stdio.h>
void suma(int N, int A[][N], int B[][N], int RESULT[][N]){
	int i=0;
	while (i<N){
		int j=0;
		while (j<N){
			RESULT[i][j] = A[i][j] + B[i][j];
			j++;
		}
		i++;
	}
}
