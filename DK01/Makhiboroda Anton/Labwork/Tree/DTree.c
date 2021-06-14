#include "DTree.h"
#include <stdlib.h>

static void destroyNode(DNode* aNode);
static DNode* createDoubleNodeWithValue(double aValue);
static DNode* getSuccessor(DTree* tree, DNode* toDelete);
static void print_double_node(DNode* node);

DTree* createDTree(void)
{
	DTree* theTree = (DTree*)malloc(sizeof(DTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyDTree(DTree* aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DTree* aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DNode* theNode = createDoubleNodeWithValue(aValue);
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
		DNode* theCurrent = aTree->root;
		DNode* theParent = NULL;

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

DNode* findNodeWithValue(DTree* aTree, double aValue)
{
	DNode* theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root;
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

void deleteNodeWithValue(DTree* aTree, double aValue) {

	if (NULL == aTree || NULL == aTree->root) { // Перевірка вхідних параметрів
		return;
	}

	DNode* current = aTree->root;
	DNode* parent = aTree->root;

	while (aValue != current->value) { // Пошук вузла для видалення
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
	if (NULL == current->leftChild && NULL == current->rightChild) { // Знайдений вузол листовий?
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
	else if (NULL == current->rightChild) { // Знайдений визол має одного лівого нащадка?
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
	else if (NULL == current->leftChild) { // Знайдений визол має одного правого нащадка?
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
	else { // Знайдений визол має двох нащадків?
		DNode* successor = getSuccessor(aTree, current);
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

void printTree(DTree* aTree) {
	printf("Beginning\n");
	DNode* item = aTree->root;
	print_double_node(item);
	printf("End\n");
}

void print_double_node(DNode* node) {
	if (node == NULL)
		return;
	printf("Element: %f\n", node->value);
	print_double_node(node->leftChild);
	print_double_node(node->rightChild);
}

void destroyNode(DNode* aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

DNode* createDoubleNodeWithValue(double aValue)
{
	DNode* theNode = (DNode*)malloc(sizeof(DNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

DNode* getSuccessor(DTree* tree, DNode* toDelete) {
	DNode* successParent = toDelete;
	DNode* successor = toDelete;
	DNode* current = toDelete->rightChild;

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
