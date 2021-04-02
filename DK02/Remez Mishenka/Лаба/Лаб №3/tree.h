#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define tree_h
#ifdef tree_h

typedef struct t_item tree_item;

struct t_item
{
	char value;
	tree_item* left;
	tree_item* right;

};

typedef struct
{
	tree_item* source_item;
	int count_item;

}tree;

void include_item_im_tree(tree_item* tree, char value);
void destroy_item(tree_item* item);

tree* make_tree(void);
void delete_tree(tree* char_tree);

tree_item* find_tree_item(tree* tree, char value);
void print_tree(tree* tree);

void delete_item_from_tree(tree* tree, char value);

static tree_item* make_item_for_tree(char value);
static void into_item(tree_item* item);

#endif