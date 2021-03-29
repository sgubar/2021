#include "tree.h"


void include_item_im_tree(tree* tree, char value)
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
	while(1)
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

void delete_item_from_tree(tree* tree, char value)
{
	if (tree == NULL || tree->source_item == NULL)
		return;
	tree_item* current = tree->source_item;
	tree_item* parent = tree->source_item;

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

		tree_item* sparent = current;
		tree_item* successor = current;
		tree_item* scurrent = current->right;
		while (NULL != current) {
			sparent = successor;
			successor = scurrent;
			scurrent = scurrent->left;
		}

		if (successor != current->right) {
			sparent->left = successor->right;
			successor->right = current->right;
		}


		if (tree->source_item == successor) {
			tree->source_item = NULL;
		}
		else if (parent->left == current) {
			parent->left = successor;
		}
		else {
			parent->right = successor;
		}
	}
	destroy_item(current);
	return;
}

tree_item* find_tree_item(tree* tree, char value)
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
		item = NULL;
		free(item);
	}
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

void delete_tree(tree* char_tree)
{
	if (char_tree != NULL)
	{
		destroy_item(char_tree->source_item);
		free(char_tree);
	}
}

static tree_item* make_item_for_tree(char value)
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
	printf("Ёлемент: %c\n", item->value);
	into_item(item->right);
}