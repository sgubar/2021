
#define list_h
#ifdef list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tagListNumbers ListNumbers;
struct tagListNumbers {
	int value;
	ListNumbers *prev;
	ListNumbers *next;
};

ListNumbers* createListNumbers(int value);
void deleteListNumbers(ListNumbers* element);
void printListNumbers(ListNumbers* element);

typedef struct {
	ListNumbers* head;
	ListNumbers* tail;
} IntList;

IntList* createIntList(void);
void deleteIntList(IntList* list);
void printIntList(IntList* list);
long countElementsOfIntList(IntList* list);
int addIntValueToIntList(IntList* list, int value);
void removeLastElementFromIntList(IntList* list);
void removeFirstElementFromIntList(IntList* list);
int insertIntElementToIntListAtIndex(IntList* list, int index, int value);
int removeIntElementFromIntListAtIndex(IntList* list, int index);

#endif