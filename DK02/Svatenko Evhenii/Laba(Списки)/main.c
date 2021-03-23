#include "single_list.h"

int main(void)
{
	int value;
	printf("Vvedit rozmir spisku: ");
	scanf_s("%d", &value);
	single_list* L = create_random_values_list(value);
	printf("Randomnii spisok mae viglyad: \n");
	print_single_list(L);
	printf("\nVidsortovaniy spisok:\n");

	L = sort_elements_ascending(L);
	print_single_list(L);
	delete_single_list(L);
}
