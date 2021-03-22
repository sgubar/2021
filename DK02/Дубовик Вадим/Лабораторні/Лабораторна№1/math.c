#include "math.h"

#define MOD(n) (n<0 ? -n : n)

double power(int base, int pow)
{
	double result = 1;

	int pw = MOD(pow);
	for (int i = 0; i < pw; i++)
	{
		result *= base;
	}

	return ((pow < 0) ? 1.0 / result: result);

}

long sqrt(int a)

{
	long result = a;
	result *= a;
	return result;
}

long fctrl(int a)

{
	long result = 1;

	if (a < 0)
	{
		return -1;
	}

	for (int i = 1; i <= a; i++)
	{
		result *= i;
	}

	return result;
}

double Q_is(int A, int B, int C)

{
	double result = 0;
	result = ((sqrt(A) + sqrt(B)) /(double) (B + power(5, C))) + (double)fctrl(B);
	if ((double)(B + power(5, C) == 0))
	{
		printf("Vvedeni chisla ne pidhodyat oskilky znamennik ne mozhe dorivnuvaty 0");
		return 0;
	}
	if (B < 0))
	{
		printf("Vvedeni chisla ne pidhodyat oskilky ne isnue factoriala videmnih chisel");
		return 0;
	}
	return result;
}