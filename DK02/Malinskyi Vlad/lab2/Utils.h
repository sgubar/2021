#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdbool.h>
#include "myList.h"

bool isPresentedTwiceInList(List *listToSearch, int number);
List *findStart(List *listToSearch, int number);
List *findEnd(List *listToSearch, int number);

void changeOrder(List *startNode, List *endNode);
void oddSwap(int index, List *start, List *end);
void evenSwap(int index, List *start, List *end);

#endif // UTILS_H_INCLUDED
