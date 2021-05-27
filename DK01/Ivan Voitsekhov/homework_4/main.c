#include <stdio.h>
#include <stdlib.h>
#include "char_list.h"
int main()
{
   CharList *list = createCharList();

	printCharList(list);

	addCharSumbolToCharList(list, 'a');
	printCharList(list);

	addCharSumbolToCharList(list, 'b');
	printCharList(list);

	addCharSumbolToCharList(list, 'c');
	printCharList(list);

    addCharSumbolToCharList(list, 'd');
	printCharList(list);

	insertCharElementToCharListAtIndex(list,3,'e');
	printCharList(list);

	removeCharElementFromCharListAtIndex(list,4);
	printCharList(list);

	removeFirstElementFromCharList(list);
	printCharList(list);

	removeLastElementFromCharList(list);
	printCharList(list);

    deleteCharList(list);
    printf("Hello world!\n");
    return 0;
}
