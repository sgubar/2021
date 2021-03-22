#include "single_list.h"

single_list_element* create_single_list_element(int value) {
	single_list_element* element = (single_list_element*)malloc(sizeof(single_list_element));
	element->value = value;
	element->next = NULL;
	return element;
}

void print_single_list_element(single_list_element* element) {
	if (element != NULL) {
		printf("%d", element->value);
	}
	return;
}

void delete_list_element(single_list_element* element) {
	if (element != NULL) {
		free(element);
	}
	return;
}

single_list* create_single_list(void) {
	single_list* list = (single_list*)malloc(sizeof(single_list));
	if (list != NULL) {
		list->head = NULL;
	}
	return list;
}

int add_value_to_single_list(single_list* list, int value)
{
	if (NULL == list) {
		return 0;
	}

	single_list_element* element = create_single_list_element(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	single_list_element* tail = list->head;

	while (NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

single_list* create_random_values_list(int value) {
	if (value <= 0) {
		return NULL;
	}
	single_list* list = create_single_list();
	for (int i = 0; i < value; i++) {
		add_value_to_single_list(list, rand() % 100 + 1); //Добавляю у список рандомні значення від 1 до 100
	}
	return list;
}

single_list* sort_elements_ascending(single_list* list) {
	single_list_element* head = list->head;
	single_list_element* new_head = NULL;

	while (head != NULL) {
		single_list_element* tmp = head;
		head = head->next;

		if (new_head == NULL || tmp->value < new_head->value) {
			tmp->next = new_head;
			new_head = tmp;
		}
		else {
			single_list_element* current = new_head;
			while (current->next != NULL && !(tmp->value < current->next->value)) {
				current = current->next;
			}
			tmp->next = current->next;
			current->next = tmp;
		}
	}
	list->head = new_head;
	return list;
}

void print_single_list(single_list* list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	for (single_list_element* element = list->head; element != NULL; element = element->next) {
		print_single_list_element(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

void delete_single_list(single_list* list) {
	if (NULL == list) {
		return;
	}

	single_list_element* element = list->head;

	while (NULL != element) {
		single_list_element* tmp = element->next;
		delete_list_element(element);
		element = tmp;
	}

	free(list);
}
