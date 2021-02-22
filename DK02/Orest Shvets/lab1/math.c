
#include"math.h"
#define MOD(n) (n < 0 ? -n : n)




double power(int base, int pow) {

	double result = 1;
	int pw = MOD(pow);
	for (int i = 0; i < pw; i ++) {
		result *= base;
	}

	return (pow < 0) ? 1.0 / result : result;
}



float Q(int A, int B, int C)
{
    return (A+B+C)/(100-B-C)+(power(2, A));
}
