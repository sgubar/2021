

#define Tree_h
#ifdef Tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __tagNode
{
	int value;
	struct __tagNode* leftChild;
	struct __tagNode* rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode* root;
	int count;
} IntTree;

IntTree* createIntTree();
void destroyIntTree(IntTree* tree);
void insertIntValueToTree(IntTree* tree, int element);
IntNode* findNodeWithValue(IntTree* tree, int element);
void deleteNodeWithTree(IntTree* tree, int element);

#endif