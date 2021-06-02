#pragma once
#ifndef CharTree_h
#define CharTree_h

#include <stdio.h>
#include <stdlib.h>


typedef struct __tagNode
{
	double value;
	struct __tagNode* leftChild;
	struct __tagNode* rightChild;
} charNode;

typedef struct __tagTree
{
	charNode* root;
	int count;
} Tree;

// interface
Tree* createCharTree();
void destroyCharTree(Tree* aTree);

void insertCharToTree(Tree* aTree, double aValue);
charNode* findNodeWithValue(Tree* aTree, double aValue);
void deleteNodeWithValue(Tree* aTree, double aValue);

void printTree(Tree* aTree);

#endif /* tree_h */
