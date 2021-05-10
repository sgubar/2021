#include "CharTree.h"

int main(void)
{
	charTree* Symbol = createCharTree();

	insertCharToTree(Symbol, 'A');
	insertCharToTree(Symbol, 'B');
	insertCharToTree(Symbol, 'D');
	insertCharToTree(Symbol, 'F');
	insertCharToTree(Symbol, 'G');
	insertCharToTree(Symbol, 'R');

	printTree(Symbol);
	printf("\n");

	deleteNodeWithValue(Symbol, 'F');
	printTree(Symbol);

	destroyCharTree(Symbol);
}
