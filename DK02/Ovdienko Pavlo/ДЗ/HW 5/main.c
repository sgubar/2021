#include "Tree.h"

int main(int argc, const char* argv[]) {

	IntTree* rev = createIntTree();
	insertIntValueToTree(rev, 53);
	insertIntValueToTree(rev, 30);
	insertIntValueToTree(rev, 14);
	insertIntValueToTree(rev, 9);
	insertIntValueToTree(rev, 23);
	insertIntValueToTree(rev, 39);
	insertIntValueToTree(rev, 35);
	insertIntValueToTree(rev, 43);
	printTree(rev);
	deleteNodeWithTree(rev, 39);
	findNodeWithValue(rev, 35);
	printTree(rev);
	destroyIntTree(rev);
}