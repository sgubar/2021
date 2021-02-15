#include <stdio.h>
#include <stdlib.h>
#include "funk_math.h"

long kvad(int a)
{
    long result=a*a;
    return result;
}
long fakt(int f)
{
    long result=1;
    if (f<0)
        {   printf("error, don`t exist factorial,  result is wrong\n");
            return 0;
        } else
        {
            for(int i=0; i<f;i++)
            {
                result =result*(i+1);
            }
            return result;
        }
}
double in_step(int step)
{
   int a=5;
    float result=1;
    if (step>0)
    {   for(int i=0;i<step;i++)
        {
            result=result*a;
        }
       return result;
    } else
        {
            step*=-1;
            for(int i=0;i<step;i++)
                {
                    result=result*a;
                }
                return 1/result;
        }
        return result;
}
double res(int a, int b, int c)
{
   double result =0;
    if ((b+in_step(c))<0)
    {
        printf("error, look up for search problem, result is wrong\n");
    } else
        {
            result=(kvad(a)+kvad(b))/(b+in_step(c))+fakt(b);
        }
        return result;
}
