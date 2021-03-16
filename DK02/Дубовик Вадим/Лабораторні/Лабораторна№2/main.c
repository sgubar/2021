#include "list.h"

int main(void)
{
	int amountOfElements;
	pListEl listEl = NULL;
	pList list = NULL;
	printf("Please, enter the lenght of your list.\n ");
	list = createListWithXEl(amountOfElements = getNum());
	printList(list);

	deleteFirstElLessThanValue(list, findAverage(list));
	printList(list);
}