#include <stdio.h>
#include <stdlib.h>
#include "math.h"


int main(int argc, char *argv[]) {
	int A, B, C;
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("C: ");
	scanf("%d", &C);
	if(B+pw(C, 2)!=0 && B >=0)
	{
		printf("%f", q(A,B,C));
	}
	else
	{
		printf("Your values are not acceptable");
		return 0;
	}


}
