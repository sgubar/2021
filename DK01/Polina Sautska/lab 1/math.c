#include "math.h"
#define MOD(n) (n<0 ? -n:n)

	double power(int base, int pow){
		double result = 1;
		int pw = MOD(pow);

		for (int i = 0; i < pw; i++) {
			result *= base;
		}

		return (pow < 0) ? 1.0 / result : result;
	}

	long factorial(int base) {
		long result = 1;
		if (base < 0) {
			return -1;
		}
		for (int i = 1; i <= base; i++) {
			result *= i;
		}
		return result;
	}

    double q(int A, int B, int C) {
    int sigma = 0;
    for (int D = 0; D <= B; D++){
        sigma += factorial(D);
    }
    return A * B / (double)(B + power(C, 2)) + 1.0 * sigma;
}
