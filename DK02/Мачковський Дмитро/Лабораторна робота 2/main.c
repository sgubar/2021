#include <stdio.h>
#include "singlelist.h"


int main(int argc, const char* argv[])
{

	IntSingleList* list = createIntSingleList();

	addIntValueToIntSingleList(list, 1);
	addIntValueToIntSingleList(list, 3);
	addIntValueToIntSingleList(list, 5);
	addIntValueToIntSingleList(list, 4);
	addIntValueToIntSingleList(list, 6);
	addIntValueToIntSingleList(list, 7);
	addIntValueToIntSingleList(list, 0);

	printIntSingleList(list);

	printf("Select a value to double\n");

	int s;
	do {

		printf("Enter a value from 1 to 7\n");
		scanf_s("%d", &s);
	}while(s > 8 || s < 0);

	doubleValueFromUser(list, s);
	printIntSingleList(list);

\

	deleteIntSingleList(list);
	return 0;
}
