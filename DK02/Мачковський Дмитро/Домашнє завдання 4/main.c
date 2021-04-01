#include <stdio.h>
#include "list.h"


int main(int argc, const char* argv[])
{
	DoubleList* l = createDoubleList();
	printDoubleList(l);

	addDoubleValueToDoubleList(l, 1.321);
	printDoubleList(l);

	addDoubleValueToDoubleList(l, 3.141);
	printDoubleList(l);

	insertDoubleElementToDoubleListAtIndex(l, 1, 2.71);
	printDoubleList(l);

	removeDoubleElementFromDoubleListAtIndex(l, 2);
	printDoubleList(l);

	removeFirstElementFromDoubleList(l);
	printDoubleList(l);

	removeLastElementFromDoubleList(l);
	printDoubleList(l);

	deleteDoubleList(l);
	return 0;
}
