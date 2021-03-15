#include "list.h"

int main(void)
{
	int B = 10;
	int* C = &B;
	
	pListEl A = createListEl(10);
	printf("%d", A->value);
	free(C);
	//deleteListEl(A);



	int amountOfElements;
	pListEl list = NULL;
	printf("Please, enter the lenght of your list.\n ");
	list = createListWithXEl(amountOfElements = getNum());
	printList(list);

	//deleteFirstElLessThanValue(list, findAverage(list));
	//printList(list);
}