#include <stdio.h>
#include "tree.h"

int main() {
	DoubleTree *tree = createDoubleTree();
	insertDoubleValueToTree(tree, 5.3);
	insertDoubleValueToTree(tree, 3.0);
	insertDoubleValueToTree(tree, 1.4);
	insertDoubleValueToTree(tree, 9);
	insertDoubleValueToTree(tree, 2.3);
	insertDoubleValueToTree(tree, 3.9);
	insertDoubleValueToTree(tree, 3.5);
	insertDoubleValueToTree(tree, 4.3);
	printTree(tree);
	printf("\n");
	deleteNodeWithValue(tree, 3.0);
	printTree(tree);

	delateDoubleTree(tree);


	printf("Hello, World!\n");
	return 0;
}
