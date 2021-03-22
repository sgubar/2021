#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"

double module(int m)
{
    if (m<0)
    {
        return m*(-1);
    }
    else
    {
        return m;
    }
}
