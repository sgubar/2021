#include "M2.h"
#include <stdio.h>
#include <stdlib.h>

List* createList() {
    List *temp = (List*) malloc(sizeof(List));
    temp->size = 0;
    temp->head = temp->tail = NULL;
 
    return temp;
}

void deleteList(List **list) {
    Node *temp = (*list)->head;
    Node *next = NULL;
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list);
    (*list) = NULL;
}


Node* getNth(List *list, int index) {
    Node *tmp = list->head;
    size_t i = 0;
 
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}

void insert(List *list, int index, char value) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;
 
    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }
 
    list->size++;
}

void* deleteIndex(List *list, int index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
    return tmp;
}

void pushFront(List *list, char data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}


void* popFront(List *list) {
    Node *prev;
    void *tmp;
    if (list->head == NULL) {
        exit(2);
    }
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);
 
    list->size--;
    return tmp;
}

void pushBack(List *list, char value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
 
void* popBack(List *list) {
    Node *next;
    void *tmp;
    if (list->tail == NULL) {
        exit(4);
    }
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
 
    list->size--;
    return tmp;
}

int getSize(List *list){
	return list->size;
}

void printTail(List *list) {
    Node *temp = list->tail;
    while (temp) {
        printf("%c ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void printHead(List *list) {
    Node *temp = list->head;
    while (temp) {
        printf("%c ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void readNumber(int *a, int flag){
	int var, b=-50;
	if(flag) b=0;
	do {
		var = scanf("%i", a);
		scanf("%*[^\n]");
		if (var==0 || *a>50 || *a<b) printf("ERROR\nВведите корректное число: ");
	}while (var!=1 || *a>50 || *a<b);
}
