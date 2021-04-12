#include "tree.h"

int main(void)
{
	/*
	Tree* tree1 = createTree();

	//Inserting elements
	insertValueToTree(tree1, 7.34);
	insertValueToTree(tree1, 8.34);
	insertValueToTree(tree1, 14.34);
	insertValueToTree(tree1, 0.34);
	insertValueToTree(tree1, 23.2);
	insertValueToTree(tree1, 72.4);
	insertValueToTree(tree1, 12.3);
	insertValueToTree(tree1, 0.19);

	
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	//delete node 12.3
	deleteNodeWithValue(tree1, 12.3);
	//Print tree without a node
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	//Kill da tree
	destroyTree(tree1);
	*/

	//creating the 1-st tree
	Tree* tree1 = createTree();

	//giving some values to the 1-st tree 
	insertValueToTree(tree1, 7.34);
	insertValueToTree(tree1, 8.34);
	insertValueToTree(tree1, 14.34);
	insertValueToTree(tree1, 0.34);
	insertValueToTree(tree1, 23.2);
	insertValueToTree(tree1, 72.4);
	insertValueToTree(tree1, 12.3);
	insertValueToTree(tree1, 0.19);

	//printing the 1-st tree
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	printf("\n");

	//creating the 2-nd tree
	Tree* tree2 = createTree();

	//giving some values to the 2-nd tree 
	insertValueToTree(tree2, 9.2);
	insertValueToTree(tree2, 2.1);
	insertValueToTree(tree2, 5.2);
	insertValueToTree(tree2, 4.6);
	insertValueToTree(tree2, 3.4);
	insertValueToTree(tree2, 0.7);
	insertValueToTree(tree2, 12.8);
	insertValueToTree(tree2, 8.9);

	//printing the 2-nd tree
	printTree(tree2);
	printf("Count of elements: %i\n", tree2->count);
	printf("\n");

	//merging trees
	mergeTrees(tree2, tree1);

	//printing the 1-st tree again
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	printf("\n");

	//delete node 7.34
	deleteNodeWithValue(tree1, 7.34);

	//Print tree without a node
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	//Kill da tree
	destroyTree(tree1);
}