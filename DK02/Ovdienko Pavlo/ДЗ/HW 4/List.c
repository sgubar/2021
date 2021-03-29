#include "List.h"

ListOneElement* createListElement(int number) {
	ListOneElement* rev = (ListOneElement*)malloc(sizeof(ListOneElement));
	if (NULL != rev) {
		rev->number = number;
		rev->next = NULL;
	}
	return rev;
}

void deleteListElement(ListOneElement* element) {
	if (NULL != element) {
		free(element);
	}
}

void printListElement(ListOneElement* element) {
	if (NULL != element) {
		printf("%d", element->number);
	}
}

IntListOne* createIntList(void) {
	IntListOne* rev = (IntListOne*)malloc(sizeof(IntListOne));
	if (NULL != rev) {
		rev->head = NULL;
	}
	return rev;
}

void deleteIntList(IntListOne* list) {
	if (NULL == list) {
		return;
	}
	ListOneElement* number = list->head;

	while (NULL != number) {
		ListOneElement* tmp = number->next;
		deleteListElement(number);
		number = tmp;
	}
	free(list);
}

void printIntList(IntListOne* list) {
	if (NULL == list) {
		printf("What I should printf? ROFLAN ERROR");
		return;
	}
	printf("[");

	ListOneElement* number = list->head;

	while (NULL != number) {
		ListOneElement* tmp = number->next;
		printListElement(number);
		if (number->next != NULL) {
			printf(",");
		}
		number = tmp;
	}

	printf("]\n");
}

long countOfIntList(IntListOne* list) {
	if (NULL == list) {
		return 0;
	}
	long count = 0;
	ListOneElement* number = list->head;

	while (NULL != number) {
		ListOneElement* tmp = number->next;
		count++;
		number = tmp;
	}
	return count;
}

int addIntValueToIntList(IntListOne* list, int number) {
	if (NULL == list) {
		return 0;
	}

	ListOneElement* element = createListElement(number);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	ListOneElement* tail = list->head;

	while (NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromList(IntListOne* list) {
	if (NULL == list) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListOneElement* element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		deleteListElement(element);
		return;
	}

	while (NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	deleteListElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromList(IntListOne* list) {
	if (NULL == list) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	ListOneElement* element = list->head->next;
	deleteListElement(list->head);
	list->head = element;
}

int insertIntElementToIntListAtIndex(IntListOne* list, int index, int number) {
	if (NULL == number) {
		return 0;
	}
	
	long count = countOfIntList(list);

	if (count == index) {
		return addIntValueToIntList(list, number);
	}

	if (index >= count) {
		return 0;
	}

	ListOneElement* element = createListElement(number); {
		if (NULL == element) {
			return 0;
		}

		if (0 == index) {
			element->next = list->head;
			list->head = element;
		}
		else {
			int current = 0;
			ListOneElement* ex_element = list->head;
			for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

			element->next = ex_element->next;
			ex_element->next = element;
		}

		return 1;
	}
}

int removeIntElementFromIntListAtIndex(IntListOne* list, int index) {
	if (NULL == list) {
		return 0;
	}

	long count = countOfIntList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromList(list);
		return 1;
	}
	else if (index == (count - 1)) {
		removeLastElementFromList(list);
		return 1;
	}
	else {
		int current = 0;
		ListOneElement* ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

		ListOneElement* to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteListElement(to_delete);
	}

	return 1;
}


