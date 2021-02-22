#include "myPow.h"

double myPow(double stepen, double chislo)
{
    double numberToReturn = chislo;
    for(int i = 0; i < stepen; i++)
    {
        numberToReturn = numberToReturn * chislo;
    }
    return numberToReturn;
}
