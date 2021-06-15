#include "list.h"
#include <stdlib.h>
#include <string.h>

DoubleListElement *createDoubleListElement(double value) {
	DoubleListElement *result = (DoubleListElement *)malloc(sizeof(DoubleListElement));

	if (NULL != result) {
		result->value = value;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteDoubleListElement(DoubleListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printDoubleListElement(DoubleListElement *element) {
	if (NULL != element) {
		printf("%.0f", element->value);
	}
}

DoubleList *createDoubleList(void) {
	DoubleList *result = (DoubleList *)malloc(sizeof(DoubleList));

	if (NULL != result) {
		memset(result, 0, sizeof(DoubleList));
	}

	return result;
}

void deleteDoubleList(DoubleList *list) {
	if (NULL == list) {
		return ;
	}

	DoubleListElement *element = list->head;

	while(NULL != element) {
		DoubleListElement *tmp = element->next;
		deleteDoubleListElement(element);
		element = tmp;
	}

	free(list);
}

void printDoubleList(DoubleList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	DoubleListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printDoubleListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printDoubleListElement(element);
	}

	printf("]\n");
}

long countOfDoubleList(DoubleList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (DoubleListElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

double addDoubleValueToDoubleList(DoubleList *list, double value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	DoubleListElement *element = createDoubleListElement(value);
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

void removeLastElementFromDoubleList(DoubleList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteDoubleListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	DoubleListElement *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteDoubleListElement(toDelete);
}

void removeFirstElementFromDoubleList(DoubleList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteDoubleListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	DoubleListElement *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteDoubleListElement(toDelete);
}

double insertDoubleElementToDoubleListAtIndex(DoubleList *list, double index, double value) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfDoubleList(list);

	if (count == index) {
		return addDoubleValueToDoubleList(list, value);
	} else if (index > count) {
		return 0;
	}

	DoubleListElement *element = createDoubleListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		DoubleListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

double removeDoubleElementFromDoubleListAtIndex(DoubleList *list, double index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfDoubleList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromDoubleList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromDoubleList(list);
		return 1;
	} else {
		int current = 0;
		DoubleListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteDoubleListElement(ex_element);
	}

	return 1;
}
