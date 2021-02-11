#include <stdio.h>
#include <stdlib.h>
#include "octa.h"
int eight(int a)
{
    int first =0;
    int second=0;
    int third=0;
    int fourth=0;
    if (a>9999 || a<0)
    {
        printf("sorry this number has more than four number or < 0");
    } else
        {
             first=a/1000;
             if(first<8)
                {
                first*=512;
                } else {
                    printf("uncorect number\n ");
                    return 0;
                }
             second=a%1000/100;
              if(second<8)
                {
                second*=64;
                } else{
                    printf("uncorect number\n");
                    return 0;
                }
             third=a%100/10;
              if(third<8)
                {
                third*=8;
                } else {
                    printf("uncorect number\n");
                    return 0;
                }
             fourth=a%10;
              if(fourth<8)
                {
                first*=1;
                } else {
                    printf("uncorect number\n");
                    return 0;
                }


        }int result=first+second+third+fourth;
        return result;
}
