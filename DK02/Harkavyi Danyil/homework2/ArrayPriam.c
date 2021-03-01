#include "ArrayPriam.h"
#include <stdlib.h>

PriamArray* createPriamArray(void) {
	PriamArray* number = (PriamArray*)calloc(maxnumber, sizeof(PriamArray));
	return number;
}

int counterpriamokut(PriamArray* number) {
	if (NULL == number) {
		return 0;
	}

	int counter = 0;
	for (counter = 0; counter < maxnumber; counter++) {
		if (number->priamokut[counter] == NULL) {
			break;
		}
	}
	return counter;
}

void addPriamToArray (PriamArray* number, Priam* pri) {
	if (NULL == number || NULL == pri) {
		return;
	}
	int counter = counterpriamokut(number);
	if (counter < maxnumber) {
		number->priamokut[counter] = pri;
		counter++;
	}
	return counter;
}

void printPriamArray(PriamArray* number) {
	if (NULL == number) {
		return;
	}

	for (int i = 0; i < maxnumber && number->priamokut[i] ; i++) {
		printPriam(number->priamokut[i]);

		if ((i + 1) < maxnumber && number->priamokut[i]) {
			printf("--");
		}
	}
	//printf("\n");
}

double FullploshaPriam(PriamArray* number) {
	if (NULL == number) {
		return;
	}

	long sum = 0;
	for (int i = 0; i < maxnumber && number->priamokut[i]; i++) {
		sum += ploshaPriam(number->priamokut[i]);
	}
	return sum;
}

void deletePriamArray(PriamArray* number) {
	if (NULL != number) {
		for (int i = 0; i < maxnumber && number->priamokut[i]; i++) {
			deletePriam(number->priamokut[i]);
		}
		free(number);
	}
}