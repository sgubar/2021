#include <stdio.h>
#include "doubleTree.h"

int main(int argc, const char* argv[]) {

	DoubleTree *tree = createDoubleTree();

	insertDoubleValueToTree(tree, 1);
	insertDoubleValueToTree(tree, 3.1415);
	insertDoubleValueToTree(tree, 1.41);
	insertDoubleValueToTree(tree, 2.71);
	insertDoubleValueToTree(tree, 3.333);
	insertDoubleValueToTree(tree, 0.99);
	insertDoubleValueToTree(tree, 0.7);
	insertDoubleValueToTree(tree, 0.16);
	insertDoubleValueToTree(tree, 0.2);
	printTree(tree);
	deleteNodeWithValue(tree, 3.333);
	printTree(tree);

	destroyDoubleTree(tree);

	return 0;
//				(1)
//			   /   \
//		  (0.99)  (3.1415)
//		  /         /    \
//		(0.7)    (1.41)  (3.333)
//		/		     \
//	(0.16)			(2.71)
//		\
//		 (0.2)
}
