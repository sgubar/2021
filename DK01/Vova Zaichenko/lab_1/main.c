#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "module.h"

int main(int argc, char *argv[])
{
	char buffA[100];
	char buffB[100];

	printf("Enter A: ");
	gets(buffA);
	int a = atoi(buffA);

	if(!a && strcmp(buffA, "0"))
	{
		printf("Error. Try again!\n");
		return -1;
	}

	printf("Enter B: ");
	gets(buffB);

	int b = atof(buffB);

	if(!b && strcmp(buffB, "0"))
	{
		printf("Error. Try again!\n");
		return -1;
	}

	double q_exp = q(a, b);
	if(q_exp == -1)
	{
		printf("Error. Try again!\n");
		return -1;
	}

	printf("Result is %f\n", q_exp);
}
