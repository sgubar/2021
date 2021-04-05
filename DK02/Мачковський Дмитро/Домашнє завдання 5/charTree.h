#ifndef charTree_h
#define charTree_h

#include <stdio.h>

typedef struct tagNode
{
	char value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
} CharNode;

typedef struct tagTree
{
	CharNode* root;
	int count;
} CharTree;

CharTree* createCharTree();
void destroyCharTree(CharTree* aTree);
void insertCharValueToTree(CharTree* aTree, char aValue);
CharNode* findNodeWithValue(CharTree* aTree, char aValue);
void deleteNodeWithValue(CharTree* aTree, char aValue);
void printTree(CharTree* aTree);


#endif
