#include "CharTree.h"

int main(void)
{
	Tree* X = createCharTree();

	insertCharToTree(X, 3.0);
	insertCharToTree(X, 56.0);
	insertCharToTree(X, 45.6);
	insertCharToTree(X, 28.9);
	insertCharToTree(X, 192.2);
	insertCharToTree(X, 0.1);

	printTree(X);
	printf("\n");

	deleteNodeWithValue(X, 3.0);
	printTree(X);

	destroyCharTree(X);
}
