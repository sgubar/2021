#include "array.h"
#include <stdlib.h>
#include <string.h>

Array *createArray(int maxCount)
{
    Array *result = (Array*)malloc(sizeof(Array));
    if (NULL != result && maxCount > 0)
    {
        result->maxCount = maxCount;
        result->array = (Tria**)malloc(maxCount * sizeof(Tria*));

        for (int i = 0; i < maxCount; i++){

            result->array[i] = NULL;
        }
        //bzero(result->array, sizeof(Tria*) * maxCount);
    }
    return result;
}

void deleteArray(Array *array)
{
    if (NULL == array)
    {
       return;
    }
    if (NULL == array->array){
        return;
    }
    for (int i = 0; i < array->maxCount; i++){
        if (array->array[i]){
            deleteTria(array->array[i]);
        }
    }

    free(array->array);

    free(array);
}
void printArray(Array *array)
{
    if (NULL == array)
    {
        printf("Invalid a pointer to the array\n");

        return;
    }

    for (int i = 0; i < array->maxCount; i++)
    {
        if (NULL != array->array[i]){
            printTriange(array->array[i]);
        }
    }
    printf("\n");
}


int append(Array *array, Tria *value)
{
    if (NULL == array)
    {
        return -1;
    }
    for (int i = 0; i < array->maxCount; i++){
        if (NULL == array->array[i]){
            array->array[i] = value;
            return i;
        }
    }
    return -1;
}

int appendByIndex(Array *array, Tria *value, int index)
{
    if (NULL == array)
    {
        return -1;
    }
    if (index + 1 > array->maxCount || index < 0){
        printf("Index error\n");
       return -1;
    }
    array->array[index] = value;
    return index;
}
