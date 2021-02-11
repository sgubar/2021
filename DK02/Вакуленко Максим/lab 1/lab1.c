#include<stdio.h>
#include"Hed.h"
int main() {
	int flag = 1;
	do {
	int A, B, C;
	printf("Type a A: ");
	scanf_s("%d", &A);

	printf("Type a B (only >= 0): ");
	scanf_s("%d", &B);
	if (B < 0) {
		printf("Fatal error enum < 0\n");
		return 0;
	}

	printf("Type a C: ");
	scanf_s("%d", &C);

	printf("\n");

    double Q = q(A, B, C);
	printf("%lf\n", Q);
	printf("Write 1 to start again: ");
	scanf_s("%d", &flag);
	} while (flag == 1);
	printf("%lf\n", power(2, -2));
	return 0;
}