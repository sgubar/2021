#include "floatTree.h"

int main(void)
{
	FloatTree* T = createFloatTree();

	insertFloatValueToTree(T, 119.4);
	insertFloatValueToTree(T, 82.67);
	insertFloatValueToTree(T, 11.00);
	insertFloatValueToTree(T, 90.12);
	insertFloatValueToTree(T, 30.29);
	insertFloatValueToTree(T, 55.55);
	insertFloatValueToTree(T, 66.66);
	insertFloatValueToTree(T, 11.11);

	printTree(T);
	printf("\n");

	deleteNodeWithValue(T, 30.29);
	printTree(T);

	destroyFloatTree(T);
}
