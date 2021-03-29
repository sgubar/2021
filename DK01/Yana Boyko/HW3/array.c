#include "array.h"
#include <stdlib.h>
#include <string.h>

Element *createElement(Tria *value)
{
    if (value == NULL)
    {
        printf("Tringle is NULL");
        return NULL;
    }

    Element *result = (Element *)malloc(sizeof(Element));
    if (NULL != result)
    {
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void deleteElement(Element *element)
{
    if (NULL != element)
    {
        deleteTria(element->value);

        free(element);
    }
}

void printElement(Element *element)

{
    if (NULL != element)
    {
        printf("\nTriangle of index %d:\n", element->index);

        printTriange(element->value);
    }
}
// List
Array *createArray(int maxCount)

{
    Array *result = (Array*)malloc(sizeof(Array));
    if (NULL != result && maxCount > 0)
    {
        result->maxCount = maxCount;

        result->currectCount = 0;

        result->head = NULL;

        result->tail = NULL;
    }
    return result;
}


void deleteArray(Array *array)
{
    if (NULL == array)
    {
        return;
    }
    Element *element = array->head;
  
    while (NULL != element)
    {
        Element *tmp = element->next;

        deleteElement(element);

        element = tmp;
    }
    free(array);
}

void printArray(Array *array)
{
    if (NULL == array)
    {
        printf("Invalid a pointer to the array\n");
        return;
    }
    Element *element = NULL;

    for (element = array->head; element != array->tail; element = element->next)
    {
        printElement(element);
    }
  
    if (element != NULL)
    {
        printElement(element);
    }

    printf("\n");
}

int append(Array *array, Tria *value)
{
    if (NULL == array || (array->head == NULL && array->head != array->tail))
    {
        return -1;
    }

    Element *element = createElement(value);

    if (NULL == element)
    {
        return -1;
    }

    if (array->currectCount + 1 > array->maxCount){

        printf("Array is completely filled\n");

        return -1;
    }

    if (NULL == array->head)
    {

        array->head = element;

        array->tail = array->head;

        element->index = array->currectCount;

        array->currectCount++;

        return 0;
    }


    array->tail->next = element;

    element->prev = array->tail;

    array->tail = element;


    element->index = array->currectCount;

    array->currectCount++;
  
    return array->currectCount - 1;
}

int appendByIndex(Array *array, Tria *value, int index)
{
    if (NULL == array || (array->head == NULL && array->head != array->tail))
    {
        return -1;
    }

    Element *element = createElement(value);
    if (NULL == element)

    {
        return -1;
    }

    if (array->currectCount + 1 > array->maxCount){

        printf("Array is completely filled\n");

        return -1;
    }

    if (index == array->currectCount)
    {
        append(array, value);
    }

    if (index > array->currectCount)
    {
        return -1;
    }

    Element *oldElement = array->head;

    while (oldElement->index != index)
    {
        oldElement = oldElement->next;
    }

    if (oldElement->prev != NULL)
    {
        oldElement->prev->next = element;
    }

    else
    {
        array->head = element;
    }

    element->index = index;

    element->next = oldElement;


    while (oldElement != NULL)
    {
        oldElement->index++;

        oldElement = oldElement->next;
    }
    array->currectCount++;
  
    return index;
}
