#pragma once
#include <stdio.h>
#include <stdlib.h>

#define List_h
#ifdef List_h

typedef struct list_item_float list_item;

struct list_item_float
{
	float data;
	list_item* next_item;

};

list_item* make_list_item(float data);
void delete_list_item(list_item* item);

typedef struct
{
	list_item* first_item;
	int count;

} list_float;

list_float* make_list(void);
void delete_list(list_float* list);

void add_data_to_list(list_float* list, float data);
void print_list(list_float* list);

void add_data_to_list_by_index(list_float* list, int index, float data);
void remove_data_by_index(list_float* list, int index);

static void remove_first_data(list_float* list);
static void remove_last_data(list_float* list);

#endif // List_h