#include "Array.h"

long reallocateArray(arrayTriangle* a, int req);

arrayTriangle* makeArray(long count) {
    arrayTriangle* array = (arrayTriangle*)malloc(sizeof(arrayTriangle));
    if (array != NULL) {

        array->storage = (triangle**)malloc(sizeof(triangle*) * ((count > 0) ? count : 1));
        memset(array->storage, 0, sizeof(triangle*) * count);

    }
    array->count = 0;
    return array;
}

void deleteArray(arrayTriangle* a) {
    if (a != NULL) {
        if (a->storage != NULL) {

            free(a->storage);
        }
        free(a);
    }
}

int putTriangleAtIndex(arrayTriangle* a, triangle* value, int index) {
    if (a == NULL || value == NULL) {
        printf("Error, ArrayPointer is NULL");
        return -1;
    }
    if (index < 0) {
        printf("Error, Index is less than zero");
        return -1;
    }
    if (index >= a->count) {

        if (-1 == reallocateArray(a, index + 1)) {
            printf("Error, ArrayPointer is NULL");
            return -1;
        }

        a->count++;

    }
    a->storage[index] = value;
}

void printArray(arrayTriangle* a) {
    for (int x = 0; x < a->count; x++) {
        if (!(a->storage[x] == NULL)) {
            printTriangle(a->storage[x]);
            printf("\n");
        }

    }
    printf("\n");
}

long countArray(arrayTriangle* a) {
    if (a == NULL) {
        printf("Error, ArrayPointer is NULL");
        return -1;
    }
    return a->count;
}

long reallocateArray(arrayTriangle* a, int req) {
    if (a->count >= req) {
        return a->count;
    }
    long count_ = req * 2;
    triangle** new_storage = (triangle**)malloc(sizeof(triangle*) * count_);
    if (new_storage == NULL) {
        printf("Error, ArrayPointer is NULL");
        return -1;
    }

    memcpy(new_storage, a->storage, sizeof(triangle*) * count_);
    free(a->storage);
    a->storage = new_storage;
    return req;
}

int addTriangleToArray(arrayTriangle* a, triangle* value) {

    if (NULL == a || NULL == value) {
        printf("Error, ArrayPointer is NULL");
        return -1;
    }


    a->count = a->count + 1;
    putTriangleAtIndex(a, value, countArray(a) - 1);


    return a->count;
}
