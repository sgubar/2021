#include <stdio.h>
#include "math.h"
#include <ctype.h>

int main()
{
    int a, b, c, kinez = 1;
    double Q;
    restart:
    printf("Type numbers A,B and C: \n");
    if (scanf_s("%d", &a) && scanf_s("%d", &b) && scanf_s("%d", &c))
    {
        if (a < 0)
        {
            printf("Error. Numbers entered incorrectly.\n");
            fflush(stdin);
            getchar();
            goto question;
        }
        printf("Numbers entered correctly. \n");
    }
    else {
        printf("Error. Numbers entered incorrectly.\n");
        fflush(stdin);
        getchar();
        goto question;
    }


    if ((double)(100 - b - c) == 0)
    {
        printf("Fatal error! Division by 0. \n");
    }
    else
    {
        Q = ((a + b + c) / (double)(100 - b - c)) + (double)sum(a);
        printf("%f\n", Q);
    }
    question:
    printf("Type 1 to restart program or 0 to exit: ");
    scanf_s("%d", &kinez);
    if (kinez == 1)
    {
        goto restart;
    }
    else if (kinez == 0)
    {
        return 0;
    }

}