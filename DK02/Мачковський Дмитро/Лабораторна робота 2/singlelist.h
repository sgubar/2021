#ifndef singlelist
#define singlelist

#include <stdio.h>

typedef struct tagSingleListIntElement SingleListIntElement;

typedef struct tagSingleListIntElement {

	SingleListIntElement* next;
	int value;

};

SingleListIntElement* createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement* element);
void printSingleListIntElement(SingleListIntElement* element);

typedef struct IntSingleList {

	SingleListIntElement* head;

}IntSingleList;

IntSingleList* createIntSingleList(void);
void deleteIntSingleList(IntSingleList* list);
void printIntSingleList(IntSingleList* list);
long countOfIntSingleList(IntSingleList* list);
int addIntValueToIntSingleList(IntSingleList* list, int value);
int insertIntElementToIntSingleListAtIndex(IntSingleList* list, int index, int value);
void doubleValueFromUser(IntSingleList* list, int value);

#endif
