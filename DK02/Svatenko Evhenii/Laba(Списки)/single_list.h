#pragma once
#include <stdio.h>
#include <stdlib.h>

#define single_list_h
#ifdef single_list_h

typedef struct tag_single_list_element single_list_element;

typedef struct tag_single_list_element
{
	single_list_element *next;
	int value;
};

typedef struct tag_single_list single_list;

typedef struct tag_single_list
{
	single_list_element *head;
	//long count;
};

//List element functions
single_list_element *create_single_list_element(int value);
void print_single_list_element(single_list_element *element);
void delete_list_element(single_list_element *element);
//List functions
single_list *create_single_list(void);
int add_value_to_single_list(single_list *list, int value);

single_list *create_random_values_list (int value);
single_list* sort_elements_ascending(single_list* list);

void print_single_list(single_list *list);
void delete_single_list(single_list *list);


#endif
