#include <stdio.h>
#include <stdlib.h>
#include "list.h"

TNode* Push(TNode** list, int value)
{
    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->value = value;
    node->next = *list;
    node->prev = NULL;
 
    if (*list)
    {
        (*list)->prev = node;
    }
 
    *list = node;
 
    return *list;
}

void RemoveNode(TNode* node)
{
    if (node->prev)
    {
        node->prev->next = node->next;
    }
 
    if (node->next)
    {
        node->next->prev = node->prev;
    }
 
    free(node);
}

TNode* RemoveEvery(TNode** list, size_t number)
{
    size_t counter = 0;
    TNode* node = *list;
    TNode* tmp;
 
    while (node)
    {
        if (++counter == number)
        {
            counter = 0;
            tmp = node;
            node = node->next;
            RemoveNode(tmp);
        }
        else
        {
            node = node->next;
        }
    }
 
    if (number == 1)
    {
        *list = NULL;
    }
 
    return *list;
}

TNode* GetList(size_t count)
{
    TNode* list = NULL;
 
    while (count--)
    {
        Push(&list, rand() % 90 + 10);
    }
 
    return list;
}

void Print(const TNode* list)
{
    for (; list; list = list->next)
    {
        printf("%d, ", list->value);
    }
    printf("\b\b \n");
}
