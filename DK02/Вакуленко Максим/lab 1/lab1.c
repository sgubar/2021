#include<stdio.h>
#include"Hed.h"
int main() {
	int flag = 1;
	int A, B, C;
	do {

	printf("Type a A: ");
	scanf_s("%d", &A);
	if (A > 5000) {
		printf("Error_A. Num is very big \n");
		return 0;
	}

	printf("Type a B (only >= 0): ");
	scanf_s("%d", &B);
	if (B < 0 || B > 10) {
		printf("Error_B. Enum < 0 or num is very big \n");
		return 0;
	}

	printf("Type a C: ");
	scanf_s("%d", &C);
	if (C > 50) {
		printf("Error_C. Num is very big \n");
		return 0;
	}
	

	printf("\n");

    double Q = q(A, B, C);
	printf("%lf\n", Q);
	printf("Write 1 to start again: ");
	scanf_s("%d", &flag);
	} while (flag == 1);
	//printf("%lf\n", power(2, -2));
	return 0;
}