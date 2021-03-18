#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));
	if (NULL != result) {
	memset(result, 0, sizeof(IntListElement));
	result->value = value;
	}
	return result;
}
void DeleteThis(IntListElement *element) {
	if (NULL != element) {
	free(element);
	}
}
void printElement(IntListElement *element) {
	if (NULL != element) {
	printf("%d", element->value);
	}
}
IntList *createIntList(void) {
	IntList *result = (IntList *)
	malloc(sizeof(IntList));
	if (NULL != result) {
	memset(result, 0, sizeof(IntList));
	}
	return result;
}
void delete(IntList *list) {
	if (NULL == list) {
	return;
	}
	IntListElement *element = list->head;
	while(NULL != element) {
	IntListElement *tmp = element->next;
	DeleteThis(element);
	element = tmp;
	}
	free(list);
}
int ReadInteger(int number) {
  char c;
  while (1) 
  {
    if (!scanf("%d", &number) || getchar() != '\n') {  
    while ((c = getchar()) != '\n' && c != EOF);
    } else {
    return number;  
    }
    printf("Wrong number: ");
  }
}

void MakeListSizeAndAddValues(IntList *list, int count) 
{
for(int i = 0; i < count; i++) {
  printf("Enter number, please ");
  int number;
  ReadInteger(number);
  IntToList(list,ReadInteger(number));
  }
}
int IntToList(IntList *list, int value) 
	{
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 	return 0;
	}
	IntListElement *element = createIntListElement(value);
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
void printlist(IntList *list) {
	if (NULL == list) {
	printf("Incorrect point\n");
	return;
	}
	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
	printElement(element);
	printf(",");
	}
	if (element != NULL) {
	printElement(element);
	}
	printf("\n");
}
void Reverse(IntList *list) {
	if (NULL == list) {
	printf("Incorrect point\n");
	return;
	}
	IntListElement *element = NULL;
	for (element = list->tail; element != list->head; element = element->prev) {
	printElement(element);
	printf(",");
	}
	if (element != NULL) {
	printElement(element);
	}
	printf("\n");
}
