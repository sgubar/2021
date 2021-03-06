#ifndef BTREE
#define BTREE

#include <stdio.h>

typedef struct CharNode {
    char value;
    struct CharNode* left;
    struct CharNode* right;
} T_Node;

typedef struct CharTree {
    T_Node* root;
    unsigned int count;
} T_Tree;

typedef enum PrintOrder {
    e_Preorder = 0,
    e_Symmetric,
    e_Postorder
} E_PrintOrder;

T_Tree* CreateTree();
void DestroyTree(T_Tree* tree_);
void PrintTree(T_Tree* tree_, E_PrintOrder printOrder_);
T_Node* InsertNode(T_Tree* tree_, char value);
void DeleteNode(T_Tree* tree_, char value_);
T_Node* FindNode(T_Tree* tree_, char value_);

#endif