#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"

int durak123(char str[])
{
    int b=0;
    if(strlen(str)==0)
        return 0;
    for(int a=0; a<strlen(str); a++){
        if ( 47 < str[a] && str[a] < 58 ){
            b=b+1;
        }
    }
    if(b==strlen(str)){return 1;}
    else{return 0;}

}
