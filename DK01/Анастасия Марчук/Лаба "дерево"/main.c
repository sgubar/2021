#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	DoubleTree *tree = createDoubleTree();
	insertDoubleValueToTree(tree, 'A');
	insertDoubleValueToTree(tree, 'B');
	insertDoubleValueToTree(tree, 'C');
	insertDoubleValueToTree(tree, 'E');
	insertDoubleValueToTree(tree, 'F');
	insertDoubleValueToTree(tree, 'Y');
	insertDoubleValueToTree(tree, 'G');
	insertDoubleValueToTree(tree, 'H');
  printTree(tree);
	printf("\n");
	deleteNodeWithSumbol(tree, 'Q');
	printTree(tree);

	delateDoubleTree(tree);
}
