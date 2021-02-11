#include "Hed.h"


int summa_factorials(int num_b) {
	int res = 0;
	for (int i = 0; i <= num_b; i++) {
		res += factorial(i);
	}
	return res;
}


double power(int base, int pow) {

	double result = 1;
	int i;

	if (pow < 0) {
	
		for ( i = 0; i < pow*-1; i++) {
			result *= base;
		}
		result = 1 / result;
	}

	else if (pow == 0) {
		return 1;

	}
	else
		for (i = 0; i < pow; i++) {
		result *= base;
	}

	return result;
}




long factorial(int number){
	long result = 1;

	if (number < 0) {
		return -1;
	}

	for (int i = 1; i <= number; i++) {
		result *= i;
	}

	return result;
}

double q(int A, int B, int C) { 
	if (B + power(C, 2) == 0 ) {
		return -1;
	}
	else
	return  (A*B)/ (B + power(C, 2)) + summa_factorials(B);
}