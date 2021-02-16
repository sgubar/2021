#include"math.h"
long factorial(int number)
{
	long result = 1;

	if(number < 0)
    {
		return -1;
	}
	for(int i = 1; i <= number; i++)
	{
		result *= i;
	}
	return result;
}

long sum_factor(int A, int C)
    {
	long result = 0;
	for(int i = 0; i <= C; i++)
    {
    result += factorial(A + i);
	}

	return result;
}

double Q(int A, int B, int C)
    {
     return (A * ((sqrt(B+C))/B)) + sum_factor(A, C);
	}
