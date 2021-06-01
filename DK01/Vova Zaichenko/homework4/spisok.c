#include <stdlib.h>
#include <stdio.h>

struct Node
{
    float m_Value;
    struct Node* pNext;
    struct Node* pPrev;
};

struct List
{
    int m_iSize;
    struct Node* m_pHead;
    struct Node* m_pTail;
};

struct List* createList()
{
    struct List* tmp = (struct List*)malloc(sizeof(struct List));
    tmp->m_iSize = 0;
    tmp->m_pHead = tmp->m_pTail = NULL;
    return tmp;
}

void push_back(struct List* otherList, const float value)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) 
    {
        exit(0);
    }
    tmp->m_Value = value;
    tmp->pNext = NULL;
    tmp->pPrev = otherList->m_pTail;
    if (otherList->m_pTail)
    {
        otherList->m_pTail->pNext = tmp;
    }
    otherList->m_pTail = tmp;

    if (otherList->m_pHead == NULL)
    {
        otherList->m_pHead = tmp;
    }
    otherList->m_iSize++;
}

void pop_back(struct List* otherList)
{
    struct Node* currentNode = NULL;
    if (otherList == NULL || otherList->m_pTail == NULL)
    {
        return;
    }

    currentNode = otherList->m_pTail;
    otherList->m_pTail = otherList->m_pTail->pPrev;
    if (otherList->m_pTail) 
    {
        otherList->m_pTail->pNext = NULL;
    }
    if (currentNode == otherList->m_pHead)
    {
        otherList->m_pHead = NULL;
    }
    free(currentNode);
    otherList->m_iSize--;
}

void clear(struct List* otherList)
{
    while (otherList->m_pHead)
    {
        pop_back(otherList);
    }
}

struct Node* get_by_index(struct List* otherList, const int index)
{
    struct Node* currentNode = otherList->m_pHead;
    size_t i = 0;
    while (currentNode && i < index) 
    {
        currentNode = currentNode->pNext;
        i++;
    }
    return currentNode;
}

void insert(struct List* otherList, const int index, const float value)
{
    struct Node* currentNode = NULL;
    struct Node* newNode = NULL;
    currentNode = get_by_index(otherList, index);
    if (currentNode == NULL)
    {
        return;
    }
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->m_Value = value;
    newNode->pNext = currentNode;
    newNode->pPrev = currentNode->pPrev;
    if (currentNode->pPrev)
    {
        currentNode->pPrev->pNext = newNode;
    }
    currentNode->pPrev = newNode;

    if (!newNode->pPrev)
    {
        otherList->m_pHead = newNode;
    }
    otherList->m_iSize++;
}

void delete_by_index(struct List* otherList, const int index)
{
    struct Node* elm = NULL;
    elm = get_by_index(otherList, index);
    if (elm == NULL) 
    {
        return;
    }
    if (elm->pPrev) 
    {
        elm->pPrev->pNext = elm->pNext;
    }
    if (elm->pNext)
    {
        elm->pNext->pPrev = elm->pPrev;
    }

    if (!elm->pPrev)
    {
        otherList->m_pHead = elm->pNext;
    }
    if (!elm->pNext) 
    {
        otherList->m_pTail = elm->pPrev;
    }

    free(elm);
    otherList->m_iSize--;
}

void print_List(struct List* otherList) {
    struct Node* currentNode = otherList->m_pHead;
    while (currentNode)
    {
        printf("%f   ", currentNode->m_Value);
        currentNode = currentNode->pNext;
    }
}


int main()
{
    struct List* lst_1 = createList();
    push_back(lst_1, 1.1);
    push_back(lst_1, 2.2);
    push_back(lst_1, 3.3);
    push_back(lst_1, 4.4);

    printf("lst_1:   ");
    print_List(lst_1);
    printf("\n");
    
    pop_back(lst_1);
    pop_back(lst_1);

    printf("lst_1:   ");
    print_List(lst_1);
    printf("\n");

    insert(lst_1, 0, 10.2);
    insert(lst_1, 2, 20.2);

    printf("lst_1:   ");
    print_List(lst_1);
    printf("\n");

    printf("lst_1[1]:   %f\n", get_by_index(lst_1, 1)->m_Value);
    
    printf("lst_1 size:   %d\n", lst_1->m_iSize);

    delete_by_index(lst_1, 1);
    print_List(lst_1);
    printf("\n");

    printf("lst_1 size:   %d\n", lst_1->m_iSize);
    clear(lst_1);
    printf("after clear lst_1 size:   %d\n", lst_1->m_iSize);
	return 0;
}
