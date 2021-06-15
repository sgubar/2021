#include "intTree.h"

int main(void)
{
	IntTree* T = createIntTree();

	insertIntValueToTree(T, 119);
	insertIntValueToTree(T, 826);
	insertIntValueToTree(T, 110);
	insertIntValueToTree(T, 90);
	insertIntValueToTree(T, 302);
	insertIntValueToTree(T, 555);
	insertIntValueToTree(T, 666);
	insertIntValueToTree(T, 111);

	printTree(T);
	printf("\n");

	deleteNodeWithValue(T, 302);
	printTree(T);

	destroyIntTree(T);
}
