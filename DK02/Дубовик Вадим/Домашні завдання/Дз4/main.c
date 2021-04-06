#include "list.h"
//створення списку, додавання нового елементу до списку, вилучення елементу зі списку, вставка елементу по індексу, видалення списку, розмір списку, вивід списку на екран.
int main(void)
{
	pIntList list = createIntList();
	addIntValueToIntList(list, 23);
	addIntValueToIntList(list, 72);
	addIntValueToIntList(list, 28);

	printIntList(list);

	insertIntElementToIntListAtIndex(list, 3, 100);
	
	printIntList(list);

	removeIntElementFromIntListAtIndex(list, 0);

	removeIntElementFromIntListAtIndex(list, 2);

	printIntList(list);

	deleteIntList(list);
}