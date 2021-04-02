#ifndef _M2_H_
#define _M2_H_

typedef struct _Node {
    char value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _List {
    int size;
    Node *head;
    Node *tail;
} List;

void deleteList(List **list);
void insert(List *list, int index, char value);
void* deleteIndex(List *list, int index);
void pushFront(List *list, char data);
void* popFront(List *list);
void pushBack(List *list, char value);
void* popBack(List *list);
int getSize(List *list);
void printTail(List *list);
void printHead(List *list);
void readNumber(int *a, int flag);

#endif
