#include <stdio.h>
#include <stdlib.h>
#include "List.h"
int main()
{
    list *NewList = createList();
    listNode *NewNode = createNode('m');
    NewList->head = NewNode;
    addfrontNode(NewList, 't');
    addfrontNode(NewList, 'i');
    addbackNode(NewList, 'r');
    addbackNode(NewList, 'o');
    addbtwNode(NewList, 'g');





    printAllList(NewList);
    printf("\nNumber of elements in List is %d", NumberOfNodes(NewList));

    deleteSpecialNode(NewList, 'i');

    printAllList(NewList);

    FreeList(NewList);

}
