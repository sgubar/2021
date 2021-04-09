#include <stdio.h>
#include "tree.h"

int main(int argc, const char* argv[]) {

	IntTree* tree = createIntTree();

	insertIntValueToTree(tree, 15);

	insertIntValueToTree(tree, 7);

	insertIntValueToTree(tree, 4);

	insertIntValueToTree(tree, 3);

	insertIntValueToTree(tree, 9);

	insertIntValueToTree(tree, 20);

	insertIntValueToTree(tree, 16);

	insertIntValueToTree(tree, 48);

	insertIntValueToTree(tree, 50);

	printTree(tree);

	deleteNodeWithValue(tree, 3);

	deleteNodeWithValue(tree, 50);

	printf("\n");

	printTree(tree);

	destroyIntTree(tree);

	return 0;		 
}
    //			    (15)
	//			   /    \
	//		     (7)   (20)
	//		    /  \    /  \
	//		 (4)   (9) (16) (48)
	//		 /                \
	//	   (3)	              (50)
	//		 
	//		 

