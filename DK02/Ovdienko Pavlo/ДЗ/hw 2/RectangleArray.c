#include "RectangleArray.h"

RectangleArray* createRectangleArray(void) {
	RectangleArray* ric = (RectangleArray*)calloc(maxnumbers, sizeof(RectangleArray));
	return ric;
}

int countRectangles(RectangleArray* ris) {
	if (NULL == ris) {
		return 0;
	}

	int count = 0;
	for (count = 0; count < maxnumbers; count++) {
		if (ris->rectangles[count] == NULL) {
			break;
		}
	}
	return count;
}

void addRectangleToRectangleArray(RectangleArray* ris, Rectangle* rec) {
	if (NULL == ris || NULL == rec){
		return;
	}
	int count = countRectangles(ris);
	if (count < maxnumbers) {
		ris->rectangles[count] = rec;
		count++;
	}
	return count;
}

void printRectangleArray(RectangleArray* ris) {
	if (NULL == ris) {
		return;
	}

	for (int i = 0; i < maxnumbers && ris->rectangles[i] != NULL; i++) {
		printRectangle(ris->rectangles[i]);

		if ((i + 1) < maxnumbers && ris->rectangles[i] != NULL) {
			printf("-");
		}
	}
	printf("\n");
}

double FullPerimeterRectangleArray(RectangleArray* ris) {
	if (NULL == ris) {
		return;
	}

	long sumOfperimeters = 0;
	for (int i = 0; i < maxnumbers && ris->rectangles[i] != NULL; i++) {
		sumOfperimeters += perimeterRectangle(ris->rectangles[i]);
	}
	return sumOfperimeters;
}

double FullSquareRectangleArray(RectangleArray* ris) {
	if (NULL == ris) {
		return;
	}

	long sumOfsquares = 0;
	for (int i = 0; i < maxnumbers && ris->rectangles[i] != NULL; i++) {
		sumOfsquares += squareRectangle(ris->rectangles[i]);
	}
	return sumOfsquares;
}

void deleteRectangleArray(RectangleArray* ris) {
	if (NULL != ris) {
		for (int i = 0; i < maxnumbers && ris->rectangles[i] != NULL; i++){
			deleteRectangle(ris->rectangles[i]);
		}
		free(ris);
	}
}
