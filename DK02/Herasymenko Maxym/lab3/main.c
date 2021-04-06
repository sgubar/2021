#include "Tree.h"
#include <stdio.h>
int main(int argc, const char* argv[])
{
	IntTree *the_tree = createIntTree();
	insertIntValueToTree(the_tree, 67);
	insertIntValueToTree(the_tree, 34);
	insertIntValueToTree(the_tree, 20);
	insertIntValueToTree(the_tree, 12);
	insertIntValueToTree(the_tree, 23);
	insertIntValueToTree(the_tree, 34);
	insertIntValueToTree(the_tree, 25);
	insertIntValueToTree(the_tree, 48);
	findNode(the_tree, 34);
	printIntTree(the_tree);
	deleteNodeWithValue(the_tree, 25);
	deleteNodeWithValue(the_tree, 48);
	printIntTree(the_tree);
	destroyIntTree(the_tree);
}
