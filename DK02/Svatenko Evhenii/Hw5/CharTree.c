#include "CharTree.h"

static void destroyNode(charNode* aNode);
static charNode* createCharNodeWithValue(double aValue);
static charNode* getSuccessor(Tree* tree, charNode* toDelete);
static void printCharNode(charNode* node);

Tree* createCharTree()
{
	Tree* theTree = (Tree*)malloc(sizeof(Tree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyCharTree(Tree* aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertCharToTree(Tree* aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	charNode* theNode = createCharNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		charNode* theCurrent = aTree->root;
		charNode* theParent = NULL;

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

		aTree->count++;
	}
}

charNode* findNodeWithValue(Tree* aTree, double aValue)
{
	charNode* theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		charNode* theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
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

void deleteNodeWithValue(Tree* aTree, double aValue) {

	// check input parameters
	if (NULL == aTree || NULL == aTree->root) {
		return;
	}

	charNode* current = aTree->root;
	charNode* parent = aTree->root;

	// find node for delete
	while (aValue != current->value) {
		parent = current;
		if (aValue < current->value) {
			current = current->leftChild;
		}
		else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		}
		else {
			parent->rightChild = NULL;
		}

		aTree->count--;
	}
	else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		}
		else {
			parent->rightChild = current->rightChild;
		}
	}
	else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		}
		else if (parent->rightChild == current) {
			parent->rightChild = current->rightChild;
		}
		else {
			parent->leftChild = current->leftChild;
		}
	}
	else {
		charNode* successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = successor;
		}
		else if (parent->rightChild == current) {
			parent->rightChild = successor;
		}
		else {
			aTree->root = successor;
			current->leftChild = NULL;
			current->rightChild = NULL;
		}
	}

	free(current);
}

void printTree(Tree* aTree) {
	charNode* item = aTree->root;
	printCharNode(item);
}

void printCharNode(charNode* node) {
	if (node == NULL)
		return;

	printf("Element: %.1f\n", node->value);
	printCharNode(node->leftChild);
	printCharNode(node->rightChild);
}

void destroyNode(charNode* aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

charNode* createCharNodeWithValue(double aValue)
{
	charNode* theNode = (charNode*)malloc(sizeof(charNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

charNode* getSuccessor(Tree* tree, charNode* toDelete) {
	charNode* successParent = toDelete;
	charNode* successor = toDelete;
	charNode* current = toDelete->rightChild;

	while (NULL != current) {
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
