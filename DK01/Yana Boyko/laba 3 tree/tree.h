#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree
{
    Node* root;
    int count;
} BinaryTree;

// interface
BinaryTree* createTree();
void destroyTree(BinaryTree* aTree);

void insert(BinaryTree* aTree, int aValue);
Node* find(BinaryTree* aTree, int aValue);
void delete(BinaryTree* aTree, int aValue);

void mergeTrees(BinaryTree* aTreeDst, BinaryTree* aTreeSrc);

void print(BinaryTree* aTree);

#endif /* tree_h */
