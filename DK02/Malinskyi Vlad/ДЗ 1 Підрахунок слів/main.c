#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dk_tool.h"






void main(void)
{
    char *s = NULL;
    s = (char*) calloc(255, sizeof(char));
    printf("Vvedite predlojenie: ");
    gets(s);
    func(s);
    free(s);
    return 0;
    system("pause");
}

