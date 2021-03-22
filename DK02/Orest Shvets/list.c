#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
        memset (result, 0, sizeof(IntListElement));
		result->value = value;
	}

	return result;
}

void deleteIntListElement(IntListElement *element) {
	if (NULL != element) {
		free(element);
	}
}



void deleteIntList(IntList *list) {
	if (NULL == list) {
		return;
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
		printf("Error\n");
		return;
	}

	printf("|");

	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printIntListElement(element);
	}

	printf("|\n");
	printf ("\n");
}


void printRIntList(IntList *list) {

	if (NULL == list) {
		printf("Error\n");
		return;
	}

	printf("|");

	IntListElement *element = NULL;
	for (element = list->tail; element != list->head; element = element->prev) {
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printIntListElement(element);
	}

	printf("|\n");
	printf ("\n");
}
void addRandomValuesToList(IntList *list, int count)
{
    for(int i = 0; i < count; i++) {
    addIntValueToIntList(list, rand()%100);
    }
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
void printIntListElement(IntListElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

IntList *createIntList(void) {
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result) {
		memset(result, 0, sizeof(IntList));
	}

	return result;
}
