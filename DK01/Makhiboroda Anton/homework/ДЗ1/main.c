#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
int main()


{
    char str1[100];
    char str2[100];
    printf("Vvedit rechenna: ");
    gets(str1);
    printf("Vvedit chislo dla povtorennya: ");
    gets(str2);
    printf("%d", poisk(str1, str2));
    return 0;
}

