#include "Tree.h"

int main(int argc, const char* argv[]) {

	DoubleTree* rev = createDoubleTree();
	insertDoubleValueToTree(rev, 0.53);
	insertDoubleValueToTree(rev, 0.30);
	insertDoubleValueToTree(rev, 0.14);
	insertDoubleValueToTree(rev, 0.09);
	insertDoubleValueToTree(rev, 0.23);
	insertDoubleValueToTree(rev, 0.39);
	insertDoubleValueToTree(rev, 0.35);
	insertDoubleValueToTree(rev, 0.43);
	printTree(rev);
	deleteNodeWithTree(rev, 0.39);
	printTree(rev);
	destroyDoubleTree(rev);
}