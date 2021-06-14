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
} DTree;

DTree* createDTree(void);
void destroyDoubleTree(DTree* aTree);
void insertDoubleValueToTree(DTree* aTree, double aValue);
DoubleNode* findNodeWithValue(DTree* aTree, double aValue);
void deleteNodeWithValue(DTree* aTree, double aValue);
void printTree(DTree* aTree);


#endif
