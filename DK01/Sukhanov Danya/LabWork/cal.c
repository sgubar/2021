#include "cal.h"
#define MOD(n) (n < 0 ? -n : n)

double power(int base, int pow)
{
	double result = 1;
	int pw = MOD(pow);
	for (int i = 0; i < pow; i++)
	{
		result *=base;
	}
	return (pow < 0) ? 1.0 / result : result;
}
long mod(int A, int B, int C)
{
	int modulb = MOD(A * C - B);
	return modulb;
}
long sum(int start, int finish)
{
	long result=0;
    for (int i = start; i < finish; i++)
    {
        result += power (2 ,finish);
	}
}
float q(int A, int B, int C)
{
	return (mod(A, B, C)/power(C, 3))*sum(0, A);
}
