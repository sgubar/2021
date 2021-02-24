#include "math.h"
float power(float base){
	
	float z = 0;
	while(z*z < base){	
		z += 0.01;
	}
				
	return z - 0.01;
}

int factor(int number){
	int result = 1;
	
	if(number < 0){		
		return -1;
	}
	int i;
	for(i = 1; i <= number; i++){
		result *= i;
	}
	return result;
}

int sum_factor(int finish, int zmin){
	int result = 0;
	int i;
	for(i = 0; i <= finish; i++){
		result = result + factor(zmin + i);
	}

	return result;
}

	float Q(int A, int B, int C){
	
		return (A * ((power(B+C))/B)) + sum_factor(C, A);
	}

