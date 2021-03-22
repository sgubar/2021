#include <stdio.h>
#include "list.h"
int main(void)
{
    IntList *list = createIntList();
    addRandomValuesToList(list, 26);
    for(int i = 0; i < 2; i++) {
    printIntList(list);
    printRIntList(list);
    }
    deleteIntList(list);
}
