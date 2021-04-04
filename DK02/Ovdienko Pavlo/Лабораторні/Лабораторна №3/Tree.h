

#define Tree_h
#ifdef Tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __tagNode
{
	double value;
	struct __tagNode* leftChild;
	struct __tagNode* rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode* root;
	int count;
} DoubleTree;

DoubleTree* createDoubleTree();
void destroyDoubleTree(DoubleTree* tree);
void insertDoubleValueToTree(DoubleTree* tree, double DDDdouble);
void printTree(DoubleTree* tree);
DoubleNode* findNodeWithValue(DoubleTree* tree, double DDDdouble);
void deleteNodeWithTree(DoubleTree* tree, double DDDdouble);

#endif