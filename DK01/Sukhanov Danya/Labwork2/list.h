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
int addIntValueToIntList(IntList *list, int value);
void addRandIntValuesToIntList(IntList *list, int count);
void printIntList(IntList *list);
void printReverseIntList(IntList *list);


#endif
