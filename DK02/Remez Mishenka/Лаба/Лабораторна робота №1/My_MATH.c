#include "My_MATH.h"

#define MOD(n) (n < 0 ? -n : n)

int stepen(int Ch, int pow)
{
	int buffer = 1;
	for (short i = 0; i < MOD(pow); i++)
		buffer *= Ch;
	return buffer;
}

int factorio(int Ch)
{
	int res = 1;
	for (short i = 0; i < Ch; Ch--)
	{
		res *= Ch;		
	}
	return res;
}

double formula(int A, int B, int C)
{
	return ((stepen(A, 2) + stepen(B, 2)) / (double)(B + stepen(5, C)) + factorio(B));
}
