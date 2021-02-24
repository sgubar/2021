#include <stdio.h>
#include "math.h"

int main(int argc, const char* argv[])
{

	int A, B, C;	
	printf("Please enter an integer number A:\n");
	scanf_s("%d", &A);	
	printf("Please, enter a number B >= 0:\n");
	scanf_s("%d", &B);
	if (B >= 0)
	{
		printf("Please, enter a number C:\n");
	}
	else {
		return printf("The number must be >= 0");
		 }
	scanf_s("%d", &C);
	if (A && B && C)
	{
		printf("Result:\n");
		printf("%f", Q_is(A, B, C));		
	}
	else {
		printf("Error: the numbers are entered incorrectly\n");
	}

}
