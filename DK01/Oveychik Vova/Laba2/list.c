#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
		memset(result,0, sizeof(IntListElement));
		result->value = value;
//		result->next = NULL;
//		result->prev = NULL;
	}

	return result;
}

void deleteIntListElement(IntListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

// List

IntList *createIntList(void) {
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result) {
//		result->head = NULL;
//		result->tail = NULL;
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(IntList *list) {
	if (NULL == list) {
		return ;
	}

	IntListElement *element = list->head;

	while(NULL != element) {
		IntListElement *tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}

void printIntList(IntList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printIntListElement(element);
	}

	printf("]\n");
}

int addIntValueToIntList(IntList *list, int value) {
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


IntListElement *MinListElement(IntList *list){
  if (list==NULL){
    return 0;
  }
   IntListElement *min =list->head;
   IntListElement *element = NULL;
  for(element = list->head; element !=list->tail; element = element->next)
  {
      if (min->value > element->value  ){
        min=element;
      }
  }
    if(min->value  >  list->tail->value){
        min=list->tail;
    }
  return min;
}

IntListElement *MaxListElement(IntList *list){
  if (list==NULL){
    return 0;
  }
   IntListElement *max =list->head;
   IntListElement *element = NULL;
  for(element = list->head; element !=list->tail; element = element->next)
  {
      if (max->value < element->value  ){
        max=element;
      }
  }
    if(max->value  <  list->tail->value){
        max=list->tail;
    }
  return max;
}

long countOfElementforMintoMax(IntList *list){
  if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (IntListElement *element = MinListElement(list); element != MaxListElement(list); element = element->next, count ++);

	return count;
}


IntList *SortForMinToMax(IntList *list){
    if (list==NULL){
    return 0;
}

     IntListElement *element = NULL;
     for(int i=0; i<countOfElementforMintoMax(list);i++){
  for(element = MinListElement(list); element !=MaxListElement(list); element = element->next){
        int p =element->value ;
    if (element->value > element->next->value){
        element->value=element->next->value;
        element->next->value=p;
    }
  }}
  return list;
}
