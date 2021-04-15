#include <stdio.h>
#include <string.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	CharTree *tree = createCharTree();
	insertCharSumbolToTree(tree, 'A');
	insertCharSumbolToTree(tree, 'B');
	insertCharSumbolToTree(tree, 'C');
	insertCharSumbolToTree(tree, 'D');
	insertCharSumbolToTree(tree, 'E');
	insertCharSumbolToTree(tree, 'F');
	insertCharSumbolToTree(tree, 'K');
	insertCharSumbolToTree(tree, 'L');
	printTree(tree);
	printf("\n");
	deleteNodeWithSumbol(tree, 'M');
	printTree(tree);

	delateCharTree(tree);


	printf("Hello, World!\n");
	return 0;
}
