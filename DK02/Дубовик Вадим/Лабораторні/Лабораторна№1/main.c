#include <stdio.h>
#include "math.h"

int main(int argc, const char* argv[])
{
	
	int A, B, C;
	printf("Dobrogo dnya, vy koristuetes programou\ndly rozrahunku formuly #5\n");
	printf("Bud lasksa, vvedit chislo A,B,C:\n");
    if (scanf_s("%d", &A) && scanf_s("%d", &B) && scanf_s("%d", &C))
    {
		printf("%f", Q_is(A, B, C));
    }
    else {
        printf("Error: Vi vveli nepravilni simvoli\n");        
    }
	
}

