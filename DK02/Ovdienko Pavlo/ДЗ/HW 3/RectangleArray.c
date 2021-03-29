#include "RectangleArray.h"



RectangleArray* createRectangleArray(long countOfArray) {
	RectangleArray* array = (RectangleArray*)malloc(sizeof(RectangleArray));

	if (NULL != array) {
		array->countz = (countOfArray > 0) ? countOfArray : 1;
		array->storage = (Rectangle**)malloc(sizeof(Rectangle*) * array->countz);
		memset(array->storage, 0, sizeof(Rectangle*) * array->countz);
	}
	return array;
}

void addRectangleToRectangleArray(RectangleArray* array, Rectangle* rec) {
	if (NULL == array || NULL == rec) {
		return;
	}

	long komirki = countOfRectangles(array);
	setRectangleAtIndex(array, rec, (komirki));

}

int setRectangleAtIndex(RectangleArray* array, Rectangle* value, int index) {
	if (NULL == array || index < 0) {
		return IndexError;
	}

	long make = reallocateInternalStorage(array, index + 1);
	int XD = IndexError;

	if (index >= array->countz) {
		if (XD == make) {
			return IndexError;
			}
	}

	array->storage[index] = value;
	return index;
}

Rectangle* getRectangleAtIndex(RectangleArray* array, int index) {
	if (NULL == array || index < 0 || index >= array->countz) {
		return NULL;
	}

	return array->storage[index];
}

void printRectangleArray(RectangleArray* array) {
	if (NULL == array) {
		return;
	}

	for (int i = 0; i < array->countz; i++) {
		if (array->storage[i] != NULL) {
			printRectangle(array->storage[i]);
		}
		else {
			printf("NULL");
		}

		if (i < (array->countz - 1)) {
			printf(",");
		}
	}
	printf("\n");

}

long countOfRectangles(RectangleArray* array) {
	 if (NULL == array) {
		return 0;
	 }
	 return array->countz;
}

long reallocateInternalStorage(RectangleArray* array, int requestedCount) {
	if (array->countz >= requestedCount) {
		return array->countz;
	}
	int count = requestedCount * 2;
	Rectangle** storage = (Rectangle**)malloc(sizeof(Rectangle*) * count);
	if (NULL == storage) {
		return IndexError;
	}
	memset(storage, 0, sizeof(Rectangle*) * count);
	memcpy(storage, array->storage, requestedCount);
	free(array->storage);
	array->storage = storage;
	array->countz = count;
	return count;
}

void deleteRectangleArray(RectangleArray* array) {
	if (NULL != array) {
		if (NULL != array->storage) {
			/*for (int i = 0; i < array->countz; i++) {*/
				free(array->storage);
			//}
		}
		free(array);
		}
	}
