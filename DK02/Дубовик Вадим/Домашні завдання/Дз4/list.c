#include "list.h"

// Element

pIntListElement createIntListElement(int value) {
	pIntListElement result = (pIntListElement)malloc(sizeof(IntListElement));

	if (NULL != result)
	{
		//bzero(result, sizeof(IntListElement));
		result->value = value;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteIntListElement(pIntListElement element)
{
	if (NULL != element)
	{
		free(element);
	}
}

void printIntListElement(pIntListElement element)
{
	if (NULL != element)
	{
		printf("%d", element->value);
	}
}

// List

pIntList createIntList(void)
{
	pIntList result = (pIntList)malloc(sizeof(IntList));

	if (NULL != result)
	{
		//		result->head = NULL;
		//		result->tail = NULL;
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(pIntList list)
{
	if (NULL == list)
	{
		return;
	}

	pIntListElement element = list->head;

	while (NULL != element)
	{
		pIntListElement tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}

void printIntList(pIntList list)
{

	if (NULL == list)
	{
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	pIntListElement element = NULL;
	for (element = list->head; element != list->tail; element = element->next)
	{
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL)
	{
		printIntListElement(element);
	}

	printf("]\n");
}

long countOfIntList(pIntList list)
{
	if (NULL == list)
	{
		return 0;
	}

	long count = 0;

	for (pIntListElement element = list->head; element != NULL; element = element->next, count++);

	return count;
}

int addIntValueToIntList(pIntList list, int value)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
	{
		return 0;
	}

	pIntListElement element = createIntListElement(value);
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

void removeLastElementFromIntList(pIntList list)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
	{
		return;
	}

	if (NULL == list->head)
	{
		return;
	}

	if (list->head == list->tail)
	{
		deleteIntListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	pIntListElement toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteIntListElement(toDelete);
}

void removeFirstElementFromIntList(pIntList list)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
	{
		return;
	}

	if (NULL == list->head)
	{
		return;
	}

	if (list->head == list->tail)
	{
		deleteIntListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	pIntListElement toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteIntListElement(toDelete);
}

int insertIntElementToIntListAtIndex(pIntList list, int index, int value)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
	{
		return 0;
	}

	long count = countOfIntList(list);

	if (count == index)
	{
		return addIntValueToIntList(list, value);
	}
	else if (index > count)
	{
		return 0;
	}

	pIntListElement element = createIntListElement(value);
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
		pIntListElement ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeIntElementFromIntListAtIndex(pIntList list, int index)
{
	if (NULL == list || (list->head == NULL && list->head != list->tail))
	{
		return 0;
	}

	long count = countOfIntList(list);
	if (index >= count)
	{
		return 0;
	}

	if (0 == index)
	{
		removeFirstElementFromIntList(list);
		return 1;
	}
	else if (index == (count - 1))
	{
		removeLastElementFromIntList(list);
		return 1;
	}
	else
	{
		int current = 0;
		pIntListElement ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteIntListElement(ex_element);
	}

	return 1;
}

int getNum(void)
{
	int i = 0;
	printf("Print the number:");
	scanf_s("%d", &i);
	if (i == NULL)
	{
		printf("You've entered the wrong symbol,\nPlease, enter only numbers.\n");
		return -1;
	}
	printf("You have just entered: %d\n", i);
	return i;
}