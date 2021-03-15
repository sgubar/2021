//
//  list.c
//  list
//
//  Created by Slava Gubar on 03.03.2021.
//

#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement *createIntListElement(int value) {
    IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

    if (NULL != result) {
        //bzero(result, sizeof(IntListElement));
        result->value = value;
		result->next = NULL;
		result->prev = NULL;
    }

    return result;
}

void deleteIntListElement(IntListElement *element) {
    if (NULL != element) {
        free(element);
    }
}

void printIntListElement(IntListElement *element) {
    if (NULL != element) {
        printf("%d", element->value);
    }
}

// List

IntList *createIntList(void) {
    IntList *result = (IntList *)malloc(sizeof(IntList));

    if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
        memset(result, 0, sizeof(IntList));
    }

    return result;
}

void deleteIntList(IntList *list) {
    if (NULL == list) {
        return ;
    }

    IntListElement *element = list->head;

    while(NULL != element) {
        IntListElement *tmp = element->next;
        deleteIntListElement(element);
        element = tmp;
    }

    free(list);
}

void printIntList(IntList *list) {

    if (NULL == list) {
        printf("Invalid a pointer to the list\n");
        return;
    }

    printf("[");

    IntListElement *element = NULL;
    for (element = list->head; element != list->tail; element = element->next) {
        printIntListElement(element);
        printf(",");
    }

    if (element != NULL) {
        printIntListElement(element);
    }

    printf("]\n");
}


int addIntValueToIntList(IntList *list, int value) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    IntListElement *element = createIntListElement(value);
    if (NULL == element) {
        return 0;
    }

    if (NULL == list->head) {
        list->head = element;
        list->tail = list->head;
        return 1;
    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;

    return 1;
}
//!
void removeLastElementFromIntList(IntList *list) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (NULL == list->head) {
        return;
    }

    // is single element list?
    if (list->head == list->tail) {
        deleteIntListElement(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    IntListElement *toDelete = list->tail;
    list->tail = toDelete->prev;
    list->tail->next = NULL;

    deleteIntListElement(toDelete);
}




