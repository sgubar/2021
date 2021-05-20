#pragma warning(disable : 4996)
#include <stdio.h>
#include "btree.h"

int main() {
	T_Tree* tree = CreateTree();
	printf("Tree was created\n");
	InsertNode(tree, 20);
	printf("First node was inserted\n");
	for (char value = -100; value < 101; value += 10) {
		InsertNode(tree, value);
	}	
	printf("Tree were initially filled and looks like (symmetric):\n");
	PrintTree(tree, e_Symmetric);
	printf("\n");

	char valueToOperate = 0;
	int nonValidated = 0;
	do {
		int selection;
		printf("Enter operation type:\n1 - Insert to tree\n2 - Find in tree\n3 - Delete from tree\n0 - Print final tree and exit\n");
		scanf("%d", &selection);
		switch (selection) {
			case 1:
				printf("Enter value to insert in range [-127;127]:\n");
				scanf("%d", &nonValidated);
				if ((-127 > nonValidated) || (127 < nonValidated)) {
					printf("Entered value is out of possible range.\n");
					break;
				}
				valueToOperate = nonValidated;
				if (NULL == InsertNode(tree, valueToOperate)) {
					printf("Error inserting node to tree\n");
					break;
				}
				break;
			case 2:
				printf("Enter value to search in tree in range [-127;127]:\n");
				scanf("%d", &nonValidated);
				if ((-127 > nonValidated) || (127 < nonValidated)) {
					printf("Entered value is out of possible range.\n");
					break;
				}
				valueToOperate = nonValidated;
				T_Node* foundNode = FindNode(tree, valueToOperate);
				if (NULL != foundNode) {
					printf("Found node value: %d\n", foundNode->value);
				} else {
					printf("Can't find %d in tree\n", valueToOperate);
				}
				break;
			case 3:
				printf("Enter value to delete from map in range [-127;127]:\n");
				scanf("%d", &nonValidated);
				if ((-127 > nonValidated) || (127 < nonValidated)) {
					printf("Entered value is out of possible range.\n");
					break;
				}
				valueToOperate = nonValidated;
				DeleteNode(tree, valueToOperate);
				break;
			case 0:
				break;
			default:
				printf("Incorrect operation, try again.\n");
		}
		if (0 == selection) {
			break;
		}
	} while (1);

	

	//DeleteNode(tree, 45);
	//DeleteNode(tree, 100);

	/* printf("Final tree preorder\n");
	PrintTree(tree, e_Preorder);
	printf("\n"); */

	printf("Final tree symmetric\n");
	PrintTree(tree, e_Symmetric);
	printf("\n");

	printf("Final tree postorder\n");
	PrintTree(tree, e_Postorder);
	printf("\n");

    DestroyTree(tree);
    return 0;
}
