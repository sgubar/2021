#ifndef CHAR_LIST_H_INCLUDED
#define CHAR_LIST_H_INCLUDED

#include <stdio.h>

//char element

typedef struct tagListCharElement ListCharElement;

struct tagListCharElement {
	ListCharElement *next;
	char sumbol;
};

ListCharElement *createListCharElement(char sumbol);
void deleteListCharElement(ListCharElement *element);
void printListCharElement(ListCharElement *element);

//char list

typedef struct tagCharList {
	ListCharElement *head;
} CharList;

CharList *createCharList(void);
void deleteCharList(CharList *list);

void printCharList(CharList *list);

long countOfCharList(CharList *list);

int addCharSumbolToCharList(CharList *list, char sumbol);

void removeLastElementFromCharList(CharList *list);
void removeFirstElementFromCharList(CharList *list);

int insertCharElementToCharListAtIndex(CharList *list, int index, char sumbol);
int removeCharElementFromCharListAtIndex(CharList *list, int index);

#endif // CHAR_LIST_H_INCLUDED
