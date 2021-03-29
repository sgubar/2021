#include <stdio.h>
#include <stdlib.h>

#define List_h
#ifdef List_h

typedef struct tagListOneElement ListOneElement;
 struct tagListOneElement {
	ListOneElement* next;
	int number;
};

ListOneElement* createListElement(int number);
void deleteListElement(ListOneElement* element);
void printListElement(ListOneElement* element);

typedef struct {
	ListOneElement* head;
} IntListOne;

IntListOne* createIntList(void);
void deleteIntList(IntListOne* list);
void printIntList(IntListOne* list);
long countOfIntList(IntListOne* list);
int addIntValueToIntList(IntListOne* list, int number);
void removeLastElementFromList(IntListOne* list);
void removeFirstElementFromList(IntListOne* list);
int insertIntElementToIntListAtIndex(IntListOne* list, int index, int number);
int removeIntElementFromIntListAtIndex(IntListOne* list, int index);


#endif