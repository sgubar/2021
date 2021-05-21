#include <stdio.h>
#include "tree_of_char.h"

int main() {
	CharTree *tree = createCharTree();
	insertCharSumbolToTree(tree, 'A');
	insertCharSumbolToTree(tree, 'X');
	insertCharSumbolToTree(tree, 'B');
	insertCharSumbolToTree(tree, 'W');
	insertCharSumbolToTree(tree, 'Q');
	insertCharSumbolToTree(tree, 'R');
	insertCharSumbolToTree(tree, 'E');
	insertCharSumbolToTree(tree, 'L');
	printTree(tree);
	printf("\n");
	deleteNodeWithSumbol(tree, 'Q');
	printTree(tree);

	delateCharTree(tree);


	printf("Hello, World!\n");
	return 0;
}
