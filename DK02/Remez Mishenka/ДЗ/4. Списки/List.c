#include "List.h"

list_item* make_list_item(float data)
{
	list_item* item = (list_item*)malloc(sizeof(list_item));
	if (item != NULL)
	{
		item->data = data;
		item->next_item = NULL;
	}
	return item;
}

void delete_list_item(list_item* item)
{
	if (NULL != item)
		free(item);
}

list_float* make_list(void)
{
	list_float* list = (list_float*)malloc(sizeof(list_float));
	if (list != NULL)
		list->first_item = NULL;
	list->count = 0;
	return list;
}

void delete_list(list_float* list)
{
	if (NULL == list)
		return;
	list_item* elem = list->first_item;
	while (elem != NULL)
	{
		list_item* mask = elem->next_item;
		delete_list_item(elem);
		elem = mask;
	}
	free(list);
}

void add_data_to_list(list_float* list, float data)
{
	if (list == NULL)
		return;
	list_item* item = make_list_item(data);
	if (item == NULL)
		return;
	if (list->first_item == NULL)
	{
		list->first_item = item;
		list->count++;
		return;
	}
	list_item* tail = list->first_item;

	while (NULL != tail->next_item)
	{
		tail = tail->next_item;
	}
	tail->next_item = item;
	list->count++;
	return;
}

void print_list(list_float* list)
{
	if (list == NULL)
	{
		printf("Ошибка списка\n");
		return;
	}
	printf("[");
	for (list_item* item = list->first_item; item != NULL; item = item->next_item)
	{
		printf("%0.1f", item->data);
		if (item->next_item != NULL)
		printf(", ");
	}	
	printf("]\n");
}

void add_data_to_list_by_index(list_float* list, int index, float data) 
{
	if (NULL == list) {
		return 0;
	}

	if (list->count == index) {
		add_data_to_list(list, data);
		return;
	}

	list_item* elem = make_list_item(data);
	if (NULL == elem) {
		return;
	}

	if (0 == index) {
		elem->next_item = list->first_item;
		list->first_item = elem;
	}
	else {
		int cur = 0;
		list_item* mask = list->first_item;
		for (; mask != NULL && cur < index - 1; mask = mask->next_item, cur++);

		elem->next_item = mask->next_item;
		mask->next_item = elem;
	}

	return;
}

void remove_data_by_index(list_float* list, int index)
{
	if (NULL == list) {
		return 0;
	}

	if (index > list->count) {
		return;
	}
	if (0 == index) {
		remove_first_data(list);
		return 1;
	}
	else if (index == (list->count - 1)) {
		remove_last_data(list);
		return 1;
	}
	else {
		int cur = 0;
		list_item* mask = list->first_item;
		for (; mask != NULL && cur < index - 1; mask = mask->next_item, cur++);

		list_item* item_for_delete = mask->next_item;
		mask->next_item = item_for_delete->next_item;
		delete_list_item(item_for_delete);
	}
	return;
}

static void remove_first_data(list_float* list)
{
	if (NULL == list) 
	{
		return;
	}

	if (NULL == list->first_item) 
	{
		return;
	}

	list_item* elem = list->first_item->next_item;
	delete_list_item(list->first_item);
	list->first_item = elem;
}

static void remove_last_data(list_float* list)
{
	if (NULL == list) 
	{
		return;
	}

	if (NULL == list->first_item) 
	{
		return;
	}

	list_item* elem = list->first_item;

	if (NULL == elem->next_item) 
	{
		list->first_item = NULL;
		delete_list_item(elem);
		return;
	}

	while (NULL != elem->next_item && NULL != elem->next_item->next_item) 
	{
		elem = elem->next_item;
	}
	delete_list_item(elem->next_item);
	elem->next_item = NULL;
	return;
}