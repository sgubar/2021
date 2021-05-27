#include "char_list.h"
#include <stdlib.h>
//work with element
ListCharElement *createListCharElement(char sumbol) {
	ListCharElement *result = (ListCharElement *)malloc(sizeof(ListCharElement));

	if (NULL != result) {
		result->sumbol = sumbol;
		result->next = NULL;
	}

	return result;
}

void deleteListCharElement(ListCharElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printListCharElement(ListCharElement *element) {
	if (NULL != element) {
		printf("%d", element->sumbol);
	}
}

//work with list

CharList *createCharList(void) {
	CharList *result = (CharList *)malloc(sizeof(CharList));

	if (NULL != result) {
		result->head = NULL;
	}

	return result;
}

void deleteCharList(CharList *list) {
	if (NULL == list) {
		return ;
	}

	ListCharElement *element = list->head;

	while(NULL != element) {
		ListCharElement *tmp = element->next;
		deleteListCharElement(element);
		element = tmp;
	}

	free(list);
}

void printCharList(CharList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	for (ListCharElement *element = list->head; element != NULL; element = element->next) {
		printListCharElement(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long countOfCharList(CharList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (ListCharElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addCharSumbolToCharList(CharList *list, char sumbol) {
	if (NULL == list) {
 		return 0;
	}

	ListCharElement *element = createListCharElement(sumbol);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	ListCharElement *tail = list->head;

	while(NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}


void removeLastElementFromCharList(CharList *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListCharElement *element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		deleteListCharElement(element);
		return;
	}

	while(NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	deleteListCharElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromCharList(CharList *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListCharElement *element = list->head->next;
	deleteListCharElement(list->head);
	list->head = element;
}


int insertCharElementToCharListAtIndex(CharList *list, int index, char sumbol) {

	if (NULL == list) {
 		return 0;
	}

	long count = countOfCharList(list);

	if (count == index) {
		return addCharSumbolToCharList(list, sumbol);
	}

	ListCharElement *element = createListCharElement(sumbol);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head = element;
	} else {
		int current = 0;
		ListCharElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		element->next = ex_element->next;
		ex_element->next = element;
	}

	return 1;
}

int removeCharElementFromCharListAtIndex(CharList *list, int index) {
	if (NULL == list) {
 		return 0;
	}

	long count = countOfCharList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromCharList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromCharList(list);
		return 1;
	} else {
		int current = 0;
		ListCharElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		ListCharElement *to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteListCharElement(to_delete);
	}

	return 1;
}
