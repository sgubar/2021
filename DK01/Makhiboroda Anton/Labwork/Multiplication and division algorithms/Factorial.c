#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"

int factorial(int e)
{
    int count = 1;
    for(int a=1; a<e+1; a++ )
{
    count=count*a;
}
    return count;
}
