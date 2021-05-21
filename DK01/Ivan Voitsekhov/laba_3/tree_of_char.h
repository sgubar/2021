#ifndef TREE_OF_CHAR_H_INCLUDED
#define TREE_OF_CHAR_H_INCLUDED

#include <stdio.h>

typedef struct tagNode
{
	char sumbol;
	struct tagNode *leftChild;
	struct tagNode *rightChild;
} CharNode;

typedef struct tagTree
{
	CharNode *root;

	int count;
} CharTree;


CharTree *createCharTree();
void delateCharTree(CharTree *aTree);

void insertCharSumbolToTree(CharTree *aTree, char aSumbol);
CharNode *findNodeWithSumbol(CharTree *aTree, char aSumbol);
void deleteNodeWithSumbol(CharTree *aTree, char aSumbol);



void printTree(CharTree *aTree);


#endif // TREE_OF_CHAR_H_INCLUDED
