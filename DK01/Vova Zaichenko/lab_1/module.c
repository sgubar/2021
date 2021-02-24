#include "module.h"

int fact(int n)
{
	if(n < 0)
	{
		return -1;
	}
	else if(n == 0)
	{
		return 1;
	}

	return n * fact(n - 1);
}

double module(double t)
{
	if(t < 0)
	{
		return -t;
	}
	else if(t >= 0)
	{
		return t;
	}
}

double q(int a, double b)
{
	int fact_exp = fact(a);
	if(fact_exp == -1)
	{
		return -1;
	}

	return fact_exp / module(2 * a + b);
}
