#include "list.h"

int main(void)
{
	int amountOfElements;
	pListEl list = NULL;
	printf("Please, enter the lenght of your list.\n ");
	list = createListWithXEl(amountOfElements = getNum());
	printList(list);
	deleteFirstElLessThanValue(list, findAverage(list));
	printList(list);
	//int A = getNum();
	//printf("%d", A);
	//int A;
	//scanf_s("%d", &A);
	//printf("%d", A);
}