#pragma once
#include <stdio.h>
#include <stdlib.h>

#define LIST_H
#ifdef LIST_H

typedef struct tagListEl ListEl, * pListEl;

typedef struct tagListEl
{
	pListEl next;
	int value;
};

typedef struct tagList List, * pList;

typedef struct tagList
{
	pListEl head;
	long AmountOfEl;
};

//List element functions
pListEl createListEl(int value);
void printListEl(pListEl listEl);
void deleteListEl(pListEl listEl);

//List functions
pList createList(void);
pList createListWithXEl(int elements);
void printList(pList list);
void deleteList(pList list);
int addIntToList(pList list, int value);
int addElToList(pList list, pListEl El);
void removeLastElFromList(pList list);
void removeElFromList(pList list, int index);

//My task functions
int getNum(void);
int findAverage(pList list);
void deleteFirstElLessThanValue(pList list, int index);
#endif