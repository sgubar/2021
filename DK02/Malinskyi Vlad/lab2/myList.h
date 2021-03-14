#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}List;

List *init(int a);
List *addelem(List *lst, int number);
List *input(int *listSize);

void printList(List *myList);
void swapNodes(List *node1, List *node2);

void freeList(List* head);

#endif // MYLIST_H_INCLUDED
