#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct tagIntListElement IntListElement;
struct tagIntListElement
{
	int value;
	IntListElement *prev;
	IntListElement *next;
};

IntListElement *createElement(int value);
void printElement(IntListElement *element);
void deleteElement(IntListElement *element);



typedef struct tagIntList
{
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createList(void);
int addValueToList(IntList *list, int value);
int insertElementToList_Index(IntList *list, int index, int value);
void printList(IntList *list);
void printReverse_order(IntList *list);
void deleteList(IntList *list);

#endif
