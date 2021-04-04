#include "tree.h"


void include_item_im_tree(tree* tree, float value)
{
	if (tree == NULL)
		return;
	tree_item* item = make_item_for_tree(value);
	if (item == NULL)
		return;
	if (tree->source_item == NULL)
	{
		tree->source_item = item;
		tree->count_item = 1;
	}
	else
	{
		tree_item* Current_item = tree->source_item;
		tree_item* Parent_item = NULL;
		while (1)
		{
			Parent_item = Current_item;
			if (item->value < Current_item->value)
			{
				Current_item = Current_item->left;
				if (Current_item == NULL)
				{
					Parent_item->left = item;
					break;
				}
			}
			else
			{
				Current_item = Current_item->right;
				if (Current_item == NULL)
				{
					Parent_item->right = item;
					break;
				}
			}
		}
		tree->count_item++;
	}
	return;
}

void delete_item_from_tree(tree* tree, float value)
{
	// check input parameters
	if (NULL == tree || NULL == tree->source_item) {
		return;
	}

	tree_item* current = tree->source_item;
	tree_item* parent = tree->source_item;

	// find node for delete
	while (value != current->value) {
		parent = current;
		if (value < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}

		if (NULL == current) {
			return;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->left && NULL == current->right) {
		if (tree->source_item == current) {
			tree->source_item = NULL;
		}
		else if (parent->left == current) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}

		tree->count_item--;
	}
	else if (NULL == current->right) {
		if (tree->source_item == current) {
			tree->source_item = current->left;
		}
		else if (parent->left == current) {
			parent->left = current->left;
		}
		else {
			parent->right = current->right;
		}
	}
	else if (NULL == current->left) {
		if (tree->source_item == current) {
			tree->source_item = current->right;
		}
		else if (parent->right == current) {
			parent->right = current->right;
		}
		else {
			parent->left = current->left;
		}
	}
	else {
		tree_item* successor = getSuccessor(tree, current);
		if (tree->source_item == successor) {
			tree->source_item = NULL;
		}
		else if (parent->left == current) {
			parent->left = successor;
		}
		else {
			parent->right = successor;
		}
		current->left = NULL;
		current->right = NULL;
	}

	destroy_item(current);
}



tree_item* find_tree_item(tree* tree, float value)
{
	tree_item* item = NULL;

	if (tree != NULL && tree->source_item != NULL)
	{
		item = tree->source_item;
		while (value != item->value)
		{	
			item = (value < item->value) ? item->left : item->right;
			if (NULL == item)
			{
				break;
			}
		}
	}
	return item;
}

void destroy_item(tree_item* item)
{
	if (item != NULL)
	{
		destroy_item(item->left);
		destroy_item(item->right);
		free(item);
	}	
}

static tree_item* getSuccessor(tree* tree, tree_item* toDelete) 
{
	tree_item* successParent = toDelete;
	tree_item* successor = toDelete;
	tree_item* current = toDelete->right;

	while (NULL != current) {
		successParent = successor;
		successor = current;
		current = current->left;
	}
	//current = NULL;
	//successor = 35
	if (successor != toDelete->right) { // 35 != 39
		successParent->left = successor->right; //39 -> NULL
		successor->right = toDelete->right; //35->39
	}

	successor->left = toDelete->left;

	return successor;
}

tree* make_tree(void)
{
	tree* derevo = (tree*)malloc(sizeof(tree));
	if (derevo == NULL)
		return derevo;
	derevo->source_item = NULL;
	derevo->count_item = 0;
	return derevo;
}

void delete_tree(tree* float_tree)
{
	if (float_tree != NULL)
	{
		destroy_item(float_tree->source_item);
		free(float_tree);
	}
}

static tree_item* make_item_for_tree(float value)
{
	tree_item* item = (tree_item*)malloc(sizeof(tree_item));
	item->left = NULL;
	item->right = NULL;
	item->value = value;
	return item;
}


void print_tree(tree* tree)
{
	tree_item* item = tree->source_item;
	into_item(item);
}

static void into_item(tree_item* item)
{
	if (item == NULL)
		return;
	into_item(item->left);
	printf("Ёлемент: %.2f\n", item->value);
	into_item(item->right);
}

static tree_item* last_left(tree_item* item)
{
	if (item == NULL)
		return;
	if (item->left != NULL)
		last_left(item->left);
	return item;
}

static tree_item* last_right(tree_item* item)
{
	if (item == NULL)
		return;
	if (item->right != NULL)
		last_left(item->right);
	return item;
}