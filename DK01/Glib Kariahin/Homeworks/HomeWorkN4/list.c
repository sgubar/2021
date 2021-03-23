

#include "list.h"
#include <stdlib.h>
#include <string.h>

CharListElement *createCharListElement(char value) {
    CharListElement *result = (CharListElement *)malloc(sizeof(CharListElement));

    if (NULL != result) {
        //bzero(result, sizeof(IntListElement));
        result->value= value;
		result->next = NULL;
		result->prev = NULL;
    }

    return result;
}

void deleteCharListElement(CharListElement *element) {
    if (NULL != element) {
        free(element);
    }
}

void printCharListElement(CharListElement *element) {
    if (NULL != element) {
        printf("%c", element->value);
    }
}

CharList *createCharList(void) {
    CharList *result = (CharList *)malloc(sizeof(CharList));

    if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
        memset(result, 0, sizeof(CharList));
        result->count=0;
    }

    return result;
}

void deleteCharList(CharList *list) {
    if (NULL == list) {
        return ;
    }

    CharListElement *element = list->head;

    while(NULL != element) {
        CharListElement *tmp = element->next;
        deleteCharListElement(element);
        element = tmp;
    }

    free(list);
}

void printCharList(CharList *list) {

    if (NULL == list) {
        printf("Invalid a pointer to the list\n");
        return;
    }


    CharListElement *element = NULL;
    printf("[");
    for (element = list->head; element != list->tail; element = element->next) {
        printCharListElement(element);
    }

    if (element != NULL) {
        printCharListElement(element);
    }

    printf("]\n");
}


int addCharValueToCharList(CharList *list, char value) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    CharListElement *element = createCharListElement(value);
    if (NULL == element) {
        return 0;
    }

    if (NULL == list->head) {
        list->head = element;
        list->tail = list->head;
        list->count++;
        return 1;

    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;
    list->count++;
    return list->count;
}
//!
void removeLastElementFromCharList(CharList *list) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (NULL == list->head) {
        return;
    }

    // is single element list?
    if (list->head == list->tail) {
        deleteCharListElement(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->count--;
        return;
    }

    CharListElement *toDelete = list->tail;
    list->tail = toDelete->prev;
    list->tail->next = NULL;

    deleteCharListElement(toDelete);
    list->count--;
}

void removeAllCharElements(CharList *list){
    while(list->head!=NULL){
        removeLastElementFromCharList(list);
    }
}
long getSizeOfCharList(CharList *list){
    if(list!=NULL){
        return list->count;
    }
    return NullPointerException;
}

int insertCharElementToCharListAtIndex(CharList *list, int index, char value) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }
    long count = getSizeOfCharList(list);
    if (count == index) {
        return addCharValueToCharList(list, value);
    } else if (index > count) {
        return 0;
    }
    CharListElement *element = createCharListElement(value);
    if (NULL == element) {
        return 0;
    }
    if (0 == index) {
        element->next = list->head;
        list->head->prev = element;
        list->head = element;
    } else {
        int current = 0;
        CharListElement *ex_element = list->head;
        for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);
        element->next = ex_element;
        element->prev = ex_element->prev;
        ex_element->prev = element;
        element->prev->next = element;
        list->count++;
    }
    return 1;
}