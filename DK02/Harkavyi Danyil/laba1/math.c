#include "math.h"
#include <stdio.h>
#define MOD(n) (n < 0 ? -n : n)

double power(int number, int step) {
	double result = 1;
	int pow = MOD(step);
	for (int i = 0; i < pow; i++) {
		result *= number;
	}
	return (pow < 0) ? 1.0 / result : result;
}

long modyl(int A, int B, int C) {
	int result_modyl = MOD (A * C - B);
	return result_modyl;
}

long sum_power2(int finish) {
	long result = 0;
	for (int i = 0; i <= finish; i++) {
		result += power(2, i);
	}

	return result;
}


	double q(int A, int B, int C) {
		return (modyl(A, B, C) / (double)power(C, 3)) * sum_power2(A); //NOT FINISHED
	}