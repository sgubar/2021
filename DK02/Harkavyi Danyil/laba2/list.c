#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement* createIntListElement(int value) {
	IntListElement* result = (IntListElement*)malloc(sizeof(IntListElement));

	if (NULL != result) {
		//bzero (result, sizeof(IntListElement));
		result->value = value;
		result->next = NULL;
		result->prev = NULL;
		
	}

	return result;
}

void deleteIntListElement(IntListElement* element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement* element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

int addIntValueToIntList(IntList* list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	IntListElement* element = createIntListElement(value);
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



IntList* createIntList(void) {
	IntList* result = (IntList*)malloc(sizeof(IntList));

	if (NULL != result) {
	
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(IntList* list) {
	if (NULL == list) {
		return;
	}

	IntListElement* element = list->head;

	while (list->tail != element) {
		IntListElement* tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}
//void printIntList(IntList* list) {
//
//	if (NULL == list) {
//		printf("Invalid a pointer to the list\n");
//		return;
//	}
//
//	printf("[");
//
//	IntListElement* element = NULL;
//	for (element = list->head; element != list->tail; element = element->next) {
//		printIntListElement(element);
//		printf(",");
//	}
//
//	if (element != NULL) {
//		printIntListElement(element);
//	}
//
//	printf("]\n");
//}

void Search(IntList* list)
{
int a = 0, b = 0, c = 0;
IntListElement* result = list->head;
do
{
	
		if (result->value == '{') { a++; }
		else if (result->value == '}') { a--; }
		if (result->value == '(') { b++; }
		else if (result->value == ')') { b--; }
		if (result->value == '[') { c++; }
		else if (result->value == ']') { c--; }
	
	result = result->next;
} while (list->tail != result);

if (a != 0)
{
	printf("FALSE BALANCE\n Bracket '{}' : %d\n", a);
}
else
{
	printf("Balance bracket '{}': true\n");
}

if (b != 0)
{
	printf("FALSE BALANCE\n Bracket '()' : %d\n", b);
}
else
{
	printf("Balance bracket '()': true\n");
}

if (c != 0)
{
	printf("FALSE BALANCE\n Bracket '[]' : %d\n", c);
}
else
{
	printf("Balance bracket '[]': true");
}
}