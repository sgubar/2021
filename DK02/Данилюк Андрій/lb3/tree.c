#include "tree.h"

static void destroyNode(Node* node);
static Node* createNodeWithValue(float value);
static Node* getSuccessor(Tree* tree, Node* toDelete);
static void printNode(Node* node);

Tree* createTree(void)
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));

	if (NULL != tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}
	return tree;
}
void destroyTree(Tree* tree)
{
	if (NULL != tree)
	{
		destroyNode(tree->root);
		free(tree);
	}
}
void insertValueToTree(Tree* tree, float value)
{
	if (NULL == tree)
	{
		return;
	}

	Node* node = createNodeWithValue(value);
	if (NULL == node)
	{
		return;
	}

	if (NULL == tree->root)
	{
		tree->root = node;
		tree->count++;
	}
	else
	{
		Node* current = tree->root;
		Node* parent = NULL;

		while (1)
		{
			parent = current;

			if (value < current->value)
			{
				current = current->Left;
				if (NULL == current)
				{
					parent->Left = node;
					break;
				}
			}
			else
			{
				current = current->Right;
				if (NULL == current)
				{
					parent->Right = node;
					break;
				}
			}
		}

		tree->count++;
	}
}
Node* findNodeWithValue(Tree* tree, float value)
{
	Node* currentNode = NULL;

	if (NULL != tree && NULL != tree->root)
	{
		currentNode = tree->root;
		while (value != currentNode->value)
		{
			currentNode = (value < currentNode->value)
				? currentNode->Left
				: currentNode->Right;

			if (NULL == currentNode)
			{
				break;
			}
		}
	}

	return currentNode;
}
void deleteNodeWithValue(Tree* tree, float value)
{
	if (NULL == tree || NULL == tree->root)
	{
		return;
	}

	Node* current = tree->root;
	Node* parent = tree->root;

	while (value != current->value)
	{
		parent = current;
		if (value < current->value)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
		if (NULL == current)
		{
			return;
		}
	}

	if (NULL == current->Left && NULL == current->Right)
	{
		if (tree->root == current)
		{
			tree->root = NULL;
		}
		else if (parent->Left == current)
		{
			parent->Left = NULL;
		}
		else
		{
			parent->Right = NULL;
		}

		tree->count--;
	}
	else if (NULL == current->Right)
	{
		if (tree->root == current)
		{
			tree->root = current->Left;
		}
		else if (parent->Left == current)
		{
			parent->Left = current->Left;
		}
		else
		{
			parent->Right = current->Right;
		}

		tree->count--;
	}
	else if (NULL == current->Left)
	{
		if (tree->root == current)
		{
			tree->root = current->Right;
		}
		else if (parent->Right == current)
		{
			parent->Right = current->Right;
		}
		else
		{
			parent->Left = current->Left;
		}

		tree->count--;
	}
	else
	{
		Node* successor = getSuccessor(tree, current);
		if (tree->root == successor)
		{
			tree->root = NULL;
		}
		else if (parent->Left == current)
		{
			parent->Left = successor;
		}
		else if(parent->Right == current)
		{
			parent->Right = successor;
		}
		else
		{
			tree->root = successor;
			current->Left = NULL;
			current->Right = NULL;
			tree->count--;
		}
	}
	destroyNode(current);
}
void printTree(Tree* tree)
{
	Node* item = tree->root;
	printNode(item);
}

static void destroyNode(Node* node)
{
	if (NULL != node)
	{
		destroyNode(node->Left);
		destroyNode(node->Right);
		free(node);
	}
}
static Node* createNodeWithValue(float value)
{
	{
		Node* theNode = (Node*)malloc(sizeof(Node));

		if (NULL != theNode)
		{
			theNode->Left = NULL;
			theNode->Right = NULL;
			theNode->value = value;
		}

		return theNode;
	}
}
static Node* getSuccessor(Tree* tree, Node* toDelete)
{
	Node* successParent = toDelete;
	Node* successor = toDelete;
	Node* current = toDelete->Right;

	while (NULL != current)
	{
		successParent = successor;
		successor = current;
		current = current->Left;
	}

	if (successor != toDelete->Right)
	{
		successParent->Left = successor->Right;
		successor->Right = toDelete->Right;
	}

	successor->Left = toDelete->Left;

	return successor;
}
static void printNode(Node* node)
{
	{
		if (node == NULL)
			return;

		printNode(node->Left);
		printf("Your element is: %.2f\n", node->value);
		printNode(node->Right);
	}
}
