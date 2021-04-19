#pragma once
#define tree_h
#ifdef tree_h
#include <stdio.h>
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
} 


IntTree;

IntTree* createIntTree();
void destroyIntTree(IntTree* tree);
void insertIntValueToTree(IntTree* tree, int aValue);
void printIntTree(IntTree* tree);
IntNode* findNode(IntTree* tree, int aValue);
void deleteNodeWithValue(IntTree* tree, int aValue);



#endif