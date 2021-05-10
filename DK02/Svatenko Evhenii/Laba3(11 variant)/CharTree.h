#pragma once
#ifndef CharTree_h
#define CharTree_h

#include <stdio.h>
#include <stdlib.h>


typedef struct __tagNode
{
	char value;
	struct __tagNode* leftChild;
	struct __tagNode* rightChild;
} charNode;

typedef struct __tagTree
{
	charNode* root;
	int count;
} charTree;

// interface
charTree* createCharTree();
void destroyCharTree(charTree* aTree);

void insertCharToTree(charTree* aTree, char aValue);
charNode* findNodeWithValue(charTree* aTree, char aValue);
void deleteNodeWithValue(charTree* aTree, char aValue);

void printTree(charTree* aTree);

#endif /* tree_h */
