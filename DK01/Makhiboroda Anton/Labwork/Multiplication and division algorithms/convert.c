#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"

int convert(char str[])
{
    int a=0;
    for(int i =0; i< strlen(str); i++)
        a+= (str[i]-48)*pow(10, strlen(str)-1-i);

    return a;
}
