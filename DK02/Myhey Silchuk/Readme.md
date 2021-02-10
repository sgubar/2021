#include "math.h"
#include <stdio.h>

long fact(int factbase)
{
	int result = 1;
	for(int i = 0; i < factbase; i++)
	{
		result = result*(1+i);
	}
	return result;
}


long sum(int st, int fin)
{	st = 0;
	int result = 0;
	for(int i = 0; i<= fin; i++)
	{	
		result = result + fact(st+i);
	}
	return result;
}

long pw(int base, int pow)
{
	int result = 1;
	for(int i =0; i < pow; i++)
	{
		result = result * base; 
	}
	return result; 
}

float q(int A, int B, int C)
{
	int a = A*B; 
	printf("%d\n", a);
	int b = (B+pw(C, 2));
	printf("%d\n", b);
	float c = (float)a/(float)b;
	printf("Run %f\n", c);
	float h = c + (float)sum(0, B);
	printf("%f\n", h);
	return h; 
}
