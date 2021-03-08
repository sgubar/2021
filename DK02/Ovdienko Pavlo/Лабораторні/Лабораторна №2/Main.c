#include "myfunction.h"

int main()
{
	int x;
	srand(time(NULL));
	do {
		printf("Vvedite razmernost lista:");
		scanf_s("%d", &x);
	} while (x < 0 || x>10);

	IntList* mylist = createIntList();
	for (int i = 0; i <= x; i++) {
		addIntValueToIntList(mylist, rand() % 20 - 10);
	}
	printIntList(mylist);
	removeLastElementFromIntList(mylist);
	removeFirstElementFromIntList(mylist);
	removeIntElementFromIntListAtIndex(mylist, 3);
	insertIntElementToIntListAtIndex(mylist, 7, 10);
	printIntList(mylist);
	printf("%d\n", MaxmimumElementOfList(mylist));
	sortElementsOfList(mylist, x);
	printIntList(mylist);
	deleteIntList(mylist);
}
