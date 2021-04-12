#include <stdio.h>
#include "tree.h"

int main(int argc, const char* argv[]) {

	IntTree* tree = createIntTree();
	insertIntValueToTree(tree, 24);
	insertIntValueToTree(tree, 16);
	insertIntValueToTree(tree, 9);
	insertIntValueToTree(tree, 5);
	insertIntValueToTree(tree, 19);
	insertIntValueToTree(tree, 26);
	insertIntValueToTree(tree, 33);
	insertIntValueToTree(tree, 43);
	insertIntValueToTree(tree, 53);
	insertIntValueToTree(tree, 66);
	printTree(tree);
	deleteNodeWithValue(tree, 5);
	deleteNodeWithValue(tree, 66);
	printf("\n");
	printf("\n");
	printf("\n");
	printTree(tree);
	destroyIntTree(tree);
	return 0;		 
}
