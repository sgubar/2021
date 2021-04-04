#include "doubleTree.h"
#include <stdlib.h>

static void destroyNode(DoubleNode* aNode);
static DoubleNode* createDoubleNodeWithValue(double aValue);
static DoubleNode* getSuccessor(DoubleTree* tree, DoubleNode* toDelete);
static void print_double_node(DoubleNode* node);

DoubleTree* createDoubleTree(void)
{
	DoubleTree* theTree = (DoubleTree*)malloc(sizeof(DoubleTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyDoubleTree(DoubleTree* aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree* aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode* theNode = createDoubleNodeWithValue(aValue);
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
		DoubleNode* theCurrent = aTree->root;
		DoubleNode* theParent = NULL;

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

DoubleNode* findNodeWithValue(DoubleTree* aTree, double aValue)
{
	DoubleNode* theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		DoubleNode* theCurrentNode = aTree->root; 
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

void deleteNodeWithValue(DoubleTree* aTree, double aValue) {

	// Перевірка вхідних параметрів
	if (NULL == aTree || NULL == aTree->root) {
		return;
	}

	DoubleNode* current = aTree->root;
	DoubleNode* parent = aTree->root;

	// Пошук вузла для видалення
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

	//1) Знайдений вузол листовий?
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
	//2) Знайдений визол має одного нащадка?
	//а) Знайдений визол має одного лівого нащадка?
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
	//б) Знайдений визол має одного правого нащадка?
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
	//3) Знайдений визол має двох нащадків?
	else {
		DoubleNode* successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = successor;
		}
		else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

void printTree(DoubleTree* aTree) {
	printf("Beginning\n");
	DoubleNode* item = aTree->root;
	print_double_node(item);
	printf("End\n");
}

void print_double_node(DoubleNode* node) {
	if (node == NULL)
		return;
	printf("Element: %f\n", node->value);
	print_double_node(node->leftChild);
	print_double_node(node->rightChild);
}

void destroyNode(DoubleNode* aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

DoubleNode* createDoubleNodeWithValue(double aValue)
{
	DoubleNode* theNode = (DoubleNode*)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

DoubleNode* getSuccessor(DoubleTree* tree, DoubleNode* toDelete) {
	DoubleNode* successParent = toDelete;
	DoubleNode* successor = toDelete;
	DoubleNode* current = toDelete->rightChild;

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
