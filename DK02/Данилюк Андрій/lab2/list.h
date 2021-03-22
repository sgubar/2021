#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_h
#define LIST_h
typedef struct node_t
{
    int value;
    struct node_t* next;
    struct node_t* prev;
}   TNode;
TNode* GetList(size_t count);
TNode* RemoveEvery(TNode** list, size_t number);
void Print(const TNode* list);
#endif
