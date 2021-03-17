
#ifndef list_h
#define list_h

#include <stdio.h>
#define NullPointerException (-3)
typedef struct tagCharListElement CharListElement;
struct tagCharListElement {
    char value;
    CharListElement *prev;
    CharListElement *next;
};

CharListElement *createCharListElement(char value);
void deleteCharListElement(CharListElement *element);
void printCharListElement(CharListElement *element);

typedef struct tagCharList {
    int count;
    CharListElement *head;
    CharListElement *tail;
} CharList;

CharList *createCharList(void);
void deleteCharList(CharList *list);
void printCharList(CharList *list);
int addCharValueToCharList(CharList *list, char value);
void removeLastElementFromCharList(CharList *list);
void removeAllCharElements(CharList *list);
long getSizeOfCharList(CharList *list);
int insertCharElementToCharListAtIndex(CharList *list, int index, char value);
#endif /* list_h */