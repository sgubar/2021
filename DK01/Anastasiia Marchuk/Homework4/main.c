#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
	
  DoubleList *l = createDoubleList();

	printDoubleList(l);

  addIntValueToDoubleList(l, 'A');
	printDoubleList(l);

	addIntValueToDoubleList(l, 'B');
	printDoubleList(l);

  addIntValueToDoubleList(l, 'C');
	printDoubleList(l);

  addIntValueToDoubleList(l, 'D');
	printDoubleList(l);

  addIntValueToDoubleList(l, 'F');
	printDoubleList(l);

  removeFirstElementFromDoubleList(l);
	printDoubleList(l);

	removeLastElementFromDoubleList(l);
	printDoubleList(l);

  removeLastElementFromDoubleList(l);
	printDoubleList(l);

  removeLastElementFromDoubleList(l);
	printDoubleList(l);

  removeLastElementFromDoubleList(l);
	printDoubleList(l);

	deleteDoubleList(l);
	return 0;
}
