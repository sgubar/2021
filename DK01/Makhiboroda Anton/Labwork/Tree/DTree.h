#ifndef DTree_h
#define DTree_h

#include <stdio.h>

typedef struct tagNode
{
	double value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
} DNode;

typedef struct tagTree
{
	DNode* root;
	int count;
} DTree;

DTree* createDTree(void);
void destroyDTree(DTree* aTree);
void insertDoubleValueToTree(DTree* aTree, double aValue);
DNode* findNodeWithValue(DTree* aTree, double aValue);
void deleteNodeWithValue(DTree* aTree, double aValue);
void printTree(DTree* aTree);


#endif
