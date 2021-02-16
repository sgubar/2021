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
	
	float h = ((float)(A*B)/(float)(B+pw(C, 2)))+sum(0, B);
	return h; 
}
