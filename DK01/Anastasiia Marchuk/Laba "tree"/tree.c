#include "tree.h"
#include <stdlib.h>

static void delateNode(DoubleNode *aNode);
static DoubleNode *createDoubleNodeWithSumbol(double aSumbol);
static DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete);
static void print_double_node(DoubleNode *node);

DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void delateDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		delateNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleSumbolToTree(DoubleTree *aTree, double aSumbol)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithSumbol(aSumbol);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (aSumbol < theCurrent->sumbol)
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

		aTree->count ++;
	}
}

DoubleNode *findNodeWithSumbol(DoubleTree *aTree, double aSumbol)
{
	DoubleNode *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		DoubleNode *theCurrentNode = aTree->root;
		while (aSumbol != theCurrentNode->sumbol)
		{
			theCurrentNode = (aSumbol < theCurrentNode->sumbol)
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

void deleteNodeWithSumbol(DoubleTree *aTree, double aSumbol) {


	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	DoubleNode *current = aTree->root;
	DoubleNode *parent = aTree->root;


	while (aSumbol!= current->sumbol) {
		parent = current;
		if (aSumbol < current->sumbol) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}


	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		aTree->count --;
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		DoubleNode *successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	delateNode(current);
}


void printTree(DoubleTree *aTree) {
	DoubleNode* item = aTree->root;
	print_double_node(item);
}

void print_double_node(DoubleNode *node) {
	if (node == NULL)
		return;
    printf("Element: %.0f \n", node->sumbol);
	print_double_node(node->leftChild);
	print_double_node(node->rightChild);

}



void delateNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		delateNode(aNode->leftChild);
		delateNode(aNode->rightChild);

		free(aNode);
	}
}

DoubleNode *createDoubleNodeWithSumbol(double aSumbol)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->sumbol = aSumbol;
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
