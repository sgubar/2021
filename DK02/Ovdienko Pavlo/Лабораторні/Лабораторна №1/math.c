#include "math.h"



long power(int number, int pow)
{
	int i;
	long result = 1;
	if (pow > 0) {
		for (i = 0; i < pow; i++)
		{
			result *= number;
		}
	}
	else {
		for (i = 0; i < pow * (-1); i++)
		{
		result *= number;
	    }
	    result = 1 / result;
	}
	return result;
}

long sum(int kinez)
{
		long result = 0;

		for (int i = 0; i <= kinez; i++)
		{
			result += power(2, (i + kinez));
		}
		return result;
}