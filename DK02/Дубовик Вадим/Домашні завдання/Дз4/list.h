#pragma once
#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagIntListElement IntListElement, *pIntListElement;
struct tagIntListElement {
	int value;
	pIntListElement prev;
	pIntListElement next;
};

pIntListElement createIntListElement(int value);
void deleteIntListElement(pIntListElement element);
void printIntListElement(pIntListElement element);

// IntList

typedef struct tagIntList {
	IntListElement* head;
	IntListElement* tail;
} IntList, *pIntList;

IntList* createIntList(void);
void deleteIntList(pIntList list);

void printIntList(pIntList list);

long countOfIntList(pIntList list);

int addIntValueToIntList(pIntList list, int value);
void removeLastElementFromIntList(pIntList list);
void removeFirstElementFromIntList(pIntList list);

int insertIntElementToIntListAtIndex(pIntList list, int index, int value);
int removeIntElementFromIntListAtIndex(pIntList list, int index);

int getNum(void);
#endif