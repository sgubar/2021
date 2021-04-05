#include "list.h"
#include <stdlib.h>

ListIntElem* createListElem(int value) {
	ListIntElem* result = (ListIntElem*)malloc(sizeof(ListIntElem));

	if (NULL != result) {
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void deleteListElem(ListIntElem* element) {
	if (NULL != element) {
		free(element);
	}
}

void printListElem(ListIntElem* element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

List* createList(void) {
	List* result = (List*)malloc(sizeof(List));

	if (NULL != result) {
		result->head = NULL;
	}

	return result;
}

void deleteList(List* list) {
	if (NULL == list) {
		return;
	}

	ListIntElem* element = list->head;

	while (NULL != element) {
		ListIntElem* tmp = element->next;
		deleteListElem(element);
		element = tmp;
	}

	free(list);
}

void printIntSingleList(List* list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	for (ListIntElem* element = list->head; element != NULL; element = element->next) {
		printListElem(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long countOList(List* list) {
	if (NULL == list) {
		return 0;
	}

	long count = 0;

	for (ListIntElem* element = list->head; element != NULL; element = element->next, count++);

	return count;
}

int addIntToList(List* list, int value) {
	if (NULL == list) {
		return 0;
	}

	ListIntElem* element = createListElem(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	ListIntElem* tail = list->head;

	while (NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromList(List* list) {
	if (NULL == list) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListIntElem* element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		deleteListElem(element);
		return;
	}

	while (NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	deleteListElem(element->next);
	element->next = NULL;
}

void removeFirstElementFromIntList(List* list) {
	if (NULL == list) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListIntElem* element = list->head->next;
	deleteListElem(list->head);
	list->head = element;
}

int insertElementToListByIndex(List* list, int index, int value) {

	if (NULL == list) {
		return 0;
	}

	long count = countOList(list);

	if (count == index) {
		return addIntToList(list, value);
	}

	ListIntElem* element = createListElem(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head = element;
	}
	else {
		int current = 0;
		ListIntElem* ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

		element->next = ex_element->next;
		ex_element->next = element;
	}

	return 1;
}

int removeElementFromListByIndex(List* list, int index) {
	if (NULL == list) {
		return 0;
	}

	long count = countOList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromIntList(list);
		return 1;
	}
	else if (index == (count - 1)) {
		removeLastElementFromList(list);
		return 1;
	}
	else {
		int current = 0;
		ListIntElem* ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

		ListIntElem* to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteListElem(to_delete);
	}

	return 1;
}