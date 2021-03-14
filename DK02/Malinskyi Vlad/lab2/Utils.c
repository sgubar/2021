#include "Utils.h"
#include "myList.h"

void oddSwap(int index, List *start, List *end)
{
    index--;
    while(index > 0)
    {
        List *iter = start;

        for(int i = 0; i < index; i++)
        {
            iter = iter->next;
        }
        end = iter;
        swapNodes(start, iter);



        start = start->next;


        index -= 2;
    }
}

void evenSwap(int index, List *start, List *end)
{
    index--;
    while(index >= 2)
    {
        List *iter = start;

        for(int i = 0; i < index; i++)
        {
            iter = iter->next;
        }
        end = iter;
        swapNodes(start, iter);



        start = start->next;


        index -= 2;
    }
}

bool isPresentedTwiceInList(List *listToSearch, int number)
{
    int occurrences = 0;
    List *iter = listToSearch;

    while(iter != NULL)
    {
        if(iter->val == number)
            occurrences++;
        iter = iter->next;
    }
    return (occurrences >= 2);
}

List *findStart(List *listToSearch, int number)
{
    List *iter = listToSearch;

    while(iter != NULL)
    {
        if(iter->val == number)
            return iter;
        iter = iter->next;
    }
}
List *findEnd(List *listToSearch, int number)
{
    bool meet = false;

    List *iter = listToSearch;

    List* valueToReturn;

    while(iter != NULL)
    {
        if(iter->val == number)
            valueToReturn = iter;
        iter = iter->next;
    }
    return valueToReturn;
}

void changeOrder(List *startNode, List *endNode)
{
    int index = 0;
    List *iter = startNode;

    while(iter != endNode)
    {
        index++;
        iter = iter->next;
    }
    index--;



    if(!(index % 2))
    {
        oddSwap(index, startNode->next, endNode);
    }
    else
    if(index % 2)
    {
        evenSwap(index, startNode->next, endNode);
    }
}

