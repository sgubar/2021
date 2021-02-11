#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "DK_TOOL.h"

int sum(char* s);

void main(void)
{
    char *s = NULL;
    s = (char*) calloc(255, sizeof(char));
    printf("Vvedite predlojenie: ");
    gets(s);
    sum(s);
    return 0;
    system("pause");
}


