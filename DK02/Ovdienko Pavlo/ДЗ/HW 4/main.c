#include "List.h"

int main(int argc, const char* argv[]) {


	IntListOne *wow = createIntList();
	printIntList(wow);
		addIntValueToIntList(wow, 2);
		addIntValueToIntList(wow, 3);
		addIntValueToIntList(wow, 9);
		addIntValueToIntList(wow, 1);
	printf("%i\n", countOfIntList(wow));
	printIntList(wow);
		removeLastElementFromList(wow);
		removeFirstElementFromList(wow);
	printf("%i\n", countOfIntList(wow));
	printIntList(wow);
		insertIntElementToIntListAtIndex(wow, 1, 24);
		removeIntElementFromIntListAtIndex(wow, 2);
	printf("%i\n", countOfIntList(wow));
	printIntList(wow);
	deleteIntList(wow);
}