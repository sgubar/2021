#include "KoloArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reallocateStorage(T_KoloArray* array_, unsigned int expansion_);

T_KoloArray* CreateKoloArray(unsigned int count_) {
    unsigned int realCount = (count_ == 0) ? 1 : count_;
    T_KoloArray* newArray = (T_KoloArray*)malloc(sizeof(T_KoloArray));
    if (NULL == newArray) {
        return NULL;
    }
    newArray->arrayData = (Kolo**)malloc(sizeof(Kolo*) * realCount);
    if (NULL == newArray->arrayData) {
        free(newArray);
        return NULL;
    }
    memset(newArray->arrayData, 0, sizeof(Kolo*) * realCount);
    newArray->count = realCount;
    return newArray;
}

void DeleteKoloArray(T_KoloArray* array_) {
    if (NULL != array_) {
        if (NULL != array_->arrayData) {
            free(array_->arrayData);
        }
        free(array_);
    }
    return;
}

int InsertKoloToArray(T_KoloArray* array_, Kolo* element_) {
    if ((NULL == array_) || (NULL == element_)) {
        return -1;
    }
    int elementNum = 0;
    for (; elementNum < array_->count; ++elementNum) {
        if (array_->arrayData[elementNum] == NULL) {
            array_->arrayData[elementNum] = element_;
            return elementNum;
        }
    }
	if (-1 == reallocateStorage(array_, 1)) {
		return -1;
	}
    array_->arrayData[elementNum] = element_;
    return elementNum;
}

int InsertKoloToArrayByIndex(T_KoloArray* array_, Kolo* element_, unsigned int index_) {
    if ((NULL == array_) || (NULL == element_)) {
        return -1;
    }

    if (index_ >= array_->count) {
        if (-1 == reallocateStorage(array_, index_ - array_->count + 1)) {
            return -1;
        }
    } 
    array_->arrayData[index_] = element_;
    return index_;
}

void PrintKoloArray(T_KoloArray* array_) {
    if (NULL == array_) {
        printf("KoloArray is empty\n");
        return;
    }
    for (unsigned int elementNum = 0 ; elementNum < array_->count; ++elementNum) {
        if (array_->arrayData[elementNum] != NULL) {
            printKolo(array_->arrayData[elementNum]);
        } else {
            printf("Element #%u is empty\n", elementNum);
        }
    }
	printf("\n");
}

int reallocateStorage(T_KoloArray* array_, unsigned int expansion_) {
	if (NULL == array_) {
		return -1;
	}
	if (0 == expansion_) {
		return array_->count;
	}

	unsigned int newCount = array_->count + expansion_;
	Kolo** newStorage = (Kolo **)malloc(sizeof(Kolo*) * newCount);
	if (NULL == newStorage) {
		printf("Error: memory allocation\n");
		return -1;
	}
	memset(newStorage, 0, sizeof(Kolo*) * newCount);
	memcpy(newStorage, array_->arrayData, sizeof(Kolo*) * array_->count);

	free(array_->arrayData);

    array_->arrayData = newStorage;
    array_->count = newCount;

    return newCount;
}