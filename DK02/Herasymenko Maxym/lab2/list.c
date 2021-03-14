#include "list.h"
#include <stdlib.h>
#include <stdio.h>

IntListElement *createElement(int value)
{
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result)
    {
		bzero(result, sizeof(IntListElement));
		result->value = value;
	}

	return result;
}

void deleteElement(IntListElement *element)
{
	if (NULL != element)
    {
		free(element);
	}
}

void printElement(IntListElement *element)
{
	if (NULL != element)
    {
		printf("%d", element->value);
	}
}


IntList *createList(void)
{
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result)
    {
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteList(IntList *list)
{
	if (NULL == list)
    {
		return ;
	}

	IntListElement *element = list->head;

	while(NULL != element)
    {
		IntListElement *tmp = element->next;
		deleteElement(element);
		element = tmp;
	}

	free(list);
}

void printList(IntList *list)
{

	if (NULL == list)
    {
		printf("Invalid a pointer to the list\n");
		return;
	}
	for(int i = 0; i < 2; i++)
	{
	printf("[");

	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next)
    {
		printElement(element);
		printf(",");
	}

	if (element != NULL)
    {
		printElement(element);
	}

	printf("]\n");
	}
}


long countOfIntList(IntList *list)
{
	if (NULL == list)
    {
 		return 0;
	}

	long count = 0;

	for (IntListElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addValueToList(IntList *list, int value)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
    {
 		return 0;
	}

	IntListElement *element = createElement(value);
	if (NULL == element)
    {
		return 0;
	}

	if (NULL == list->head)
    {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}



int insertElementToList_Index(IntList *list, int index, int value)
{

	if (NULL == list || (list->head == NULL && list->head != list->tail))
    {
 		return 0;
	}

	long count = countOfIntList(list);

	if (count == index) {
		return addValueToList(list, value);
	}
	else if (index > count)
	{
		return 0;
	}

	IntListElement *element = createElement(value);
	if (NULL == element)
    {
		return 0;
	}

	if (0 == index)
        {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	    }
	else
    {
		int current = 0;
		IntListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

void printReverse_order(IntList *list)
{

	if (NULL == list)
    {
		return 0;
	}

	for(int i = 0; i < 2; i++)
    {
	printf("[");

	IntListElement *element = NULL;
	for (element = list->tail; element != list->head; element = element->prev)
    {
		printElement(element);
		printf(",");
	}

	if (element != NULL)
    {
		printElement(element);
	}

	printf("]\n");
	}
}

