
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "math.h"


int main(void) {
	int A, B, C;
	printf("Enter your numbers [0 < A, B, C <= 7]: \n");
	do{
	printf("Enter A: ");
	scanf("%d", &A );
	printf("Enter B: ");
	scanf("%d", &B );
	printf("Enter C: ");
	scanf("%d", &C );
	if((A <= 0) || (B <= 0) || (C <= 0) || (A >= 8) || (B >= 8) || (C >= 8)){
		printf("Enter the correct numbers [0 < A, B, C < 7]: \n");
	}
	}while((A <= 0) || (B <= 0) || (C <= 0) || (A >= 8) || (B >= 8) || (C >= 8));
	
	printf("The answer to the equation: %.2f\n", Q(A, B, C));
	return 0;
}
