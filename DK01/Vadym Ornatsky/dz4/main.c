#include <stdio.h>
#include "linked_list.h"

int main() {
    T_ListNode* singleLinkedList = CreateList(1);
    AddToList(singleLinkedList, 2);
    AddToList(singleLinkedList, 2);
    AddToList(singleLinkedList, 3);
    AddToList(singleLinkedList, 4);
    AddToList(singleLinkedList, 5);
    AddToList(singleLinkedList, 6);
    AddToList(singleLinkedList, 6);
    AddToList(singleLinkedList, 2.1);
    AddToList(singleLinkedList, 23.5);

    PrintList(singleLinkedList);

    InsertByIndex(singleLinkedList, 5, 100);

    PrintList(singleLinkedList);

    RemoveFromListByIndex(singleLinkedList, 8);

    PrintList(singleLinkedList);

    printf("Final list size: %u\n",ListSize(singleLinkedList));

    DestroyList(singleLinkedList);
}
