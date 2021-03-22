#include"list.h"

DoubleLinkedListElement* createDoubleListElement(char el) {
	DoubleLinkedListElement* result = (DoubleLinkedListElement*)malloc(sizeof(DoubleLinkedListElement));
	if (NULL != result) {
		memset(result, 0, sizeof(DoubleLinkedListElement));
		result->element = el;
	}
	return result;
}
void deleteDoubleListElement(DoubleLinkedListElement* element) {
	if (NULL != element) {
		free(element);
	}
}

void printDoubleLinkedListElement(DoubleLinkedListElement* el) {
	if (NULL != el) {
			printf("%c", el->element);
	}
}

DoubleCharList* createDoubleCharList(void) {
	DoubleCharList* result = (DoubleCharList*)malloc(sizeof(DoubleCharList));

	if (NULL != result) {
		memset(result, 0, sizeof(DoubleCharList));
	}

	return result;
}

void deleteDoubleCharList(DoubleCharList* list) {
	if (NULL == list) {
		return;
	}

	DoubleLinkedListElement* element = list->head;
    
	while (NULL != element) {
		DoubleLinkedListElement* tmp = element->next;
		deleteDoubleListElement(element);
		element = tmp;
	}

	free(list);
}


void printDoubleCharList(DoubleCharList* list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

//	printf("[");

	DoubleLinkedListElement* element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printDoubleLinkedListElement(element);
		//	printf("");
	}

	if (element != NULL) {
		printDoubleLinkedListElement(element);
	}

	//printf("]\n");
}

int addCharValueToDoubleCharList(DoubleCharList* list, char value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	DoubleLinkedListElement* element = createDoubleListElement(value);
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

	return 2;
}

void printRevDoubleCharList(DoubleCharList* list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}



	DoubleLinkedListElement* element = NULL;
	for (element = list->tail; element != list->head; element = element->prev) {
		printDoubleLinkedListElement(element);
		//	printf("");
	}

	if (element != NULL) {
		printDoubleLinkedListElement(element);
	}

}


DoubleCharList* ClearCharList(DoubleCharList* list) {
	DoubleCharList* new_list = createDoubleCharList();
	deleteDoubleCharList(list);
	return  new_list;
}
