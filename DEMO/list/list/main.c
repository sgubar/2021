//
//  main.c
//  list
//
//  Created by Slava Gubar on 01.03.2021.
//

#include <stdio.h>
#include "signle_list.h"

int main(int argc, const char * argv[]) {

	IntSingleList *list = createIntSingleList();

	printIntSingleList(list);

	addIntValueToIntSingleList(list, 5);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 6);
	printIntSingleList(list);

	removeFirstElementFromIntSingleList(list);
	printIntSingleList(list);

	removeLastElementFromIntSingleList(list);
	printIntSingleList(list);

	// insert code here...
	printf("Hello, World!\n");

	deleteIntSingleList(list);
	return 0;
}
