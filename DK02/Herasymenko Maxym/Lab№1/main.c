#include"math.h"
int main()
{
    int A,B,C;//input A,B,C
    printf("You can use numbers only from 1 to 10.");//ban on words
    printf("\nEnter A: ");
	while (scanf("%d",&A)==0)
    {
        printf("Please enter ONLY digits!");
        return 0;
    }
	if(A <= 0 || A >= 11)
    {
        printf("Sorry, but number A can be only from 1 to 10.");//digits only from 1-10
        return 0;
    }
	printf("Enter B: ");
	while (scanf("%d",&B)==0)
    {
        printf("Please enter ONLY digits!");
        return 0;
    }
	if(B <= 0)
    {
        printf("Fatal Error(B can`t be <= 0)!!!");
        return 0;
    }
    if(B >= 11)
    {
        printf("Sorry, but number B can be only from 1 to 10.");
        return 0;
    }
	printf("Enter C: ");
	while (scanf("%d",&C)==0)
    {
        printf("Please enter ONLY digits!");
        return 0;
    }
	if(C <= 0 || C >= 11)
    {
        printf("Sorry, but number C can be only from 1 to 10.");
        return 0;
    }

	printf("The result of calculation:%f\n", Q(A, B, C));//result
	return 0;
}
