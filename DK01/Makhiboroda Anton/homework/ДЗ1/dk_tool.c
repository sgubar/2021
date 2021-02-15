#include "dk_tool.h"

int poisk(char str1[], char str2[]){

    int a=1;
    int counter=0;
    for(int i=0; i< strlen(str1)-strlen(str2)+1; i++)
    {
        for(int j =0; j<strlen(str2); j++)
            if(str1[i+j]!=str2[j])
            {
                a=0;
                break;
            }
        if(a!=0)
            counter++;
        a=1;
    }
    return counter;
}

