#include "tree_of_char.h"
#include <stdlib.h>

static void delateNode(CharNode *aNode);
static CharNode *createCharNodeWithSumbol(char aSumbol);
static CharNode *getSuccessor(CharTree *tree, CharNode *toDelete);
static void print_char_node(CharNode *node);

CharTree *createCharTree()
{
	CharTree *theTree = (CharTree *)malloc(sizeof(CharTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void delateCharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		delateNode(aTree->root);
		free(aTree);
	}
}

void insertCharSumbolToTree(CharTree *aTree, char aSumbol)
{
	if (NULL == aTree)
	{
		return;
	}

	CharNode *theNode = createCharNodeWithSumbol(aSumbol);
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
		CharNode *theCurrent = aTree->root;
		CharNode *theParent = NULL;

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

CharNode *findNodeWithSumbol(CharTree *aTree, char aSumbol)
{
	CharNode *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		CharNode *theCurrentNode = aTree->root;
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

void deleteNodeWithSumbol(CharTree *aTree, char aSumbol) {


	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	CharNode *current = aTree->root;
	CharNode *parent = aTree->root;


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
		CharNode *successor = getSuccessor(aTree, current);
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


void printTree(CharTree *aTree) {
	CharNode* item = aTree->root;
	print_char_node(item);
}

void print_char_node(CharNode *node) {
	if (node == NULL)
		return;
    printf("element: %c\n", node->sumbol);
	print_char_node(node->leftChild);
	print_char_node(node->rightChild);

}



void delateNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		delateNode(aNode->leftChild);
		delateNode(aNode->rightChild);

		free(aNode);
	}
}

CharNode *createCharNodeWithSumbol(char aSumbol)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->sumbol = aSumbol;
	}

	return theNode;
}

CharNode *getSuccessor(CharTree *tree, CharNode *toDelete) {
	CharNode *successParent = toDelete;
	CharNode *successor = toDelete;
	CharNode *current = toDelete->rightChild;

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
