#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct tagDoubleListElement DoubleListElement;
struct tagDoubleListElement {
	double value;
	DoubleListElement *prev;
	DoubleListElement *next;
};

DoubleListElement *createDoubleListElement(double value);
void deleteDoubleListElement(DoubleListElement *element);
void printDoubleListElement(DoubleListElement *element);


typedef struct tagDoubleList {
	DoubleListElement *head;
	DoubleListElement *tail;
} DoubleList;

DoubleList *createDoubleList(void);
void deleteDoubleList(DoubleList *list);

void printDoubleList(DoubleList *list);

long countOfDoubleList(DoubleList *list);
int addDoubleValueToDoubleList(DoubleList *list, double value);
void removeLastElementFromDoubleList(DoubleList *list);
void removeFirstElementFromDoubleList(DoubleList *list);


int insertDoubleElementToDoubleListAtIndex(DoubleList *list, double index, double value);

int removeDoubleElementFromDoubleListAtIndex(DoubleList *list, double index);


#endif
