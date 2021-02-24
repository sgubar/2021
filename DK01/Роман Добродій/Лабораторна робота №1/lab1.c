#include <stdio.h>
#include "math.h"

int main(int argc, const char* argv[])
{
	
	int A, B, C;
	printf("Введіть значення A,B,C:\n");
    if (scanf_s("%d", &A) && scanf_s("%d", &B) && scanf_s("%d", &C))
    {
		printf("%f", Q_ дорівнює (A, B, C));
    }
    else {
        printf("Error: Числа введені не вірно\n");        
    }
	
}
