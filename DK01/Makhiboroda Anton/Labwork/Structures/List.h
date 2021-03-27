#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
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

// IntList

typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createIntList(void);
void deleteIntList(IntList *list);
void printIntList(IntList *list);
int addIntValueToIntList(IntList *list, int value);
IntListElement *MaxListElement(IntList *list);
long countOfElementforHeadtoMax(IntList *list);
IntList *SortForHeadToMax(IntList *list);



#endif // LIST_H_INCLUDED
