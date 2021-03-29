#ifndef signle_list_h
#define signle_list_h

#include <stdio.h>

typedef struct tagSingleListcharElement SingleListcharElement;

struct tagSingleListcharElement {
	SingleListcharElement *next;
	char value;
};

SingleListcharElement *createSingleListcharElement(char value);
void deleteSingleListcharElement(SingleListcharElement *element);
void printSingleListcharElement(SingleListcharElement *element);

typedef struct tagcharSingleList {
	SingleListcharElement *head;
} charSingleList;

charSingleList *createcharSingleList(void);
void deletecharSingleList(charSingleList *list);

void printcharSingleList(charSingleList *list);

long countOfcharSingleList(charSingleList *list);

int addcharValueTocharSingleList(charSingleList *list, char value);
void removeLastElementFromcharSingleList(charSingleList *list);
void removeFirstElementFromcharSingleList(charSingleList *list);

int insertcharElementTocharSingleListAtIndex(charSingleList *list, int index, char value);
int removecharElementFromcharSingleListAtIndex(charSingleList *list, int index);


#endif