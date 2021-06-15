#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
	
  DoubleList *l = createDoubleList();

	printDoubleList(l);

  addDoubleValueToDoubleList(l, 'A');
	printDoubleList(l);

	addDoubleValueToDoubleList(l, 'B');
	printDoubleList(l);

  addDoubleValueToDoubleList(l, 'C');
	printDoubleList(l);

  addDoubleValueToDoubleList(l, 'D');
	printDoubleList(l);

  addDoubleValueToDoubleList(l, 'F');
	printDoubleList(l);

  removeLastElementFromDoubleList(l);
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
