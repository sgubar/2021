
#include "Ellipse.h"
#include "ArrayEllipseHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long reallocateInternalStorage(ArrayEllipse *a, int req);

ArrayEllipse *createArrayEllipse(long preservedCount) {
    ArrayEllipse *array = (ArrayEllipse *) malloc(sizeof(ArrayEllipse));
    if (array != NULL) {

        array->storage = (Ellipse **) malloc(sizeof(Ellipse *) * ((preservedCount > 0) ? preservedCount : 1));
        memset(array->storage,0,sizeof(Ellipse*)*preservedCount);

    }
    array->count=0;
    return array;
}

void deleteArrayEllipse(ArrayEllipse *a) {
    if (a != NULL) {
        if (a->storage != NULL) {

            free(a->storage);
        }
        free(a);
    }
}

int setEllipsetAtIndex(ArrayEllipse *a, Ellipse *value, int index) {
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
        //!Збільшуємо кількість елементів у колекції, а не індекс елементів.
        a->count++;

    }
    a->storage[index] = value;
}

void printArrayEllipse(ArrayEllipse *a) {
    for (int x = 0; x < a->count; x++) {
        if (!(a->storage[x] == NULL)) {
            printEllipse(a->storage[x]);
            printf("\n");
        }
        printf("Null");
    }
    printf("\n");
}

long countArrayEllipse(ArrayEllipse *a) {
    if (a == NULL) {
        return ArrayNullPointerException;
    }
    return a->count;
}

long reallocateInternalStorage(ArrayEllipse *a, int req) {
    if (a->count >= req) {
        return a->count;
    }
    long count_ = req * 2;
    Ellipse **new_storage = (Ellipse **) malloc(sizeof(Ellipse *) * count_);
    if (new_storage == NULL) {
        return ArrayNullPointerException;
    }
    //memset(new_storage,sizeof(Point*) * req);
    memcpy(new_storage, a->storage, sizeof(Ellipse *) * count_);
    free(a->storage);
    a->storage = new_storage;
    return req;
}

int addNewEllipseToArray(ArrayEllipse *a, Ellipse *value) {

    if (NULL == a || NULL == value) {
        return ArrayNullPointerException ;
    }

    //!Збільшуємо кількість елементів у колекції, а не індекс елементів.
    a->count = a->count+1;
    setEllipsetAtIndex(a, value, countArrayEllipse(a)-1);


    return a->count;
}