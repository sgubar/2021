#pragma once
#ifndef floatTree_h
#define floatTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __tagNode
{
	float value;
	struct __tagNode* leftChild;
	struct __tagNode* rightChild;
} FloatNode;

typedef struct __tagTree
{
	FloatNode* root;
	int count;
} FloatTree;

// interface
FloatTree* createFloatTree();
void destroyFloatTree(FloatTree* aTree);

void insertFloatValueToTree(FloatTree* aTree, float aValue);
FloatNode* findNodeWithValue(FloatTree* aTree, float aValue);
void deleteNodeWithValue(FloatTree* aTree, float aValue);

void printTree(FloatTree* aTree);

#endif /* tree_h */
