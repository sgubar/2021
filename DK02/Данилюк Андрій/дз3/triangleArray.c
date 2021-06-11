#include "triangleArray.h"
#include <stdlib.h>
#include <string.h>


TriangleArray* createTriangleArray(int preservedCount) {
	TriangleArray* array = (TriangleArray*)malloc(sizeof(TriangleArray));

	if (NULL != array) {
		array->count = (preservedCount > 0) ? preservedCount : 1;
		array->storage = (Triangle**)malloc(sizeof(Triangle*) * array->count);
		memset(array->storage, 0, sizeof(Triangle*) * array->count);

	}

	return array;
}

Triangle* getTriangleAtIndex(TriangleArray* ts, int index) {
	if (NULL == ts || index < 0 || index >= ts->count) {
		return NULL;
	}

	return ts->storage[index];
}

int setTriangleAtIndex(TriangleArray* ts, Triangle* value, int index) {
	if (NULL == ts || index < 0) {
		return TriangleArrayError;
	}

	long a = reallocateInternalStorage(ts, index + 1);
	int b = TriangleArrayError;

	if (index >= ts->count) {
		if (b == a) {
			return TriangleArrayError;
		}
	}

	ts->storage[index] = value;
	return index;
}

int countTriangles(TriangleArray* ts) {
	if (NULL == ts) {
		return TriangleArrayError;
	}

	return ts->count;
}

void addTriangleToTriangleArray(TriangleArray* ts, Triangle* value) {
	if (NULL == ts || NULL == value) {
		return;
	}

	int count = countTriangles(ts);
	setTriangleAtIndex(ts, value, count);
}

void printTriangleArray(TriangleArray* ts) {
	if (NULL == ts) {
		return;
	}

	for (int i = 0; i < ts->count; i++) {
		if (ts->storage[i] != NULL) {
			printf("\n");
			printTriangle(ts->storage[i]);
		}
		else {
			printf("NULL");
		}

		if (i < (ts->count - 1)) {
			printf(",");
		}
	}
	printf("\n\n");
	return;
}

void deleteTriangleArreay(TriangleArray* ts) {
	if (NULL != ts) {
		if (NULL != ts->storage) {
			free(ts->storage);
		}

		free(ts);
	}
}

long reallocateInternalStorage(TriangleArray* ts, int requestedCount) {
	if (ts->count >= requestedCount) {
		return ts->count;
	}

	int count = requestedCount * 2;
	Triangle** storage = (Triangle**)malloc(sizeof(Triangle*) * count);
	if (NULL == storage) {
		return TriangleArrayError;
	}

	memset(storage, 0, sizeof(Triangle*) * count);
	memcpy(storage, ts->storage, requestedCount);
	free(ts->storage);

	ts->storage = storage;
	ts->count = count;

	return count;
}
