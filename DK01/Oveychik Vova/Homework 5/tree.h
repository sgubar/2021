 #ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

 #include <stdio.h>

typedef struct tagNode
{
	double value;
	struct tagNode *leftChild;
	struct tagNode *rightChild;
} DoubleNode;

typedef struct tagTree
{
	DoubleNode *root;

	int count;
} DoubleTree;

// interface
DoubleTree *createDoubleTree();
void delateDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);
DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

//void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);

void printTree(DoubleTree *aTree);
//int countNodesWithTree(ShortTree *aTree);


#endif // TREE_H_INCLUDED
