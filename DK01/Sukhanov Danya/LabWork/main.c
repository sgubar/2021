#include <stdio.h>
#include <stdlib.h>
#include "cal.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    int A, B, C;
    
        printf("Enter A(please enter a number between 0 and 32767):");
        scanf("%d", &A);
        if (A<0 || A>32767)
        {
        	printf("Please read carefuly");
        	return 0;
		}
        	
        printf("A= %d\n",A);
        
        printf("Enter B(please enter a number between 0 and 32767):");
        scanf("%d", &B);
        if (B<0 || B>32767)
        {
        	printf("Please read carefuly");
        	return 0;
		}
        	
        printf("B= %d\n",B);
			
        printf("Enter C(please enter a number between 0 and 32767):");
        scanf("%d", &C);
        if (C<0 || C>32767)
        {
        	printf("Please read carefuly");
        	return 0;
		}
        	
        printf("C= %d\n",C);
			
		printf("Answer: %f\n", q(A, B, C));	
    
    
}

