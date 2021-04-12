#ifndef tree_h
#define tree_h
#include <stdio.h>

typedef struct tagNode
{
	int value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
} IntNode;

typedef struct tagTree
{
	IntNode* root;
	int count;
} IntTree;


IntTree* createIntTree();

void destroyIntTree(IntTree* aTree);

void insertIntValueToTree(IntTree* aTree, int aValue);

IntNode* findNodeWithValue(IntTree* aTree, int aValue);

void deleteNodeWithValue(IntTree* aTree, int aValue);


void printTree(IntTree* aTree);

int countNodesWithTree(IntTree* aTree);

#endif
