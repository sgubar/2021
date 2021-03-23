#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"

int pow(int a, int b)
{
    int counter=1;
    for(int i=0; i<b; i++ )
        counter=counter*a;
    return counter;
}
