#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
	int value;
	IntListElement *prev;
	IntListElement *next;
};

IntListElement *createIntListElement(int value);
void deleteIntListElement(IntListElement *element);
void printIntListElement(IntListElement *element);


typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

long countOfIntList(IntList *list);
int addIntValueToIntList(IntList *list, int value);
void removeLastElementFromIntList(IntList *list);
void removeFirstElementFromIntList(IntList *list);


int insertIntElementToIntListAtIndex(IntList *list, int index, int value);

int removeIntElementFromIntListAtIndex(IntList *list, int index);


#endif
