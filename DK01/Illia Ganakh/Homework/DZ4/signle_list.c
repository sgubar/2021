#include "signle_list.h"
#include <stdlib.h>

SingleListcharElement *createSingleListcharElement(char value) {
	SingleListcharElement *result = (SingleListcharElement *)malloc(sizeof(SingleListcharElement));

	if (NULL != result) {
		result->value = value;
		result->next = NULL;
	}
  return result;
}

void deleteSingleListcharElement(SingleListcharElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printSingleListcharElement(SingleListcharElement *element) {
	if (NULL != element) {
		printf("%c", element->value);
	}
}

charSingleList *createcharSingleList(void) {
	charSingleList *result = (charSingleList *)malloc(sizeof(charSingleList));

	if (NULL != result) {
		result->head = NULL;
	}

	return result;
}

void deletecharSingleList(charSingleList *list) {
	if (NULL == list) {
		return ;
	}

	SingleListcharElement *element = list->head;

	while(NULL != element) {
		SingleListcharElement *tmp = element->next;
		deleteSingleListcharElement(element);
		element = tmp;
	}

	free(list);
}

void printcharSingleList(charSingleList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	for (SingleListcharElement *element = list->head; element != NULL; element = element->next) {
		printSingleListcharElement(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long countOfcharSingleList(charSingleList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (SingleListcharElement *element = list->head; element != NULL; element = element->next, count++);

	return count;
}

int addcharValueTocharSingleList(charSingleList *list, char value) {
	if (NULL == list) {
 		return 0;
	}

	SingleListcharElement *element = createSingleListcharElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	SingleListcharElement *tail = list->head;

	while(NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromcharSingleList(charSingleList *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	SingleListcharElement *element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		deleteSingleListcharElement(element);
		return;
	}

	while(NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	deleteSingleListcharElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromcharSingleList(charSingleList *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	SingleListcharElement *element = list->head->next;
	deleteSingleListcharElement(list->head);
	list->head = element;
}

int insertcharElementTocharSingleListAtIndex(charSingleList *list, int index, char value) {

	if (NULL == list) {
 		return 0;
	}

	long count = countOfcharSingleList(list);

	if (count == index) {
		return addcharValueTocharSingleList(list, value);
	}

	SingleListcharElement *element = createSingleListcharElement(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head = element;
	} else {
		int current = 0;
		SingleListcharElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		element->next = ex_element->next;
		ex_element->next = element;
	}

	return 1;
}

int removecharElementFromcharSingleListAtIndex(charSingleList *list, int index) {
	if (NULL == list) {
 		return 0;
	}

	long count = countOfcharSingleList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromcharSingleList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromcharSingleList(list);
		return 1;
	} else {
		int current = 0;
		SingleListcharElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

		SingleListcharElement *to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteSingleListcharElement(to_delete);
	}

	return 1;
}