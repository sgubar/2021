#include "tree.h"
#include <stdlib.h>

static void destroyNode(DoubleNode *dNode);
static DoubleNode *createDoubleNodeWithValue(double dValue);
static DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete);
static void print_double_node(DoubleNode *node);

DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(ShortTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyDoubleTree(DoubleTree *dTree)
{
	if (NULL != dTree)
	{
		destroyNode(dTree->root);
		free(dTree);
	}
}

void insertDoubleValueToTree(DoubleTree *dTree, double dValue)
{
	if (NULL == dTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(dValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == dTree->root)
	{
		dTree->root = theNode;
		dTree->count ++;
	}
	else
	{
		DoubleNode *theCurrent = dTree->root;
		DoubleNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (dValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	
		dTree->count ++;
	}
}

DoubleNode *findNodeWithValue(DoubleTree *dTree, double dValue)
{
	DoubleNode *theCurrentNode = NULL;
	
	if (NULL != dTree && NULL != dTree->root)
	{
		DoubleNode *theCurrentNode = dTree->root; //<! - start from root
		while (dValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (dValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	return theCurrentNode;
}

void deleteNodeWithValue(DoubleTree *dTree, double dValue) {

	// check input parameters
	if (NULL == dTree || NULL == dTree->root) {
		return ;
	}

	DoubleNode *current = dTree->root;
	DoubleNode *parent = dTree->root;

	// find node for delete
	while (dValue != current->value) {
		parent = current;
		if (dValue < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (dTree->root == current) {
			dTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		dTree->count --;
	} else if (NULL == current->rightChild) {
		if (dTree->root == current) {
			dTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (dTree->root == current) {
			dTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		DoubleNode *successor = getSuccessor(dTree, current);
		if (dTree->root == successor) {
			dTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

//void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);
//
void printTree(DoubleTree *dTree) {
	DoubleNode* item = dTree->root;
	print_double_node(item);
}

void print_double_node(DoubleNode *node) {
	if (node == NULL)
		return;
	print_double_node(node->leftChild);
	printf("Элемент: %d\n", node->value);
	print_double_node(node->rightChild);
}
//int countNodesWithTree(ShortTree *aTree);

#pragma mark -
void destroyNode(DoubleNode *dNode)
{
	if (NULL != dNode)
	{
		destroyNode(dNode->leftChild);
		destroyNode(dNode->rightChild);
	
		free(dNode);
	}
}

DoubleNode *createDoubleNodeWithValue(double dValue)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = dValue;
	}
	
	return theNode;
}

DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete) {
	DoubleNode *successParent = toDelete;
	DoubleNode *successor = toDelete;
	DoubleNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}

	if (successor != toDelete->rightChild) {
		successParent->leftChild = successor->rightChild; 
		successor->rightChild = toDelete->rightChild; 
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}
