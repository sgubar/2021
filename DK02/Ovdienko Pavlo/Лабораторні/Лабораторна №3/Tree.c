#include "tree.h"

static void destroyNode(DoubleNode* Node);
static DoubleNode* createDoubleNodeWithValue(double DDDdouble);
static DoubleNode* getSuccessor(DoubleTree* tree, DoubleNode* toDelete);
static void printDoubleNode(DoubleNode* Node);

DoubleTree* createDoubleTree() {
	DoubleTree* tree = (DoubleTree*)malloc(sizeof(DoubleTree));

	if (NULL != tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}

	return tree;
}

void destroyDoubleTree(DoubleTree* tree) {
	if (NULL != tree)
	{
		destroyNode(tree->root);
		free(tree);
	}
}

void insertDoubleValueToTree(DoubleTree* tree, double DDDdouble)
{
	if (NULL == tree)
	{
		return;
	}

	DoubleNode* theNode = createDoubleNodeWithValue(DDDdouble);
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
		DoubleNode* theCurrent = tree->root;
		DoubleNode* theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (DDDdouble < theCurrent->value)
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

DoubleNode* findNodeWithValue(DoubleTree* tree, double DDDdouble)
{
	DoubleNode* theCurrentNode = NULL;

	if (NULL != tree && NULL != tree->root)
	{
		theCurrentNode = tree->root;
		while (DDDdouble != theCurrentNode->value)
		{
			theCurrentNode = (DDDdouble < theCurrentNode->value)
				? theCurrentNode->leftChild
				: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	if (theCurrentNode == NULL) {
		printf("There is no element in this tree.\n");
	}
	else {
		return printf("%f\n", theCurrentNode->value);
	}
}

void deleteNodeWithTree(DoubleTree* tree, double DDDdouble) {

	if (NULL == tree || NULL == tree->root) {
		return;
	}

	DoubleNode* current = tree->root;
	DoubleNode* parent = tree->root;

	while (DDDdouble != current->value) {
		parent = current;
		if (DDDdouble < current->value) {
			current = current->leftChild;
		}
		else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return;
		}
	}

	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (tree->root == current) {
			tree->root = NULL;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		}
		else {
			parent->rightChild = NULL;
		}

		tree->count--;
	}
	else if (NULL == current->rightChild) {
		if (tree->root == current) {
			tree->root = current->leftChild;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		}
		else {
			parent->rightChild = current->rightChild;
		}
	}
	else if (NULL == current->leftChild) {
		if (tree->root == current) {
			tree->root = current->rightChild;
		}
		else if (parent->rightChild == current) {
			parent->rightChild = current->rightChild;
		}
		else {
			parent->leftChild = current->leftChild;
		}
	}
	else {
		DoubleNode* successor = getSuccessor(tree, current);
		if (tree->root == successor) {
			tree->root = NULL;
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

void printTree(DoubleTree* tree) {
	DoubleNode* Node = tree->root;
	printf("[");
		printDoubleNode(Node);
	printf("]\n");
}

//Functions for NODES

DoubleNode* createDoubleNodeWithValue(double DDDdouble)
{
	DoubleNode* theNode = (DoubleNode*)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = DDDdouble;
	}

	return theNode;
}

void destroyNode(DoubleNode* Node)
{
	if (NULL != Node)
	{
		destroyNode(Node->leftChild);
		destroyNode(Node->rightChild);

		free(Node);
	}
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

static void printDoubleNode(DoubleNode* Node) {
	if (Node == NULL)
		return;
	printDoubleNode(Node->leftChild);
	printDoubleNode(Node->rightChild);
	printf(" %f ", Node->value);
}