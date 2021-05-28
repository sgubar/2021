#include <stdio.h>

#include "lib.h"

    void anzi(int i, char *a[])
    {
        for (; i > 0; i--)
        {
            printf("%s ", a[i]);
        }
    }
