#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pow.h"
#include "convert.h"
#include "durak123.h"
#include "Module.h"
#include "Factorial.h"


int main(int argc, char argv[])
{
    printf("Vas vitae programa z pidrahynky formylu: A!/|2*A+B| \n");
    printf("\n");
    printf("/|................Yvaga!!......................|\\ \n");
    printf("||V zminny A mojna vvodutu chislo do 10        || \n");
    printf("||V zminny B Mojna vvodutu chislo do 5 sumvoliv|| \n");
    printf("||Vci chisla povunni bytu NATURALNI            || \n");
    printf("\\|.............................................|/ \n");
    printf("\n");
    printf("Programy stvoruv student DK-01 Makhiboroda Anton\n");
    printf("\n");
 Yes: ;
    char strA[10];
    char strB[10];
    printf("Vvedit chuslo A:");
    scanf("%s",strA);
        if ( 0 > convert(strA) || convert(strA) > 10 ) goto Err;
    //printf("%d \n" ,strA[0]);
    printf("Vvedit chuslo B:");
    scanf("%s",strB);
        if ( strlen(strB) >5  ) goto Err;
    //printf("%d \n" ,strB[0]);
    printf("\n");
    //printf("%d \n", durak123(strA));
    //printf("%d \n", durak123(strA));
 if (durak123(strA) && durak123(strB) == 1)
 {

    int a=convert(strA);
    //printf("Chislo_1: %d",a);
    //printf("\n");
    int B=convert(strB);
    //printf("Chislo_2: %d",B);
    //printf("\n");

    long int A=factorial(a);
    //printf("factorial: %d\n",A);
    //printf("modul: %f\n",module((2*a)+B));
    double Q=A/module((2*a)+B);
    printf("Rezultat %f", Q);

    char tryAgain;
    printf("\n Wanna try again? (y/n)");
      scanf("%s", &tryAgain);
      if(tryAgain=='y' || tryAgain=='Y') goto Yes;
 }
 else{
 Err: ;
        char tryAgain;
    printf("Ne korekto bulu vvedeni chusla!");
    printf("\n Wanna try again? (y/n)");
      scanf("%s", &tryAgain);
      if(tryAgain=='y' || tryAgain=='Y') goto Yes;
 }
    return 0;
}
