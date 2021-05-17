#include "tree.h"

int main(void)
{
	Tree* tree1 = createTree();
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
	printf("\n");

	deleteNodeWithValue(tree1, 7.34);
	printTree(tree1);
	printf("Count of elements: %i\n", tree1->count);
	destroyTree(tree1);
}
