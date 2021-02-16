#include "myFactorial.h"

double fac(double l)
{
    for (int i=l-1; i>=1; i--)
        l=l*i;
    return l;
}
