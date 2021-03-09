#ifndef list_h
#define list_h
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct tagDoubleLinkedListElement DoubleLinkedListElement;
struct tagDoubleLinkedListElement {
	char element;
	DoubleLinkedListElement* next;
	DoubleLinkedListElement* prev;
};

typedef struct tagDoubleCharList {
	DoubleLinkedListElement* head;
	DoubleLinkedListElement* tail;
}DoubleCharList;

DoubleLinkedListElement* createDoubleListElement(char el);
void deleteDoubleListElement(DoubleLinkedListElement* element);
void printDoubleLinkedListElement(DoubleLinkedListElement* element);
DoubleCharList* createDoubleCharList(void);
void deleteDoubleCharList(DoubleCharList* list);
void printDoubleCharList(DoubleCharList* list);
long countOfDouble(DoubleCharList* list);
int addCharValueToDoubleCharList(DoubleCharList* list, char value);
void printRevDoubleCharList(DoubleCharList* list);
void clearDoubeCharlist(DoubleCharList* list);
void reFreshDoubleCharList(DoubleCharList* list);
void reverseTextFile(FILE* fPointer);

#endif