#ifndef array_h
#define array_h

#include <stdio.h>
#include "triangle.h"

typedef struct tagElement Element;

struct tagElement
{
    Tria *value;

    int index;

    Element *prev;

    Element *next;
};


Element *createElement(Tria *value);

void deleteElement(Element *element);

void printElement(Element *element);

//Array
typedef struct tagArray

{
    int maxCount;

    int currectCount;

    Element *head;

    Element *tail;
  
} Array;

Array *createArray(int maxCount);

void deleteArray(Array *array);

void printArray(Array *array);

int append(Array *array, Tria* value);

int appendByIndex(Array *array, Tria* value, int index);

#endif
