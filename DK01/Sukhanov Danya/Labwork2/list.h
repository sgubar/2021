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

void DeleteThis(IntListElement *element);
void printElement(IntListElement *element);

typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createIntList(void);

void delete(IntList *list);
int IntToList(IntList *list, int value);
void MakeListSizeAndAddValues(IntList *list, int count);
void printlist(IntList *list);
void Reverse(IntList *list);

int ReadInteger(int number);

#endif
