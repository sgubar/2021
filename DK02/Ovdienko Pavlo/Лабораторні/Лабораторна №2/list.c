#include "list.h"

ListNumbers* createListNumbers(int value) {
	ListNumbers* list = (ListNumbers*)malloc(sizeof(ListNumbers));

	if (NULL != list) {
		memset(list, 0, sizeof(ListNumbers));
		list->value = value;
	}
	return list;
}

void deleteListNumbers(ListNumbers* number) {
	if (NULL != number) {
		free(number);
	}
}

void printListNumbers(ListNumbers* number) {
	if (NULL != number) {
		printf("%d", number->value);
	}
}

IntList* createIntList(void) {
	IntList* list = (IntList*)malloc(sizeof(IntList));

	if (NULL != list) {
		memset(list, 0, sizeof(IntList));
	}

	return list;
}

int addIntValueToIntList(IntList* list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	ListNumbers* number = createListNumbers(value);
	if (NULL == number) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = number;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = number;
	number->prev = list->tail;
	list->tail = number;

	return 1;
}

void printIntList(IntList* list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	ListNumbers* number = NULL;
	for (number = list->head; number != list->tail; number = number->next) {
		printListNumbers(number);
		printf(",");
	}

	if (number != NULL) {
		printListNumbers(number);
	}

	printf("]\n");
}

void deleteIntList(IntList* list) {
	if (NULL == list) {
		return;
	}

	ListNumbers* number = list->head;

	while (NULL != number) {
		ListNumbers* tmp = number->next;
		deleteListNumbers(number);
		number = tmp;
	}
	free(list);
}

long countElementsOfIntList(IntList * list) {

	if (NULL == list) {
		return 0;
	}

	long count = 0;

	for (ListNumbers* number = list->head; number != NULL; number = number->next, count++);

	return count;
}

void removeLastElementFromIntList(IntList* list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteListNumbers(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	ListNumbers* toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteListNumbers(toDelete);
}

void removeFirstElementFromIntList(IntList* list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteListNumbers(list->head);
		list->head = list->tail = NULL;
		return;
	}

	ListNumbers* toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteListNumbers(toDelete);
}

int insertIntElementToIntListAtIndex(IntList* list, int index, int value) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	long count = countElementsOfIntList(list);

	if (count == index) {
		return addIntValueToIntList(list, value);
	}
	else if (index > count) {
		return 0;
	}

	ListNumbers* number = createListNumbers(value);
	if (NULL == number) {
		return 0;
	}

	if (0 == index) {
		number->next = list->head;
		list->head->prev = number;
		list->head = number;
	}
	else {
		int current = 0;
		ListNumbers* ex_number = list->head;
		for (; ex_number != NULL && current != index; ex_number = ex_number->next, current++);

		number->next = ex_number;
		number->prev = ex_number->prev;
		ex_number->prev = number;
		number->prev->next = number;
	}

	return 1;
}

int removeIntElementFromIntListAtIndex(IntList* list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	long count = countElementsOfIntList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromIntList(list);
		return 1;
	}
	else if (index == (count - 1)) {
		removeLastElementFromIntList(list);
		return 1;
	}
	else {
		int current = 0;
		ListNumbers* ex_number = list->head;
		for (; ex_number != NULL && current != index; ex_number = ex_number->next, current++);

		ex_number->prev->next = ex_number->next;
		ex_number->next->prev = ex_number->prev;

		deleteListNumbers(ex_number);
	}

	return 1;
}
