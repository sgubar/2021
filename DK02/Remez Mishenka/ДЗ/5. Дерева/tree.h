#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define tree_h
#ifdef tree_h

typedef struct t_item tree_item;

struct t_item
{
	float value;
	tree_item* left;
	tree_item* right;

};

typedef struct
{
	tree_item* source_item;
	int count_item;

}tree;

void include_item_im_tree(tree_item* tree, float value);
void destroy_item(tree_item* item);

tree* make_tree(void);
void delete_tree(tree* float_tree);

tree_item* find_tree_item(tree* tree, float value);
void print_tree(tree* tree);

void delete_item_from_tree(tree* tree, float value);

static tree_item* make_item_for_tree(float value);
static void into_item(tree_item* item);

static tree_item* getSuccessor(tree* tree, tree_item* toDelete);

static tree_item* last_left(tree_item* item);
static tree_item* last_right(tree_item* item);

#endif