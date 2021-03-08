#include "ArrayPriam.h"
#include <stdlib.h>


int main(int argc, const char* argv[]) {

	PriamArray* arr = createPriamArray();

	Priam* first = createPriamByCoordinates(1, 1, 5, 1, 5, 3, 1, 3);
	
	addPriamToArray(arr, first);
	
	Priam* second = createPriamByCoordinates(1, 1, 5, 1, 5, 3, 1, 3);
	
	addPriamToArray(arr, second);

	printPriam(first);

	printf("\n");

	printPriam(second);
	
	printf("\n");


	printf("Equal?: %d\n", isEqualPriam(first, second));

	printf("Summa plosh Priamokutnukiv : %f\n", FullploshaPriam(arr));

	printf("counter: %d\n", counterpriamokut(arr));

	deletePriamArray(arr);
}