
#include <stdio.h>
#include "math.h"

int main(int argc, const char* argv[]) {
	int A, B, C;
	int vvod = 1;
	do {
		printf("A (You can write numbers only > 0  and < 10): ");
		scanf_s("%d", &A);
		if (A > 10 || A < 0) {
			printf("Error A \n");
			return 0;
		}
		
		printf("B (You can write numbers only > 0 and < 10): ");
		scanf_s("%d", &B);
		if (B > 10 || B < 0) {
			printf("Error B \n");
			return 0;
		}

		printf("C (You can write numbers only > 0 and < 10): ");
		scanf_s("%d", &C);
		if (C <= 0 || C > 10 ) {
			printf("Error С \n");
			return 0;
		}
		printf("%d \n", modyl(A, B, C));
		printf("The result of calculation: %lf\n", q(A, B, C));
		printf("For starting again print 1 or else number for end: ");
		scanf_s("%d", &vvod);
	} 
	while (vvod == 1);
	
	return 0;
}

