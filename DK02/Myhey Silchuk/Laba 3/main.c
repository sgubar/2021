#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {

	CharTree *tree = createTree();
	PutElementToTheTree(tree, 'q');
	PutElementToTheTree(tree, 'b');
	PutElementToTheTree(tree, 'd');
	PutElementToTheTree(tree, 'c');
	PutElementToTheTree(tree, 'h');
	PutElementToTheTree(tree, 'a');

	char greck = 'A';
	long y = (int)greck;
	printf("Greck = %d\n", y);

	printTree(tree);

delTreeElement(tree, 'c');

printTree(tree);
freeTree(tree);
	return 0;
}
