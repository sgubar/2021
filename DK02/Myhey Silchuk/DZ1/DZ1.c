#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x;
    int count = 0;
    int result = 0;
    int backnumber = 0;


//Checking if we do not have more than 8 symbols
    do
    {
    printf("Enter your number: ");
    scanf("%d", &x);

    int check = x;
    while(check != 0)
    {
       check = check/10;
       count++;
    }

    }while(count>8);

//checking if we have a binary number and calculating it, transforming into a
    for(int i = 0; i<count; i++)
    {
        backnumber = x%10;
        if(backnumber!=0 && backnumber!=1)
        {
            printf("Your number is not a binary number");
            break;
        }
        if(backnumber==1 && i==0)
        {
              result = result+1;
        }
        else if(backnumber==1 && i!=0)
        {
            result = result + powf(2, i);
        }
        x = x/10;
    }
printf("Result is %d", result);

}
