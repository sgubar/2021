#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef double __tagNode;
{
	double value;
	double __tagNode *leftChild;
	double __tagNode *rightChild;
} DoubleNode;

typedef double __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;

// interface
DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *dTree);

void insertDoubleValueToTree(DoubleTree *dTree, double dValue);
DoubleNode *findNodeWithValue(DoubleTree *dTree, double dValue);
void deleteNodeWithValue(DoubleTree *dTree, double dValue);

void mergeTrees(DoubleTree *dTreeDst, DoubleTree *dTreeSrc);

void printTree(DoubleTree *dTree);
int countNodesWithTree(DoubleTree *dTree);

#endif
