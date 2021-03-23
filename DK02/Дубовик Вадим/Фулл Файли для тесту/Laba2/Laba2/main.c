#include "list.h"

int main(void)
{

	int amountOfElements;
	
	printf("Please, enter the lenght of your list.\n ");
	pList list = createListWithXEl(amountOfElements = getNum());
	printList(list);

	deleteFirstElLessThanValue(list, findAverage(list));
	printList(list);
}