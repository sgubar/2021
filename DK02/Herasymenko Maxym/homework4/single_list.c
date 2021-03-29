#include"single_list.h"
#include<stdio.h>
#include<stdlib.h>

Single_listCharElement *createSingle_listCharElement(char value)
{
    Single_listCharElement *result = (Single_listCharElement *)malloc(sizeof(Single_listCharElement));
    if (NULL != result)
    {
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void print_Single_listCharElement(Single_listCharElement *element)
{
    if (NULL != element)
    {
		printf("%c", element->value);
	}
}
void delete_Single_listCharElement(Single_listCharElement *element)
{
    if (NULL != element)
    {
		free(element);
	}
}

CharSingle_list *createCharSingle_list(void)
{
    CharSingle_list *result =(CharSingle_list *)malloc(sizeof(CharSingle_list));
    if (NULL != result)
    {
		result->head = NULL;
	}

	return result;
}

int addCharValue(CharSingle_list *list, char value)
{
    if (NULL == list)
    {
 		return 0;
	}
	Single_listCharElement *element = createSingle_listCharElement(value);
	if (NULL == element)
    {
		return 0;
	}

	if (NULL == list->head)
    {
		list->head = element;
		return 1;
	}
	Single_listCharElement *tail = list->head;
	while(NULL != tail->next)
    {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

int removeCharElementfromList_usingIndex(CharSingle_list *list, int index)
{
    if (NULL == list)
    {
 		return 0;
	}
	long count = countCharSingle_list(list);

    if (index >= count)
    {
		return 0;
	}

	if(0 == index)
    {
        removeFirstCharElementfromList(list);
        return 1;
    }
	else if (index == (count - 1))
    {
        removeLastCharElementfromList(list);
        return 1;
    }
    else
    {
        int current = 0;
        Single_listCharElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);
        Single_listCharElement *to_delete = ex_element->next;
        ex_element->next = to_delete->next;
        delete_Single_listCharElement(to_delete);
    }
     return 1;
}


long countCharSingle_list(CharSingle_list *list)
{
    if (NULL == list)
    {
 		return 0;
	}

	long count = 0;
	for(Single_listCharElement *element = list->head; element != NULL; element = element->next, count++);
	return count;
}

void removeFirstCharElementfromList(CharSingle_list *list)
{
    if (NULL == list)
    {
 		return;
	}

	if (NULL == list->head)
    {
		return;
	}
    Single_listCharElement *element = list->head->next;
	delete_Single_listCharElement(list->head);
	list->head = element;
}

void removeLastCharElementfromList(CharSingle_list *list)
{
	if (NULL == list)
    {
 		return;
	}

	if (NULL == list->head)
    {
		return;
	}
     Single_listCharElement *element = list->head;
     if (NULL == element->next)
    {
		list->head = NULL;
		delete_Single_listCharElement(element);
		return;
	}

	while(NULL != element->next && NULL != element->next->next)
    {
		element = element->next;
	}
	delete_Single_listCharElement(element->next);
	element->next = NULL;

}

int insertCharElementtoList_usingIndex(CharSingle_list *list, int index, char value)
{
    if (NULL == list)
    {
 		return 0;
	}

	long count = countCharSingle_list(list);

	if (count == index) {
		return addCharValue(list, value);
	}

	Single_listCharElement *element = createSingle_listCharElement(value);
	if (NULL == element)
    {
		return 0;
	}
	if (0 == index)
	{
		element->next = list->head;
		list->head = element;
	}
	else
	{
		int current = 0;
		Single_listCharElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		element->next = ex_element->next;
		ex_element->next = element;
	}
	return 1;
}
void printCharSingle_list(CharSingle_list *list)
{
    if (NULL == list)
    {
		printf("Invalid a pointer to the list\n");
		return;
	}
	printf("[");

	for (Single_listCharElement *element = list->head; element != NULL; element = element->next)
    {
		print_Single_listCharElement(element);
		if (element->next != NULL)
        {
			printf(",");
		}
	}
	printf("]\n");
}
void deleteCharSingle_list(CharSingle_list *list)
{
    if (NULL == list)
    {
		return ;
	}

	Single_listCharElement *element = list->head;

	while(NULL != element) {
		Single_listCharElement *tmp = element->next;
		delete_Single_listCharElement(element);
		element = tmp;
	}

	free(list);
}
