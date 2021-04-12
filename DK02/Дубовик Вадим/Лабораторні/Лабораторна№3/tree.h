#pragma once
#include <stdio.h>
#include <stdlib.h>

#define tree_h
#ifdef tree_h

typedef struct tagNode Node;
struct tagNode
{
	float value;
	Node* Left;
	Node* Right;
};

typedef struct tagTree Tree;
struct tagTree
{
	Node* root;
	int count;
};

// interface
Tree* createTree(void);
void destroyTree(Tree* tree);

void insertValueToTree(Tree* tree, float value);
Node* findNodeWithValue(Tree* tree, float value);
void deleteNodeWithValue(Tree* tree, float value);

void mergeTrees(Tree* aTreeDst, Tree* aTreeSrc);//to merge a tree means to merge  the 1-st and the 2-nd trees and then delete the 1-st

void printTree(Tree* tree);
#endif