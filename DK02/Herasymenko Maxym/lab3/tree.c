#include "tree.h"
#include <stdio.h>
static void destroyNode(IntNode* Node);
static IntNode *createIntNode(int aValue);
static IntNode *getSuccessor(IntTree *tree, IntNode *toDelete);
static void printIntNode(IntNode *Node);

IntTree *createIntTree()
{
	IntTree *tree = (IntTree*)malloc(sizeof(IntTree));

	if (NULL != tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}

	return tree;
}

void destroyIntTree(IntTree* tree)
{
	if (NULL != tree)
	{
		destroyNode(tree->root);
		free(tree);
	}
}

void insertIntValueToTree(IntTree* tree, int aValue)
{
	if (NULL == tree)
	{
		return;
	}

	IntNode* theNode = createIntNode(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == tree->root)
	{
		tree->root = theNode;
		tree->count++;
	}
	else
	{
		IntNode *theCurrent = tree->root;
		IntNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
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

		tree->count++;
	}
}

IntNode *findNode(IntTree* tree, int aValue)
{
	IntNode *theCurrentNode = NULL;

	if (NULL != tree && NULL != tree->root)
	{
		IntNode *theCurrentNode = tree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
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

void deleteNodeWithValue(IntTree* tree, int aValue)
{

	if (NULL == tree || NULL == tree->root)
    {
		return;
	}

	IntNode *current = tree->root;
	IntNode *parent = tree->root;

	while (aValue != current->value)
    {
		parent = current;
		if (aValue < current->value)
		{
			current = current->leftChild;
		}
		else
		{
			current = current->rightChild;
		}

		if (NULL == current)
        {
			return;
		}
	}

	if (NULL == current->leftChild && NULL == current->rightChild)
        {
		if (tree->root == current)
		{
			tree->root = NULL;
		}
		else if (parent->leftChild == current)
		{
			parent->leftChild = NULL;
		}
		else
		{
			parent->rightChild = NULL;
		}

		tree->count--;
	}
	else if (NULL == current->rightChild)
        {
		if (tree->root == current)
		{
			tree->root = current->leftChild;
		}
		else if (parent->leftChild == current)
		{
			parent->leftChild = current->leftChild;
		}
		else
		{
			parent->rightChild = current->rightChild;
		}
	}
	else if (NULL == current->leftChild)
	{
		if (tree->root == current)
		{
			tree->root = current->rightChild;
		}
		else if (parent->rightChild == current)
		{
			parent->rightChild = current->rightChild;
		}
		else
		{
			parent->leftChild = current->leftChild;
		}
	}
	else
	{
		IntNode* successor = getSuccessor(tree, current);
		if (tree->root == successor)
		{
			tree->root = NULL;
		}
		else if (parent->leftChild == current)
		{
			parent->leftChild = successor;
		}
		else
		{
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

void printIntTree(IntTree *tree)
{
	IntNode* Node = tree->root;
	printf("tree: ");
    printIntNode(Node);
    printf("\n");
}
static void printIntNode(IntNode *Node)
{
	if (Node == NULL)
    {
        return;
    }
	printIntNode(Node->leftChild);
	printIntNode(Node->rightChild);
	printf(" %d ", Node->value);
}



IntNode *createIntNode(int aValue)
{
	IntNode *theNode = (IntNode*)malloc(sizeof(IntNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void destroyNode(IntNode *Node)
{
	if (NULL != Node)
	{
		destroyNode(Node->leftChild);
		destroyNode(Node->rightChild);

		free(Node);
	}
}

IntNode* getSuccessor(IntTree *tree, IntNode *toDelete)
{
	IntNode *successParent = toDelete;
	IntNode *successor = toDelete;
	IntNode *current = toDelete->rightChild;

	while (NULL != current)
    {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}

	if (successor != toDelete->rightChild)
    {
		successParent->leftChild = successor->rightChild;
		successor->rightChild = toDelete->rightChild;
	}

	successor->leftChild = toDelete->leftChild;
	return successor;
}
