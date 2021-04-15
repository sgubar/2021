#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tagNode
{
	double sumbol;
	struct tagNode *leftChild;
	struct tagNode *rightChild;
} DoubleNode;

typedef struct tagTree
{
	DoubleNode *root;

	int count;
} DoubleTree;


DoubleTree *createDoubleTree();
void delateDoubleTree(DoubleTree *aTree);

void insertDoubleSumbolToTree(DoubleTree *aTree, double aSumbol);
DoubleNode *findNodeWithSumbol(DoubleTree *aTree, double aSumbol);
void deleteNodeWithSumbol(DoubleTree *aTree, double aSumbol);



void printTree(DoubleTree *aTree);


#endif
