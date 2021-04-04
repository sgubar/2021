#include "triangle.h"
#include "ArrayOfTriangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long reallocateInternalStorage(ArrayTriangle *a, int req);

ArrayTriangle *createArrayTriangle(long preservedCount) {
    ArrayTriangle *array = (ArrayTriangle *) malloc(sizeof(ArrayTriangle));
    if (array != NULL) {

        array->storage = (Triangle **) malloc(sizeof(Triangle *) * ((preservedCount > 0) ? preservedCount : 1));
        memset(array->storage,0,sizeof(Triangle*)*preservedCount);

    }
    array->count=0;
    return array;
}

void deleteArrayTriangle(ArrayTriangle *a) {
    if (a != NULL) {
        if (a->storage != NULL) {

            free(a->storage);
        }
        free(a);
    }
}

int TriangleAtIndex(ArrayTriangle *a, Triangle *value, int index) {
    if (a == NULL || value == NULL) {
        return ArrayNullPointerException;
    }
    if (index < 0) {
        return ArrayLessThanZeroIndexError;
    }
    if (index >= a->count) {

        if (ArrayNullPointerException == reallocateInternalStorage(a, index + 1)) {
            return ArrayNullPointerException;
        }

        a->count++;

    }
    a->storage[index] = value;
}

void printArrayTriangle(ArrayTriangle *a) {
    for (int x = 0; x < a->count; x++) {
        if (!(a->storage[x] == NULL)) {
            printTriangle(a->storage[x]);
            printf("\n");
        }

    }
    printf("\n");
}

long countArrayTriangle(ArrayTriangle *a) {
    if (a == NULL) {
        return ArrayNullPointerException;
    }
    return a->count;
}

long reallocateInternalStorage(ArrayTriangle *a, int req) {
    if (a->count >= req) {
        return a->count;
    }
    long count_ = req * 2;
    Triangle **new_storage = (Triangle **) malloc(sizeof(Triangle *) * count_);
    if (new_storage == NULL) {
        return ArrayNullPointerException;
    }

    memcpy(new_storage, a->storage, sizeof(Triangle *) * count_);
    free(a->storage);
    a->storage = new_storage;
    return req;
}

int addNewTriangleToArray(ArrayTriangle *a, Triangle *value) {

    if (NULL == a || NULL == value) {
        return ArrayNullPointerException ;
    }


    a->count = a->count+1;
   TriangleAtIndex(a, value, countArrayTriangle(a)-1);


    return a->count;
}
