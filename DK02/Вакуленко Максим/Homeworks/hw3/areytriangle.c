#include"areytriangle.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>


long reallocateInternalStorage( Tria* a, int requestedCount);

AreyTria* createAreyTria(long preservedCount){
	AreyTria* t = (AreyTria*)malloc(sizeof(AreyTria));
	if (NULL != t) {
		t->count = (preservedCount > 0) ? preservedCount : 1;
		t->storage = (Tria**)malloc((sizeof(Tria*))*t->count);
		memset(t->storage, 0, sizeof(Tria*)* t->count);
	}
	return t;
}

long countArray(AreyTria * a) {
	if (NULL == a) {
		return -1;
	}

	return a->count;
}
 


int IndexTriaInsert(AreyTria* l, int index, Tria* tria) {
	if (l == NULL || index < 0) {
		return (-1);
	}
	if (index >= l->count) {
		//realocate 
		if (reallocateInternalStorage(l, index + 1) == -1) {
			return (-1);
		}

	}
	l->storage[index] = copyTria(tria);
	return index;
}

Tria* getTriaAtArey(AreyTria* l, int index) {
	if (l == NULL || index < 0 || index >= l->count) {
		return NULL;
	}
	return copyTria(l->storage[index]);
}


void deleteAreyTria(AreyTria* l) {

	 if (NULL != l) {
			for (int i = 0; i < l->count; i++) {
				if (l->storage[i] != NULL) {
					deleteTria(l->storage[i]);
				}
			
			}
			
		}
	free(l);
}


void printAreyTria(AreyTria* l) {
	if (NULL == l) {
		//printf("Print1 done \n");
		return;
	}

	for (int i = 0; i < l->count; i++){
		if (l->storage[i] != NULL) {
			printf("Triagle%d \n", (i));
			printTriange(l->storage[i]);
		}

	}
	if (SumPerimOfArayTria(l) == 0 | SumSqyarefArayTria(l) == 0) {
				return;
			}
	printf("Sum perimeter of all Arrey: %lf\n", SumPerimOfArayTria(l));
	printf("Sum square of all Arrey: %lf\n", SumSqyarefArayTria(l));
	printf("\n\n");
}


double SumPerimOfArayTria(AreyTria* ar) {
	if (NULL == ar) {
		return;
	}
	double perimeter = 0;
	for (int i = 0; i < ar->count && ar->storage[i] != NULL; i++) {
			perimeter += PerimeterOfTriangle(ar->storage[i]);
	}
	return perimeter;
}
double SumSqyarefArayTria(AreyTria* ar) {
	if (NULL == ar) {
		return;
	}
	double Square = 0;
	for (int i = 0; i < ar->count && ar->storage[i] != NULL; i++) {
		Square += SquareOfTriangle(ar->storage[i]);
	}
	return Square;
}

long reallocateInternalStorage(AreyTria * a, int requestedCount) {
	if (a->count >= requestedCount) {
		return a->count;
	}

	int count = requestedCount * 2;

	// reallocate 
	Tria** storage = (Tria**)malloc(sizeof(Tria*) * count);
	if (NULL == storage) {
		return -1;
	}

	memset(storage, 0, sizeof(Tria*) * count);
	memcpy(storage, a->storage, requestedCount);
	
	free(a->storage);
	a->storage = storage;
	a->count = count;
   
	return count;
}