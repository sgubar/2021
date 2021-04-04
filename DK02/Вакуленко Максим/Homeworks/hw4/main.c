#include<stdio.h>
#include "list.h"

int main() {
	List* test = createList();
	printf("1/n");
	addIntToList(test, 0);
	addIntToList(test, 1);
	addIntToList(test, 2);
	addIntToList(test, 3);
	addIntToList(test, 4);
	addIntToList(test, 5);
	addIntToList(test, 6);
	addIntToList(test, 7);
	addIntToList(test, 8);
	printIntSingleList(test);

	printf("2/n");
	removeFirstElementFromIntList(test);
	removeLastElementFromList(test);
	printIntSingleList(test);
	printf("3/n");

	insertElementToListByIndex(test, 1, 10);
	removeElementFromListByIndex(test, 2);
	printIntSingleList(test);
	
	

	deleteList(test);

}