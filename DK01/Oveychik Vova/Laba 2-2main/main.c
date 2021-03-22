#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*This program sorting int elements for min to max between min and max
This is Laboratory work #2
Variant #11
Oveychick DK 01*/
int main()
{
    printf("Hello world!\n");

    IntListElement *element1 = createIntListElement(5);
    printIntListElement(element1);
    printf("\n");

    IntList *list = createIntList();

   addIntValueToIntList(list,4);
    addIntValueToIntList(list,5);
    addIntValueToIntList(list,1);
    addIntValueToIntList(list,3);
    addIntValueToIntList(list,2);
    addIntValueToIntList(list,4);
    addIntValueToIntList(list,6);
    addIntValueToIntList(list,5);
    addIntValueToIntList(list,8);
    addIntValueToIntList(list,4);

    printf("%d\n",countOfElementforMintoMax(list));

    printIntList(list);
    printf("Min =");
    printIntListElement( MinListElement(list));
    printf("\nMax =");
    printIntListElement( MaxListElement(list));
    printf("\n");

    SortForMinToMax(list);
    printIntList(list);

   deleteIntListElement(element1);
    deleteIntList(list);
    return 0;

}
