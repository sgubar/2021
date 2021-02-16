#include "math.h"
#define MOD(n < 0 ? -n : n)

double power(int base, int pow);
{
    long result = 1;
    for (int i = 0, i < MOD(pow); i++)
    {
        result *= base;
    }
    return(pow < 0) ? 1/result : result;
}
long sum(int start, int finish);
{
    long result=0;
    for (int i = start; i < finish; i++)
    {
        result += power (2; finish);
    }
    return result;
}
float q(int A, int B, int C);
{
    return ((A*C-B)/power(C; 3))*sum(0; A);
}
