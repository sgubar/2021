#include <stdio.h>
#include "math.h"

int main(int argc, const char* argv[])
{

	int A, B, C;	
	printf("A:\n");
	scanf_s("%d", &A);
	printf("B:\n");
	scanf_s("%d", &B);
	printf("C:\n");
	scanf_s("%d", &C);
	if (A && B && C)
	{
		printf("%f", Q_is(A, B, C));
	}
	else {
		printf("Error: the numbers are entered incorrectly\n");
	}

}
