#include"dk_tool.h"

void get_numbers(int A, int B, int C)
{
	printf("Write a value of A: ");
	scanf("%i", A);
	printf("Write a value of B: ");
	scanf("%i", B);
	printf("Write a value of C: ");
	scanf("%i", C);
}

#define MOD(n) (n < 0 ? -n : n)

double power(int A) 
{

	double result = 1;
	int pw = MOD(A);
	for (int i = 0; i < pw; i++) {
		result *= 2;
	}

	if (A < 1)
	{
		printf("Number of values cant be less then 1");
		return 0;
	}
	result *= A;
	return result;
}

double first_part(int A, int B, int C)
{
	if (100 - B - C == 0)
	{
		printf("the denominator cannot be zero");
	}
	long result = (A + B + C) / (100 - B - C);
	return result;
}
