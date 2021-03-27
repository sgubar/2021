#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "List.h"
int main()
{

    printf("Vas vitae programa z vuznachennam MAX, ta sortuvannam vid menshogo \n");
    printf("\n");
    printf("/|................Yvaga!!......................|\ \n");
    printf("|| Mojna vvodutu chisla vid 0 do 1000          || \n");
    printf("|| Mojna vvodutu kilkist chisel do 100         || \n");
    printf("||   Vci chisla povunni bytu NATURALNI         || \n");
    printf("\\|.............................................|/\n");
    printf("\n");
    printf("Programy stvoruv student DK-01 Makhiboroda Anton\n");
    printf("\n");
Yes: ;
    IntListElement *element1 = createIntListElement(5);

    printf("\n");

    IntList *list = createIntList();

    int b=0;

    printf("Vvedit kilkist chisel: ");
    scanf("%d", &b);
    if ( 0 > b || b > 100 ) goto Err;
     for (int i=0,a=0; i <b; i++)
        {
            if ( 0 > a || a > 1000 ) goto Err;
              printf("Vvedit chislo %d: ",i+1);
              scanf("%d", &a);
              addIntValueToIntList(list,a);
        }
    printf("\n");

    printIntList(list);

    printf("\nMax =");
    printIntListElement( MaxListElement(list));
    printf("\n");

    SortForHeadToMax(list);
    printIntList(list);

    deleteIntListElement(element1);
    deleteIntList(list);

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
