#include <stdio.h>

#include "btree.h"

int main() {

	T_Tree* tree = CreateTree();
	printf("Tree was created\n");
	InsertNode(tree, 20);
	printf("First node was inserted\n");
	for (char value = 0; value < 56; value += 5) {
		InsertNode(tree, value);
	}
	for (char value = 18; value < 49; value += 3) {
		InsertNode(tree, value);
	}
	printf("Tree were filled\n");
	PrintTree(tree);
	printf("\n");

	T_Node* foundNode = FindNode(tree, 20);
	if (NULL != foundNode) {
		printf("Found node value: %d\n", foundNode->value);
	}

	DeleteNode(tree, 45);

	printf("Final tree\n");
	PrintTree(tree);
	printf("\n");

    DestroyTree(tree);
    return 0;
}
