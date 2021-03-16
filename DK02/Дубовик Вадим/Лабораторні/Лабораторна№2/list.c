#include "list.h"

//List element functions
pListEl createListEl(int value)
{
	pListEl NewEl = (pListEl)malloc(sizeof(ListEl));
	NewEl->value = value;
	NewEl->next = NULL;
	return NewEl;
}
void printListEl(pListEl listEl)
{
	if (listEl != NULL)
	{
		printf("%d", listEl->value);
	}
	return;
}
void deleteListEl(pListEl listEl)
{
	if (listEl != NULL)
	{
		free(listEl);
	}
	return;
}

//List functions
pList createList(void)
{
	pList newList = (pList)malloc(sizeof(List));
	if (newList != NULL)
	{
		newList->head = NULL;
		newList->AmountOfEl=0;
	}
	return newList;
}
void printList(pList list)
{
	if (list == NULL)
	{
		printf("List don't has any numbers\n");
		return;
	}

	printf("Your list is: \n \t [");

	for (pListEl El = list->head; El != NULL; El = El->next)
		{
		printListEl(El);
		if (El->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
	return;
}
void deleteList(pList list)
{
	if (list == NULL)
	{
		return;
	}

	pListEl El = list->head;
	while (El != NULL)
	{
		pListEl tmp = El->next;
		deleteListEl(El);
		El = tmp;
	}
	free(list);
}
int addIntToList(pList list, int value)
{
	if (NULL == list)
	{
		return 0;
	}

	pListEl El = createListEl(value);
	if (NULL == El)
	{
		return 0;
	}

	if (NULL == list->head)
	{
		list->head = El;
		return 1;
	}

	pListEl tail = list->head;

	while (NULL != tail->next)
	{
		tail = tail->next;
	}

	tail->next = El;
	list->AmountOfEl++;
	return 1;
}
int addElToList(pList list, pListEl El)
{
	if (list == NULL)
	{
		return 0;
	}
	if (El == NULL)
	{
		return 0;
	}
	if (NULL == list->head)
	{
		list->head = El;
		return 1;
	}

	pListEl tail = list->head;

	while (NULL != tail->next)
	{
		tail = tail->next;
	}

	tail->next = El;
	list->AmountOfEl++;
	return 1;
}
void removeLastElFromList(pList list)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == list->head)
	{
		return;
	}
	pListEl tail = list->head;
	if (tail->next == NULL)
	{
		list->head = NULL;
		list->AmountOfEl = 0;
		deleteListEl(tail);
		return;
	}
	while (NULL != tail->next && NULL != tail->next->next)
	{
		tail = tail->next;
	}
	deleteListEl(tail->next);
	list->AmountOfEl--;
	tail->next = NULL;
	return;
}
void removeElFromList(pList list, int index)
{
	if (list == NULL)
	{
		return;
	}
	if (index >= list->AmountOfEl)
	{
		return;
	}
	if (list->head == NULL)
	{
		return;
	}
	pListEl ex_El = list->head;
	for (int counter = 0; ex_El != NULL && counter < index - 1; ex_El = ex_El->next, counter++);
	pListEl toDelete = ex_El->next;
	ex_El->next = toDelete->next;
	deleteListEl(toDelete);
}



pList createListWithXEl(int elements)
{
	if (elements <= 0)
	{
		printf("List doesn't exist\n");
		return NULL;
	}
	pList list = createList();
	for (int counter = 0; counter < elements; counter++)
	{
		addElToList(list, createListEl(getNum()));
	}
	return list;
}









//My task functions
int getNum(void)
{
	int i=0;
	printf("Print the number:");
	scanf_s("%d", &i);
	if (i == NULL)
	{
		printf("You've entered the wrong symbol,\nPlease, enter only numbers.\n");
		return NULL;
	}
	printf("You have just entered: %d\n", i);
	return i;
}
int findAverage(pList list)
{
	if (list == NULL)
	{
		return 0;
	}

	pListEl currentEl = list->head;
	int sum = 0;
	for (; currentEl != NULL;currentEl=currentEl->next)
	{
		sum = sum + currentEl->value;
	}
	printf("The average number is: %d\n", sum / list->AmountOfEl);
	return sum / list->AmountOfEl;
}
void deleteFirstElLessThanValue(pList list, int index)
{
	if (list == NULL)
	{
		return;
	}
	if (list->head == NULL)
	{
		printf("You don't have any list\n");
		return;
	}
	pListEl currentEl = list->head;
	for (; currentEl->value > index; currentEl = currentEl->next);
	pListEl toDelete = currentEl->next;
	currentEl->next = toDelete->next;
	deleteListEl(toDelete);
	return;
}
