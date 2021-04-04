#pragma once
#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct tagListElem ListIntElem;

struct tagListElem {
	ListIntElem* next;
	int value;
};

ListIntElem* createListElem(int value);
void deleteListElem(ListIntElem* element);
void printListElem(ListIntElem* element);

typedef struct tagList {
	ListIntElem* head;

} List;

List* createList(void);
void deleteList(List* list);

void printIntSingleList(List* list);

long countOList(List* list);
int addIntToList(List* list, int value);
void removeLastElementFromList(List* list);
void removeFirstElementFromIntList(List* list);

int insertElementToListByIndex(List* list, int index, int value);
int removeElementFromListByIndex(List* list, int index);


#endif