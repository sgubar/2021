#include"math.h"

int main()
{
    int A,B,C;
    printf("You can use numbers only from 1 to 14.");
    printf("\nEnter A: ");
	scanf("%d", &A );
	if(A <= 0 || A >= 15)
    {
        printf("Sorry, but number A can be only from 1 to 14.");
        return 0;
    }
	printf("Enter B: ");
	scanf("%d", &B );
	if(B <= 0)
    {
        printf("Fatal Error(B can`t be <= 0)!!!");
        return 0;
    }
    if(B >= 15)
    {
        printf("Sorry, but number B can be only from 1 to 14.");
        return 0;
    }
	printf("Enter C: ");
	scanf("%d", &C );
	if(C <= 0 || C >= 15)
    {
        printf("Sorry, but number C can be only from 1 to 14.");
        return 0;
    }

	printf("The result of calculation:%f\n", Q(A, B, C));
	return 0;
}
