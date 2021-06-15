#pragma once
#ifndef intTree_h
#define intTree_h

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

// interface
IntTree* createIntTree();
void destroyIntTree(IntTree* aTree);

void insertIntValueToTree(IntTree* aTree, int aValue);
IntNode* findNodeWithValue(IntTree* aTree, int aValue);
void deleteNodeWithValue(IntTree* aTree, int aValue);

void printTree(IntTree* aTree);

#endif /* tree_h */
