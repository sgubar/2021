#ifndef doubleTree_h
#define doubleTree_h

#include <stdio.h>

typedef struct tagNode
{
	double value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
} DoubleNode;

typedef struct tagTree
{
	DoubleNode* root;
	int count;
} DoubleTree;

DoubleTree* createDoubleTree(void);
void destroyDoubleTree(DoubleTree* aTree);
void insertDoubleValueToTree(DoubleTree* aTree, double aValue);
DoubleNode* findNodeWithValue(DoubleTree* aTree, double aValue);
void deleteNodeWithValue(DoubleTree* aTree, double aValue);
void printTree(DoubleTree* aTree);


#endif
