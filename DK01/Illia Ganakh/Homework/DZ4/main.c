#include <stdio.h>
#include "signle_list.h"

int main(void) {

	charSingleList *list = createcharSingleList();

	printcharSingleList(list);

	addcharValueTocharSingleList(list, 'a');
	printcharSingleList(list);

	addcharValueTocharSingleList(list, 'b');
	printcharSingleList(list);

  addcharValueTocharSingleList(list, 'd');
	printcharSingleList(list);

  printf("список має %ld елемента/елементів\n", countOfcharSingleList(list));

  removecharElementFromcharSingleListAtIndex(list, 1);
  insertcharElementTocharSingleListAtIndex(list, 1, 'c');//заміна елементу
  printcharSingleList(list);

	removeFirstElementFromcharSingleList(list);
	printcharSingleList(list);

  removeFirstElementFromcharSingleList(list);
  printcharSingleList(list);
  deletecharSingleList(list);
}