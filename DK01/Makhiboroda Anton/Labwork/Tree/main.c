#include <stdio.h>
#include "DTree.h"

int main(int argc, const char* argv[]) {

	DTree *tree = createDTree();

	insertDoubleValueToTree(tree, 5);
	insertDoubleValueToTree(tree, 3.14);
	insertDoubleValueToTree(tree, 1.41);
	insertDoubleValueToTree(tree, 2.65);
	insertDoubleValueToTree(tree, 3.2);
	insertDoubleValueToTree(tree, 0.99);
	insertDoubleValueToTree(tree, 0.7);
	insertDoubleValueToTree(tree, 0.15);
	insertDoubleValueToTree(tree, 0.2);
	printTree(tree);
	deleteNodeWithValue(tree, 3.1415);
	printTree(tree);

	destroyDTree(tree);

	return 0;
}
