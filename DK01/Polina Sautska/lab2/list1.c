#include "list1.h"
#include <stdlib.h>
#include <string.h>

Character *createCharacter(char value){
    Character *result = (Character *)malloc(sizeof(Character));

    if (NULL != result){
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void deleteCharacter(Character *element){
    if (NULL != element)
    {
        free(element);
    }
}

void printCharacter(Character *element){
    if (NULL != element){
        printf("%c", element->value);
    }
}

Row *createRow(void){
    Row *result = (Row*)malloc(sizeof(Row));

    if (NULL != result)
    {
        result->head = NULL;
        result->tail = NULL;
        memset(result, 0, sizeof(Row));
    }
    return result;
}

void deleteRow(Row *list){
    if (NULL == list){
        return;
    }
  
    Character *element = list->head;

    while (NULL != element){
        Character *tmp = element->next;
        deleteCharacter(element);
        element = tmp;
    }
    free(list);
}

void printReverseRow(Row *list){
    if (NULL == list){
        printf("Invalid a pointer to the list\n");
        return;
    }

    Character *element = NULL;

    for (element = list->tail; element != list->head; element = element->prev){
        printCharacter(element);
    }
  
    if (element != NULL){
        printCharacter(element);
    }
    printf("\n");
}

int addCharacterToRow(Row *list, char value){
    if (NULL == list || (list->head == NULL && list->head != list->tail)){
        return 0;
    }

    Character *element = createCharacter(value);

    if (NULL == element){
        return 0;
    }
  
    if (NULL == list->head){
        list->head = element;
        list->tail = list->head;
        return 1;
    }
  
    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;

    return 1;
}
