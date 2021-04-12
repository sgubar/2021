#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {

	printf("*** TEST LINKED LIST *** \n");
	
  IntList *l = createIntList();

	printIntList(l);

  addIntValueToIntList(l, 'A');
	printIntList(l);

	addIntValueToIntList(l, 'B');
	printIntList(l);

  addIntValueToIntList(l, 'C');
	printIntList(l);

  addIntValueToIntList(l, 'D');
	printIntList(l);

  addIntValueToIntList(l, 'F');
	printIntList(l);

  removeFirstElementFromIntList(l);
	printIntList(l);

	removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);


  //

  addIntValueToIntList(l, 'A');
	printIntList(l);

	addIntValueToIntList(l, 'B');
	printIntList(l);

  addIntValueToIntList(l, 'C');
	printIntList(l);

  addIntValueToIntList(l, 'D');
	printIntList(l);

  addIntValueToIntList(l, 'F');
	printIntList(l);

  removeFirstElementFromIntList(l);
	printIntList(l);

	removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);

  removeLastElementFromIntList(l);
	printIntList(l);


	deleteIntList(l);
	return 0;
}
